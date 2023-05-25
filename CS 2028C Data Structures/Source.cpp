#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstddef>

/* Define max items and remove items and change for testing purposes.
 * Test 1: max = 30, remove = 25
 * Test 2: max = 50, remove = 25
 * Test 3: max = 10, remove = 5
*/
#define maxItems 10
#define removeItems 5

using namespace std;

// Ordered list class using a template.
template <class X>
class OrderedList {
protected:
    // Array of pointers holding max items of type X.
    X* array[maxItems] = {};
    // Comparison and move counters.
    int compareAdd = 0;
    int moveAdd = 0;
    int compareRemove = 0;
    int moveRemove = 0;

public:
    // Create array of null pointers.
    OrderedList() {
        for (int i = 0; i < maxItems; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function that starts at front of array.
    void addItem(X item) {
        X temp = item;
        X temp2;
        // For loop to look at each item in array.
        for (int i = 0; i < maxItems; ++i) {
            // If-else statements to move and add in item as needed.
            if (array[i] == NULL) {
                array[i] = new X; // Create new item.
                *array[i] = temp;
                break;
            }
            else if (*array[i] > item) {
                ++compareAdd; // Compare array and item so add to comparison.
                temp2 = *array[i];
                *array[i] = temp;
                temp = temp2;
                ++moveAdd; // Move array items so add to move.
            }
            else {
                continue;
            }
        }
    }

    // Remove item function that keeps items in order and removes empty spots.
    void removeItem() {
        int i = 0;
        // Use rand function to find index of item to be removed.
        int index = rand() % maxItems;
        // If position is null, find new index until number is found
        while (array[index] == NULL) {
            index = rand() % maxItems;
        }
        // While loop add to i to continue moving through array.
        while ((i < maxItems) && (index > i) && (array[i] != NULL)) {
            ++i;
        }

        // If statement to remove item at given index.
        if (i == index) {
            compareRemove +=1; // i compared to index so add to comparison.
            // While loop to move items to remove empty spaces.
            while ((array[i + 1] != NULL) && (i + 1 < maxItems)) {
                if (array[i] != NULL)
                {
                    *array[i] = *array[i + 1];
                    ++moveRemove; // Array items moved so add to move.
                }
                ++i;
            }
            // Delete array item.
            delete array[i];
            array[i] = NULL;
        }
    }

    // Display function to display the final array.
    void display() {
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    // Display comparison and move for the add item function.
    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compareAdd << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << moveAdd << endl;
    }

    // Display comparison and move for the remove item function.
    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compareRemove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << moveRemove << endl;
    }

    // Is Empty boolean function that checks to see if the array is empty.
    bool isEmpty() {
        int empty_count = 0;
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] == NULL) {
                ++empty_count;
            }
        }
        if (empty_count == maxItems) {
            return true;
        }
        else {
            return false;
        }
    }

    // Is Full boolean function checks to see if array is full.
    bool isFull() {
        int fullCount = 0;
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) {
                ++fullCount;
            }
        }
        if (fullCount == maxItems) {
            return true;
        }
        else {
            return false;
        }
    }

    // Make empty function deletes items in array and points to null.
    void makeEmpty() {
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) {
                delete array[i];
                array[i] = NULL;
            }
        }
    }

};

// Derived class to investigate adding from the ending (task 2) using template.
template <class Y>
class InvestigateEnding : public OrderedList<class X> {
protected:
    Y* array[maxItems] = { };
    int compareAdd = 0;
    int moveAdd = 0;
    int compareRemove = 0;
    int moveRemove = 0;

public:
    // Create array of null pointers.
    InvestigateEnding() {
        for (int i = 0; i < maxItems; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function starts from end of array to insert new item.
    void addItem(Y item) {
        Y temp = item;
        Y temp2;
        // For loop starts from end of array.
        for (int i = maxItems - 1; i >= 0; --i) {
            if (array[i] == NULL) {
                // Creates new item if position is null.
                array[i] = new Y;
                *array[i] = temp;
                break;
            }
            else if (*array[i] < item) {
                ++compareAdd; // Compare item to array position so add to compare.
                temp2 = *array[i];
                *array[i] = temp;
                temp = temp2;
                ++moveAdd; // Move array items so add to move.
            }
            else {
                continue;
            }
        }
    }

    // Remove item function. Same as task 1
    void removeItem() {
        int i = 0;
        int index = rand() % maxItems;
        while (array[index] == NULL) {
            index = rand() % maxItems;
        }
        while ((i < maxItems) && (index > i) && (array[i] != NULL)) {
            ++i;
        }

        if (i == index) {
            ++compareRemove;
            while ((array[i + 1] != NULL) && (i + 1 < maxItems)) {
                *array[i] = *array[i + 1];
                ++moveRemove;
                ++i;
            }
            delete array[i];
            array[i] = NULL;
        }
    }

    // 3 Display functions same as task 1.
    void display() {
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compareAdd << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << moveAdd << endl;
    }

    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compareRemove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << moveRemove << endl;
    }
};

// Derived class investigate leaving blank spots (task 3).
template <class Z>
class InvestigateBlank : public OrderedList<class X> {
protected:
    Z* array[maxItems] = {};
    int compareAdd = 0;
    int moveAdd = 0;
    int compareRemove = 0;
    int moveRemove = 0;

public:
    // Create array of null pointers.
    InvestigateBlank() {
        for (int i = 0; i < maxItems; ++i) {
            array[i] = NULL;
        }
    }

    // Add item function inserts halfway between.
    void addItem(Z item) {
        // If array is empty, new item at index 0.
        if (isEmpty() == true) {
            array[0] = new Z;
        }

        // If new item at index 0.
        if (array[0] != NULL) {
            ++compareAdd; // Add to comparison.
            if (*array[0] > item) { // If first item is greater than inserted item
                // For loop to find null pointer.
                for (int i = 0; i < maxItems; ++i) {
                    if (array[i] == NULL) { // Empty space.
                        // For loop to move items to the right.
                        for (int j = i; j >= 0; --j) {
                            ++moveAdd; // Add to move.
                            array[j] = array[j - 1];
                        }
                        break;
                    }
                }
                array[0] = new Z;
                return;
            }
        }

        // For loop to find if array element greater than item.
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) { // If array item exists
                ++compareAdd; // Add to comparison.
                if (*array[i] > item) {
                    if (array[i - 1] == NULL) {
                        // If null create new item.
                        array[i - 1] = new Z;
                        *array[i - 1] = item;
                        return;
                    }
                    int last_empty = 0; // Find last null element.
                    for (int j = 0; j < maxItems; ++j) {
                        if (array[j] == NULL) {
                            last_empty = j;
                        }
                    }
                    if (last_empty > i) { // Move items to right til last null space.
                        for (int j = last_empty; j >= i; --j) {
                            ++moveAdd; // Add to move.
                            array[j] = array[j - 1];
                        }
                        array[i] = new Z;
                        *array[i] = item;
                    }
                    else if (last_empty < i) { // Move items to left til null space.
                        for (int j = last_empty; j <= i - 1; ++j) {
                            ++moveAdd; // Add to move.
                            array[j] = array[j + 1];
                        }
                        array[i - 1] = new Z;
                        *array[i - 1] = item;
                    }
                    return;
                }
            }
        }

        if (array[maxItems - 1] == NULL) {
            array[maxItems - 1] = new Z;
            *array[maxItems - 1] = item;
            return;
        }

        // Create empty item at the end of the list.
        int empty_item = 0;
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] == NULL) {
                empty_item = i;
            }
            // Move items to left.
            for (int j = empty_item; j < maxItems - 1; ++j) {
                ++moveAdd; // Add to move.
                array[j] = array[j + 1];
            }
            array[maxItems - 1] = new Z;
            *array[maxItems - 1] = item;
            return;
        }
    }

    // Remove item function that does not move items.
    void removeItem() {
        // Random index to remove random item.
        int index = rand() % maxItems;
        // Find new random index if item is null.
        while (array[index] == NULL) {
            index = rand() % maxItems;
        }
        // For loop to delete items without moving.
        for (int i = 0; i < maxItems; ++i) {
            if (i == index) {
                ++compareRemove; // Add to comparison.
                delete array[index];
                array[index] = NULL;
            }
        }
    }

    // 3 display functions same as task 1 and 2.
    void display() {
        for (int i = 0; i < maxItems; ++i) {
            if (array[i] != NULL) {
                cout << (*array[i]) << " ";
            }
        }
    }

    void displayCompAndMoveAddItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in add item of ordered list: ";
        cout << compareAdd << endl;
        cout << "Number of moves made in add item of ordered list: ";
        cout << moveAdd << endl;
    }

    void displayCompAndMoveRemoveItem() {
        cout << endl << endl;
        cout << "Number of comparisons made in remove item of ordered list: ";
        cout << compareRemove << endl;
        cout << "Number of moves made in remove item of ordered list: ";
        cout << moveRemove << endl;
    }
};

int main() {
    srand(time(0));
    OrderedList<int> originClass;
    InvestigateEnding<int> rev;
    InvestigateBlank<int> blankspace;


    for (int i = 0; i < maxItems; ++i) {
        int addition = rand() % 100;
        originClass.addItem(addition);
        rev.addItem(addition);
        blankspace.addItem(addition);
    }


    for (int i = 0; i < removeItems; ++i) {
        originClass.removeItem();
        rev.removeItem();
        blankspace.removeItem();
    }

    originClass.displayCompAndMoveAddItem();
    originClass.displayCompAndMoveRemoveItem();


    rev.displayCompAndMoveAddItem();
    rev.displayCompAndMoveRemoveItem();


    blankspace.displayCompAndMoveAddItem();
    blankspace.displayCompAndMoveRemoveItem();

}