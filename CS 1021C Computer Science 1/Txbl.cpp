#include <iostream>
#include <string>
#include <iomanip>

/**
 * @brief Truncate a string to a certain length.
 *
 * @param value The string to truncate.
 * @param width The length to which to truncate \p value.
 * @return std::string The truncated string.
 */
std::string truncate_string(const std::string &value, int width) {
  return value.substr(0, width);
}

/**
 * @brief Get an integer from the user
 *
 * @return int The user's input, as an integer.
 */
int get_int() {
  int value{0};
  std::cin >> value;
  return value;
}

/**
 * @brief Get a string from the user.
 *
 * @return std::string The user's input, as a string.
 */
std::string get_string() {
  std::string value{""};
  std::getline(std::cin, value);
  return value;
}

/*The main function is called at program startup after initialization of the non-local objects with static storage duration.
It is the designated entry point to a program that is executed in hosted environment (that is, with an operating system).
The entry points to freestanding programs (boot loaders, OS kernels, etc) are implementation-defined.

It performs
	taxes = (totalGen * PRICEKWH) - (susEnergy * TAXCREDITKWH);
	taxPerShare = taxes / share;
*/

int main() {
	std::string companyName;
	int totalGen;
	int solarGen;
	int windGen;
	int hydroGen;
	int share;
	double susEnergy{0};
	double taxes;
	double nonSusEnergy;
	double taxPerShare;
	const int MAXLENGTH = 40;
	const double PRICEKWH = 0.114951;
	const auto TAXCREDITKWH = 0.018;
	

	std::cout << "Enter company name: ";
	companyName = get_string();
	companyName = truncate_string(companyName, MAXLENGTH);
	

	std::cout << "Enter the total energy generation (in kwH): ";
	totalGen = get_int();
	
	

	std::cout << "Enter solar generation (in kwH): ";
	susEnergy = get_int();
	
	

	std::cout << "Enter wind generation (in kwH): ";
	susEnergy += get_int();
	
	

	std::cout << "Enter hydro generation (in kwH): ";
	susEnergy += get_int();
	

	std::cout << "Enter shares outstanding: ";
	share = get_int();
	
	
	taxes = (totalGen * PRICEKWH) - (susEnergy * TAXCREDITKWH);
	taxPerShare = taxes / share;
	
/* Console output*/
	std::cout << "Revenue Per Share Report Generator\n";
	std::cout << std::setfill('=') << std::setw(80) << "" << "\n";
	std::cout << std::setfill(' ') << std::setw(40) << std::left << "Prepared For: " << std::setw(40) << std::right << std::setfill(' ') << companyName << "\n";
	std::cout << std::setw(40) << std::left << "Taxable Total Revenue: " << std::setw(40) << std::right << std::fixed << std::setprecision(2) << taxes << "\n";
	std::cout << std::setw(40) << std::left << "Taxable Revenue Per Share: " << std::setw(40) << std::right << std::fixed << std::setprecision(2) << taxPerShare << "\n";
	std::cout << std::setfill('=') << std::setw(80) << "" << "\n";


	return 0;
}
