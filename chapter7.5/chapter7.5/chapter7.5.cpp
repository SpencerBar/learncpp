#include <iostream>

int calculate(int x, int y, char op)
{
	switch (op)
	{
	case '+':
		return x + y;
	case '-':
		return x - y;
	case '/':
		return x / y;
	case '*':
		return x * y;
	case '%':
		return x % y;
	default:
		std::cout << "calculate(): Unexpected Operator! ";
		return 0;

	}


}
int main()
{
	std::cout << "Enter an Integer: ";
	int x;
	std::cin >> x;

	std::cout << "Enter another Integer: ";
	int y;
	std::cin >> y;
	
	std::cout << "Now enter an Operator ( +, -, /, *, %): ";
	char op;
	std::cin >> op;

	std::cout << x << ' ' << op << ' ' << y << " is " << calculate(x, y, op) << '\n';

	return 0;
}