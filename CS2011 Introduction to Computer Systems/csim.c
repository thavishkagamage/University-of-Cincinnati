// Name = "Thavishka Gamage"
//Email = "gamagetd@mail.uc.edu"

#include "lab4.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

// For the entire cache, one struct can be used.
struct Cache{
    long valid;
    long tag;
    long lru;
};

// To record the hits, misses, and evictions, these are used.
int hitcount = 0;
int misscount = 0;
int evictcount = 0;

// Setup variables, no help flag because the help menu is the default.
// -v: Detailed flag that shows trace information
// -s <s>: Index bits for the number of sets (S = 2s is the number of sets).
// -E <E>: Associativity (number of lines per set)
// -b <b>: Block size is B = 2b, hence the number of block bits
// -t <tracefile>: Name of the replayable valgrind trace
int s, b, E, v, size, B;

/**
 * Make the cache struct initial.
 */
struct Cache **cache = NULL;

// Set up a mask and lru on the counter.
// both are set too long for accuracy.
long mask = 0;
long lruCounter = 0;

void fileTrace(char *fileName);
void print(char* argv);
void initCache();
void cleanCache();
void useCache(unsigned long address);

/**
 *a procedure used to execute the valgrind file's trace.
 * The variable used as the actual filename for the trace is @param fileName.
 */
void fileTrace(char *fileName)
{
    char buf[1024];

    // Open the file by trying.
    FILE *fp = fopen(fileName, "r");

    // Print an error and then retry if the file is empty.
    if (fp == NULL)
    {
        printf("The file cannot be found.\n\n");
        return;
    }

    // Open our file and read a line from the stream now.
    // then keep it in buf
    while (fgets(buf, 1024, fp))
    {
        unsigned long address = 0;
        unsigned size = 0;

        // We now look for the characters L, S, or M.
        // L is a data load.
        // S is a data store
        // M is data modify
        if (buf[1] == 'S' ||
            buf[1] == 'L' ||
            buf[1] == 'M'){

            // Then we understand that the following place is two indices over.
            // Thus, after adding 2, the location and size should be given.
            sscanf(buf + 2, "%lx,%u", &address, &size);

            // We print if the verbose flag is set to 1.
            if (v)
                printf("%c %lx,%u ", buf[1], address, size);
            useCache(address);

            // If it is M, we simply call the useCache function to modify the data.
            if (buf[1] == 'M')
            {
                useCache(address);
            }

            if (v) putchar('\n');
        }
    }
    // Close the file
    fclose(fp);
}

/**
 * The cache is started using this function.
 */
void initCache()
{
    // The cache's memory is first allocated.
    cache = malloc(size * sizeof(*cache));

    // Then, we allocate memory by utilizing calloc to our advantage.
    // while initializing it to 0 for the cache
    for (int i = 0; i < size; i++)
    {
        // The number of lines in each set is our E.
        cache[i] = calloc(E, sizeof(*cache[i]));
    }

    mask = size - 1;
}

void useCache(unsigned long address)
{
    // We return to our preferred bitwise operations.
    // In order to obtain the set, we right-shift the address by b and use the mask.
    long set = (address >> b) &mask;

    // To obtain the tag, we right-shift the address once more by b + s.
    long tag = (address >> (b+s));

    int x = 0;

    // We traverse the cache in a loop.
    while (x < E)
    {
        // We determine whether the valid bit and the tag are both not 0.
        if (cache[set][x].tag == tag && cache[set][x].valid != 0)
        {
            // We raise our hit counter and print hit if the condition is true because we have a hit.
            hitcount++;
            if (v) printf("hit ");

            // The lru is also updated.
            cache[set][x].lru = lruCounter++;
            return;
        }
        else{
            x++;
        }
    }

    // Everything else is a miss if it isn't a hit, which tells us it was a miss.
    misscount++;

    // The variables are initialized.
    // For comparisons, we must initialize the lrum to the lowest memory address.
    long lrum = 0xFFFFFFFF;
    int evictL = 0;

    if (v) printf("miss ");

    int i = 0;
    while (i < E)
    {
        // If the counter exceeds the lru minimum
        if (lrum > cache[set][i].lru)
        {
            evictL = i;
            lrum = cache[set][i].lru;
        }
        i++;
    }

    // In order to increase the hit count and print eviction, we first determine whether the valid bit is set to 1.
    if (cache[set][evictL].valid == 1)
    {
        evictcount++;
        if (v) printf("eviction ");
    }

    // Before we exit the function, we set the remaining cache.
    cache[set][evictL].valid = 1;
    cache[set][evictL].tag = tag;
    cache[set][evictL].lru = lruCounter++;
}

void cleanCache()
{
    free(cache);
}

void print(char * argv)
{
    printf("Usage: %s [-hv] -s <num> -E <num> -b <num> -t <file>\n", argv);
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    exit(0);
}

int main (int argc, char * argv[])
{
    // The variables are initialized.
    char opt = 0;
    char *file = NULL;

    // To manage the command-line arguments, we use getopt.
    while ((opt = getopt(argc, argv, "s:E:b:t:vh")) != -1)
    {
        switch (opt)
        {
            case 's':
                s = atoi(optarg);

                if (s == 0){
                    return 1;
                }
                break;
            case 'E':
                E = atoi(optarg);
                if (E == 0){
                    return 1;
                }
                break;
            case 'b':
                b = atoi(optarg);
                if (b == 0){
                    return 1;
                }
                break;
            case 't':
                file = optarg;
                if (file == 0){
                    return 1;
                }
                break;
            case 'v':
                v = 1;
                break;
            default:
                print(argv[0]);
                return 1;
        }
    }

    // Using bitwise we left shift to update the block size and bit count
    // Set the size of 1 by s, then do the same for B.
    size = 1 << s;
    B = 1 << b;

    // Set the size of 1 by s, then do the same for B.
    initCache();
    fileTrace(file);
    cleanCache();

    printSummary(hitcount, misscount, evictcount);
    return 0;
}