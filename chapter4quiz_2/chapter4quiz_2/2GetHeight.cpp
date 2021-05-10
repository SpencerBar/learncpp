#include <iostream>

double GetHeight() // gets tower height and returns value to main
{
	double x{};
	std::cout << "Enter the Height of the Tower: ";
	std::cin >> x;
	return x;
}