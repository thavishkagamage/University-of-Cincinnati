#include "unit_test.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <tuple>
#include <vector>

/* References:
 * https://bioboot.github.io/bimm143_W20/class-material/nw/
 * https://www.ncbi.nlm.nih.gov/nuccore/NC_045512
 * https://www.ncbi.nlm.nih.gov/datasets/coronavirus/proteins/
 */

using direction = enum : uint8_t { diagonal = 0, horizontal = 1, vertical = 2 };
using NWAlignmentDifference = std::vector<std::vector<int>>;
using NWAlignmentDirection = std::vector<std::vector<direction>>;
using ProteinSequence = std::vector<char>;
using Comparison = std::vector<std::tuple<int, char, char>>;

/*
get_id_and_sequence

If the file contains lines that can be read, the id and sequence variables are changed to these lines.

input: a file named file, as well as two strings named id and sequence, which are changed if possible..
output: a boolean value indicating that the file could transfer the correct values to id and sequence

*/
bool get_id_and_sequence(std::ifstream &file, std::string &id, std::string &sequence) {
    if (!file.eof()) {
        getline(file,id);
        if (!file.eof()) {
            getline(file, sequence);
            return true;
        }
    }
    return false;
}
/*
open_file

if possible, opens a file

input: an ifstream, filename, and a file, filename
output: an ifstream, filename, and a file, filename

*/
bool open_file(std::string filename, std::ifstream &file) { 
    file.open(filename);
    
    return file.is_open();
}
/*
string_to_protein_sequence

transforms a string into a proteinsequence that can be used by other procedures.

input: a string, protein_str.
output: a ProteinSequence converted from the string input.

*/
ProteinSequence string_to_protein_sequence(const std::string &protein_str) {
    ProteinSequence prot;
    for (int i = 0; i < protein_str.size(); ++i) {
        prot.push_back(protein_str.at(i));
    }

  return prot;
}
/*
above_left

determines whether or not the protein segment above and to the left is present.

input: an NWAlignmentDifference, difference_vector, a row, and a column
output: an integer value representing the difference vector's row and column value.

*/
int above_left(const NWAlignmentDifference &difference_vector, int row, int col) {
    if (row - 1 >= 0 && col - 1 >= 0) {
        return difference_vector[row - 1][col - 1];
    }
    else if (col == 0) {
        return -1 * row;
    }
    else {
        return -1 * col;
    }
  return 0;
}

/*
above

determines if the above-mentioned protein fragment is present or not

input: an NWAlignmentDifference, difference_vector, a row, and a column
output: an integer value representing the difference vector's row and column value.

*/
int above(const NWAlignmentDifference &difference_vector, int row, int col) {
   if (row - 1 >= 0) {
       return difference_vector[row - 1][col];
   }
   else {
       return -1 * (col + 1);
   }
   return 0;
}

/*
left

determines whether the protein fragment on the left is present or not

input: an NWAlignmentDifference, difference_vector, a row, and a column
output: an integer value representing the difference vector's row and column value.

*/
int left(const NWAlignmentDifference &difference_vector, int row, int col) {
    if (col - 1 >= 0) {
        return difference_vector[row][col - 1];
    }
    else {
        return -1 * (row + 1);
    }
  return 0;
}

void print_comparison(const Comparison &comparison,
                      const std::string &comparison_id, bool verbose = false) {

  std::cout << comparison_id << ": " << comparison.size();

  if (verbose) {
    for (auto i : comparison) {
      auto index = std::get<0>(i);
      auto first = std::get<1>(i);
      auto second = std::get<2>(i);
      std::cout << "(@" << index << ": " << first << ", " << second << "), ";
    }
  }
  std::cout << "\n";
}

template <typename T>
std::vector<T> reverse_vector(const std::vector<T> &to_reverse) {
  std::vector<T> forward;
  for (auto i : to_reverse) {
    forward.push_back(i);
  }
  return forward;
}

Comparison create_comparison(const ProteinSequence &top,
                             const ProteinSequence &bottom,
                             const NWAlignmentDirection &dirs) {
  int row = bottom.size() - 1;
  int col = top.size() - 1;
  Comparison full_result, diff_result;
  while (row >= 0 && col >= 0) {
    char first{0};
    char second{0};
    if (dirs[row][col] == diagonal) {
      first = bottom[row];
      second = top[col];
      row--;
      col--;
    } else if (dirs[row][col] == horizontal) {
      first = '-';
      second = top[col];
      col--;
    } else {
      first = bottom[row];
      second = '-';
      row--;
    }
    full_result.push_back(std::make_tuple(0, first, second));
  }
  full_result = reverse_vector(full_result);

  auto index = 0;
  for (auto i : full_result) {
    auto first = std::get<1>(i);
    auto second = std::get<2>(i);
    if (first != second) {
      diff_result.push_back(std::make_tuple(index, first, second));
    }
    index++;
  }
  return diff_result;
}

NWAlignmentDirection new_direction_vector(int rows, int cols) {
  std::vector<std::vector<direction>> new_direction_vector(
      rows, std::vector<direction>(cols));
  return new_direction_vector;
}

NWAlignmentDifference new_difference_vector(int rows, int cols) {
  NWAlignmentDifference new_diff_vector(rows, std::vector<int>(cols));
  return new_diff_vector;
}

int s(const char a, const char b) {
  if (a == 'X' || b == 'X') {
    return 0;
  }
  if (a == b) {
    return 1;
  }
  return -1;
}

NWAlignmentDirection needleman_wunsch(const ProteinSequence &top,
                                      const ProteinSequence &bottom) {
  auto bottom_length = bottom.size();
  auto top_length = top.size();
  auto directions = new_direction_vector(bottom_length, top_length);
  auto differences = new_difference_vector(bottom_length, top_length);
  for (int r = 0; r < bottom_length; r++) {
    for (int c = 0; c < top_length; c++) {
      int t, l, d, match, insert, del;
      t = above(differences, r, c);
      l = left(differences, r, c);
      d = above_left(differences, r, c);

      match = d + s(top[c], bottom[r]);
      del = t - 1;
      insert = l - 1;

      if (match > del && match > insert) {
        differences[r][c] = match;
        directions[r][c] = diagonal;
      } else if (del > insert) {
        differences[r][c] = del;
        directions[r][c] = vertical;
      } else {
        differences[r][c] = insert;
        directions[r][c] = horizontal;
      }
    }
  }
  return directions;
}

void run_unit_tests() {
  std::ifstream test_input_file;

  check_result(true, open_file("testing.fasta", test_input_file));
  check_result(true, test_input_file.is_open());

  std::string id, sequence;

  check_result(true, get_id_and_sequence(test_input_file, id, sequence));
  check_result(true, id == std::string{"id1"});
  check_result(true, sequence == std::string{"sequence1"});
  check_result(true, get_id_and_sequence(test_input_file, id, sequence));
  check_result(true, id == std::string{"id2"});
  check_result(true, sequence == std::string{"sequence2"});

  test_input_file.close();

  NWAlignmentDifference difference = new_difference_vector(2, 2);
  int counter{0};
  for (auto row : difference) {
    for (auto cell : row) {
      cell = counter++;
    }
  }

  check_result(0, above(difference, 1, 0));
  check_result(-2, above(difference, 0, 1));
  check_result(0, left(difference, 0, 1));
  check_result(-6, left(difference, 5, 0));
  check_result(0, above_left(difference, 1, 1));
  check_result(-4, above_left(difference, 0, 4));
  check_result(-3, above_left(difference, 3, 0));
}

int main() {
    //run_unit_tests();

    std::ifstream reference_file;
    std::ifstream comparison_file;

    open_file("reference.fasta", reference_file);
    open_file("comparison.fasta", comparison_file);
    std::string reference_id_string;
    std::string reference_seq_string;
    get_id_and_sequence(reference_file, reference_id_string, reference_seq_string);

    std::string comparison_id_string;
    std::string comparison_seq_string;

    auto reference_protein_seq = string_to_protein_sequence(reference_seq_string);

    while (get_id_and_sequence(comparison_file, comparison_id_string, comparison_seq_string) == true) {
        auto comparison_protein_sequence = string_to_protein_sequence(comparison_seq_string);
        auto direction = needleman_wunsch(reference_protein_seq, comparison_protein_sequence);
        auto comparison = create_comparison(reference_protein_seq, comparison_protein_sequence, direction);
        print_comparison(comparison, comparison_id_string);
    }

}
