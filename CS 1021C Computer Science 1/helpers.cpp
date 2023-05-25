#include <cassert>
#include <ios>
#include <iostream>

/* is_vowel
* checks whether the inputted character is a vowel or not
* input: a character
* output: a boolean
*/
bool is_vowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	else {
		return false;
	}
}

/* is_consonant
* checks whether the inputted character is a consonant or not
* input: a character
* output: a boolean
*/
bool is_consonant(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return false;
	}
	else {
		return true;
	}
}

/* ends_with
* checks whether the suffix string is the same as the ending characters of candidate.
* input: two strings
* output: a boolean
*/
bool ends_with(std::string candidate, std::string suffix) {
	if (suffix.size() > candidate.size()) {
		return false;
	}
	else if (candidate.size() == 0 && suffix.size() == 0) {
		return true;
	}
	else if (candidate.size() == 0 && suffix.size() != 0) {
		return false;
	}
	else if (candidate.substr(candidate.size() - suffix.size(), candidate.size()) == suffix) {
		return true;
	}
	else {
		return false;
	}
}

/* ends_with_double_consonant
* checks whether the last two characters of a string are both consonants, and they are the same consonant
* input: a string
* output: a boolean
*/
bool ends_with_double_consonant(std::string str) {
	if (str.size() < 2) {
		return false;
	}
	else if (is_consonant(str.at(str.size() - 2)) && is_consonant(str.at(str.size() - 1))) {
		if (str.at(str.size() - 2) == str.at(str.size() - 1))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/* ends_with_cvc
* checks whether the final three characters in a string are a consonant, vowel, and consonant, in that order
* input: a string
* output: a boolean
*/
bool ends_with_cvc(std::string str) {
	if (str.size() > 2) {
		if (is_consonant(str.at(str.size() - 3)) && is_vowel(str.at(str.size() - 2)) && is_consonant(str.at(str.size() - 1))) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

/* count_consonants_at_front
* counts the number of consecutive consonants at the start of a string
* input: string
* output: the number of consonants at the start of the string
*/
int count_consonants_at_front(std::string str) {
	int count = 0;
	if (str.size() == 0) {
		return 0;
	}
	else if (is_vowel(str.at(0))) {
		return 0;
	}
	else {
		for (int i = 0; i < str.size(); ++i) {
			if (is_consonant(str.at(i))) {
				count += 1;
			}
			else {
				return count;
				break;
			}
		}
	}
}

/* check_vowels_at_back
* counts the number of consectutive vowels at the end of a string
* input: a string
* output: the number of vowels that end the string
*/
int count_vowels_at_back(std::string str) {
	int count = 0;
	if (str.size() == 0) {
		return 0;
	}
	else if (is_consonant(str.at(str.size() - 1))) {
		return 0;
	}
	else {
		for (int i = str.size() - 1; i > 0; --i) {
			if (is_vowel(str.at(i))) {
				count += 1;
			}
			else {
				return count;
				break;
			}
		}
	}
}

/* contains_vowel
* checks whether the inputted string contains a vowel or not
* input: a string
* output: a boolean
*/
bool contains_vowel(std::string str) {
	if (str.size() == 0) {
		return 0;
	}
	else {
		for (int i = 0; i < str.size(); ++i) {
			if (is_vowel(str.at(i))) {
				return true;
				break;
			}
		}
	}
}

/* new_ending
* removes the last sufix_length characters from candidate, and then replaces them with replacement
* input: a string, candidate, an int, suffix_length, and another string, replacement
* output: a new string
*/
std::string new_ending(std::string candidate, int suffix_length, std::string replacement) {
	if (candidate.size() == 0) {
		return "";
	}
	else {
		return candidate.substr(0, candidate.size() - suffix_length) + replacement;
	}
}