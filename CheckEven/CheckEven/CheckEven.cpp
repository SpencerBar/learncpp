#include <iostream>

int GetInt()
{
	
	int x;
	std::cout << "Enter an Integer; ";
	std::cin >> x;
	return x;
}

void CheckEven(long x)
{
	(x%2) ? (std::cout << x << " is even" << '\n') : (std::cout << x << " is odd" << '\n');
}
int main()
{
	long x{ GetInt() };
	CheckEven(x);

	return 0;
}