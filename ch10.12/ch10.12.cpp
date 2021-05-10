#include <iostream>

int factorial(int x)
{
	if (x == 0)
		return 1;
	else
		return factorial(x - 1) * x;
}

int sumnumber(int x)
{
	if (x < 10)
	{
		return x;
	}
	else
	{
		return sumnumber(x / 10) + x % 10;
	}
}

void printbinary(unsigned int x)
{
	if (x > 1)
	{
		printbinary(x / 2);
	}

	std::cout << x % 2;
}
int main()
{
	for (int index{ 0 }; index < 8; ++index)
	{
		std::cout << factorial(index) << '\n';
	}
	std::cout << sumnumber(93427);

	printbinary()
}