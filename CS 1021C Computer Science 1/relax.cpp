#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/*
 * format_compression_ratio
 *
 * This function will properly format _compression_ratio_ according
 * to the specifications set forth in the lab document.
 *
 * input: a double, _compression_ratio_, that is the compression ratio
 *        to format.
 * output: a std::string that contains _compression_ratio_ properly
 *         formatted according to the specifications set forth in
 *         the lab document.
 */
std::string format_compression_ratio(double compression_ratio) {
    std::stringstream formatted_ss{};
    formatted_ss << std::fixed << std::setprecision(2) << compression_ratio;
    return formatted_ss.str();
}

/*
open_file

opens a file, if possible

input: a file, filename, and an ifstream, file
output: a boolean meaning whether the file could be opened

*/
bool open_file(std::string filename, std::ifstream& file) {
    file.open(filename);

    return file.is_open();
}

/*
* calc_comp_ratio
*
* calculates the compression ratio between two strings
*
* input: two strings, the uncompressed, and the compressed files
* output: the ratio of characters in the uncompressed file to the compressed file
*/
double calc_comp_ratio(std::string uncompressed, std::string compressed) {
    return (static_cast<double>(uncompressed.size()) / compressed.size());
}

/*
get_string

gives a string the value of the compressed file

input: a file, the compressed message, and a string, which will take the value of the file
output: a boolean meaning the value of the file was transferred to the string
*/
bool get_string(std::ifstream& file, std::string& str) {
    if (!file.eof()) {
        getline(file, str);
        return true;
    }
    return false;
}

/*
data_available
*
* This function will determine whether there is more data to be read
* from _file_.
*
* input: a std::ifstream, _file_, about which we will determine whether
* additional data can be read.
* output : a bool : true if there is more data that can be read from _file_;
*false, otherwise.
*/
bool data_available(std::ifstream& file) {
    // std::iscntrl: Returns non-zero if the character is a control character.
    //               Flip this around logically: if the return value is 0
    //               then we know that the next character to be read is *not*
    //               a control character. 
    // EOF != file.peek(): If the next character to be read is not the end-of-file.
    return (EOF != file.peek() && 0 == std::iscntrl(file.peek()));
}

int num;
char ch;

/*
* decompress
*
* takes the input file and processes it with the decompression rules in mind, printing an error if it does not work.
*
* input: a file and a string
* output: outputs a boolean detailing whether the file could be properly processed, and the uncompressed string is altered, though not outputted.
*/
bool decompress(std::ifstream& file, std::string& uncompressed) {
    int num;
    char ch;

    while (data_available(file)) {
        if (!(file >> num)) {
            uncompressed = "Compressed data format error!";
            return false;
        }
        if (!(file >> ch)) {
            uncompressed = "Compressed data format error!";
            return false;
        }
        if (ch == '-') {
            if (!(file >> ch)) {
                uncompressed = "Compressed data format error!";
                return false;
            }
        }
        for (int i = 0; i < num; ++i) {
            uncompressed.push_back(ch);
        }
    }
    return true;
}


int main() {

    std::ifstream input_file;
    std::string compressed;
    std::string uncompressed;
    double ratio = 0;
    std::string ratioString;


    open_file("input.rle", input_file);
    get_string(input_file, compressed);
    input_file.seekg(0, std::ios_base::beg);
    bool success = decompress(input_file, uncompressed);

    std::cout << uncompressed << "\n";
    if (!success) {
        return 0;
    }
    ratio = calc_comp_ratio(uncompressed, compressed);

    ratioString = format_compression_ratio(ratio);

    std::cout << ratioString << "\n";

    return 0;
}
