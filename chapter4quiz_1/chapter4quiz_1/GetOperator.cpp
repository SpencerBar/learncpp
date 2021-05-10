#include <iostream>

char GetOperator()
{
	std::cout << "Enter an Operator (*, +, -, /): ";
	char operation{};
	std::cin >> operation;
	return operation;
}