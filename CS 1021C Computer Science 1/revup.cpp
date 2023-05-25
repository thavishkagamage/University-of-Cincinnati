#include <string.h>

#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

std::string intended_use{""};
double requested_loan_amt{0.0};
bool non_profit_business{false};

void get_input(int argc, char **argv) {
  if (argc == 1) {
    intended_use = "debt";
    requested_loan_amt = 200.00;
    non_profit_business = true;
  } else if (argc == 4) {
    // The first CLI parameter is the intended use for the loan.
    intended_use = argv[1];

    // NB: No error checking is done here. User must be careful to only
    // pass valid numbers!
    requested_loan_amt = static_cast<double>(atoi(argv[2]));

    // The final CLI parameter is whether the applicant's business is
    // a non-profit. If the parameter is "true", then the business is
    // a non-profit.
    if (!strcmp("true", argv[3])) {
      non_profit_business = true;
    }
  } else {
    exit(EXIT_FAILURE);
  }
}

void print_horizontal_line(int columns) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill('=') << std::setw(columns) << ""
            << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}

std::string format_money(double money) {
  std::stringstream formatted_money{};
  formatted_money << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_money << "$" << money;
  return formatted_money.str();
}

std::string format_percentage(double percentage) {
  std::stringstream formatted_percentage{};
  formatted_percentage << std::fixed << std::setprecision(2) << std::showpoint;
  formatted_percentage << percentage << "%";
  return formatted_percentage.str();
}

/*This converts boolean to a Yes/No string*/
std::string bool_to_yes_no(bool value) {
  std::string yes_no{""};
  if (value) {
    yes_no = std::string{"Yes"};
  } else {
    yes_no = std::string{"No"};
  }
  return yes_no;
}

void print_labeled_value(const std::string &label, int label_width,
                         const std::string &value, int value_width) {
  auto flags = std::cout.flags();
  auto fill = std::cout.fill();
  std::cout << std::setfill(' ') << std::left << std::setw(label_width) << label
            << std::right << std::setw(value_width) << value << "\n";
  std::cout.flags(flags);
  std::cout.fill(fill);
}

const double NON_PROFIT_INTEREST_RATE = 2.75;
const double FOR_PROFIT_INTEREST_RATE = 3.75;
const double FEE_AMOUNT = 100.00;
const double NO_FEE_AMOUNT = 0.00;
const double LOAN_MAX = 2000000;
const double LOAN_MID = 200000;
const double LOAN_MIN = 25000;

/*The main function serves as a starting point for executing the code contained within it.
It specifies the functions that will be used to carry out the precise tasks included within those functions.
You can declare functions, variables, parameters, ...., call functions, print stuff, create loops, create if/else statements,
compute values, and basically everything else inside this main function.*/

int main(int argc, char **argv) {
  get_input(argc, argv);

  print_horizontal_line(80);
  // Complete the implementation of main according to the specifications in the
  // lab document! Do not remove any code that exists. Simply add additional
  // code to meet the description of RevUp's operation.

  if (intended_use == "payroll" || intended_use == "rent" ||
      intended_use == "mortgage" || intended_use == "utilities" ||
      intended_use == "debt" || intended_use == "ordinary business expenses") {
    if (requested_loan_amt <= LOAN_MAX) {
      print_labeled_value("Eligibility Status:", 40, bool_to_yes_no(true), 40);
      /* because the intended use is valid and the amount is less than or equal
      to 2 million, the value for eligibility is true, which will result in
      "Yes" being outputted.*/

      if (non_profit_business == true) {
        print_labeled_value("Interest Rate:", 40,
                            format_percentage(NON_PROFIT_INTEREST_RATE), 40);
      } else {
        print_labeled_value("Interest Rate:", 40,
                            format_percentage(FOR_PROFIT_INTEREST_RATE), 40);
      }

      if (requested_loan_amt > LOAN_MIN) {
        print_labeled_value("Application Fee:", 40, format_money(FEE_AMOUNT),
                            40);
        print_labeled_value("Collateral Required:", 40, bool_to_yes_no(true),
                            40);
        /*if the requested amount is more than $25,000, the requester is
         required to provide a collateral.*/
      } else {
        print_labeled_value("Application Fee:", 40, format_money(NO_FEE_AMOUNT),
                            40);
        print_labeled_value("Collateral Required:", 40, bool_to_yes_no(false),
                            40);
        /* if the requested amount is less than $25,000, there is no collateral
         * required.*/
      }

      if (requested_loan_amt > LOAN_MID) {
        print_labeled_value("Personal Guaranty:", 40, bool_to_yes_no(true), 40);
        /* If the requested amount exceeds $200,000, a guarantee is required, hence the output will be "Yes." */
      } else {
        print_labeled_value("Personal Guaranty:", 40, bool_to_yes_no(false),
                            40);
        /* If the requested amount is less than $200,000, there is no guarantee, hence the output will be "No."*/
      }

    } else {
      /* Although the intended usage is legitimate,
      the outputted value will be false because the quantity is not less than or equal to 2 million,
      resulting in a "No" for eligibility.*/

      print_labeled_value("Eligibility Status:", 40, bool_to_yes_no(false), 40);
    }
  } else {
    /* The loan is not acceptable because the planned purpose is invalid, hence the output will be "No."*/

    print_labeled_value("Eligibility Status:", 40, bool_to_yes_no(false), 40);
  }

  print_horizontal_line(80);

  return 0;
}
