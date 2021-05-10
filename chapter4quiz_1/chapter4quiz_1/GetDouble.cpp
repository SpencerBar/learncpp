#include <iostream>

double GetDouble()
{
	double x{};
	std::cout << "Enter a double value: ";
	std::cin >> x;
	return x;
}