#include <iostream>
#include <functional>
#include <utility>


int getInteger()
{
	std::cout << "Enter an Integer: ";
	int a{};
	std::cin >> a;
	return a;
}

char getOper()
{
	char op{};
	do
	{
		std::cout << "Enter the operation youd like to perform( +,-,/,*): ";
		std::cin >> op;
	} while (op != '+' && op != '-' && op != '/' && op != '*');
	
	return op;
}

int add(int x, int y)
{
	return x + y;
}

int subtract(int x, int y)
{
	return x - y;
}

int divide(int x, int y)
{
	return x / y;
}

int multiply(int x, int y)
{
	return x * y;
}

using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char op)
{
	switch (op)
	{
	default:
	case '+': return &add;
	case '-': return &subtract;
	case '/': return &divide;
	case '*': return &multiply;
	}
}
int main()
{
	int x{ getInteger() };
	int y{ getInteger() };
	char op{ getOper() };
	ArithmeticFunction fcn{ getArithmeticFunction(op) };
	std::cout << x << ' ' << op << ' ' << y << " = " << fcn(x, y) << '\n';
	return 0;
}