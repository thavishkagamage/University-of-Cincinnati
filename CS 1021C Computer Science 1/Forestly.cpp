#include <iostream>

double year;

/*
The Program will
1) calculate the increase/decrease in acres burned between the first and second years,
2) calculate the carbon dioxide emissions for the first and second years, and
3) print the results of those calculations on the console.
*/

int main() {
	int year1;
	int acresBurned1;
	int year2;
	int acresBurned2;
	double carbonEmissions1;
	double carbonEmissions2;
	const double CO2{ 26.7 };

	std::cout << "Enter the first year: ";
	std::cin >> year1;
	std::cout << "\n";

	std::cout << "Enter the acres consumed by forest fire that year: ";
	std::cin >> acresBurned1;
	std::cout << "\n";

	std::cout << "Enter the second year: ";
	std::cin >> year2;
	std::cout << "\n";

	std::cout << "Enter the acres consumed by forest fire that year: ";
	std::cin >> acresBurned2;
	std::cout << "\n";

	carbonEmissions1 = acresBurned1 * CO2;
	carbonEmissions2 = acresBurned2 * CO2;

	auto percentChange = ((carbonEmissions2 - carbonEmissions1) / carbonEmissions1) * 100;

	std::cout << "In year " << year1 << ", forest fires generated " << carbonEmissions1 << " tons of carbon dioxide.\n";
	std::cout << "In year " << year2 << ", forest fires generated " << carbonEmissions2 << " tons of carbon dioxide.\n";
	std::cout << "Between " << year1 << " and " << year2 << ", there was a " << percentChange << "% increase in acres consumed by forest fires.\n";

	
	return 0;

}
