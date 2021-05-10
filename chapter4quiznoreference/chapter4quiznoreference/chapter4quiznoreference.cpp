#include <iostream>

double GetValue()
{
	std::cout << "Enter a real number (decimals allowed); ";
	double x;
	std::cin >> x;
	return x;
}

char GetOperation()
{
	std::cout << "Choose and Operator ( +, _, /, *); ";
	char Operator;
	std::cin >> Operator;
	return Operator;
}

void DoOperation(double num1, char Operator, double num2)
{
	if (Operator == '+')
		std::cout << num1 << " + " << num2 << " is equal to " << num1 + num2 << '\n';
	else if (Operator == '-')
		std::cout << num1 << " - " << num2 << " is equal to " << num1 - num2 << '\n';
	else if (Operator == '/')
		std::cout << num1 << " / " << num2 << " is equal to " << num1 / num2 << '\n';
	else if (Operator == '*')
		std::cout << num1 << " * " << num2 << " is equal to " << num1 * num2 << '\n';

}

int main()
{
	double num1{ GetValue() };
	double num2{ GetValue() };
	char Operator{ GetOperation() };
	DoOperation(num1, Operator, num2);
	return 0;
}