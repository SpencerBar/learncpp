#include <iostream>

void PrintResult(double x, char operation, double y)
{
	if (operation == '+')
	std::cout << x << " + " << y << " is " << x + y << '\n';
	else if (operation == '-')
	std::cout << x << " - " << y << " is " << x - y << '\n';
	else if (operation == '*')
	std::cout << x << " * " << y << " is " << x * y << '\n';
	else if (operation == '/')
	std::cout << x << " / " << y << " is " << x / y << '\n';
}
//if (operation == '+')
//std::cout << x << " + " << y << " is " << x + y << '\n';
//std::cout << x << " - " << y << " is " << x - y << '\n';
//else if (operation == '*')
//std::cout << x << " * " << y << " is " << x * y << '\n';
//else if (operation == '/')
//std::cout << x << " / " << y << " is " << x / y << '\n';