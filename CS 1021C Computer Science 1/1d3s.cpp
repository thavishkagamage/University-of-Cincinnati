#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}

int main() {
    std::ifstream textfile{ "input.txt" };

    char currentLetter;
    bool leftShift;
    int shiftNum;
    int newIndex;

    if (!(textfile.is_open())) {
        std::cout << "I could not open the file equation file!\n";
        return 0;
    }
    if (!(textfile >> currentLetter))
    {
        std::cout << "Oops: Could not read the shift number from the input file.";
        std::cout << '\n';
        return 0;
    }
    
    if (currentLetter != 'l' && currentLetter != 'r') {
        std::cout << "Oops: Invalid direction in the input file.";
        std::cout << '\n';
        return 0;

    }
    else if (currentLetter == 'l') {
        leftShift = true;
    }
    else {
        leftShift = false;
    }

    
    if(textfile >> shiftNum) {
        if (leftShift == true) {
            shiftNum = -shiftNum;
        }
        else {
            shiftNum = shiftNum;
        }
    }
    else {
        std::cout << "Oops: Could not read the shift number from the input file.";
    }
    
    while (textfile >> currentLetter) {
        newIndex = number_from_letter(currentLetter) + shiftNum;
        if (newIndex > 25) {
            newIndex = newIndex % 26;
        }
        while (newIndex < 0) {
            newIndex = 26 + newIndex;
        }
        currentLetter = letter_from_number(newIndex);
        std::cout << currentLetter;
    }
    std::cout <<'\n';
    
}