#include <iostream>

void swap(int& a, int& b)
{
	int temp{ a };
	a = b;
	b = temp;
}

int main()
{
	int a{ 5 };
	int b{ 83 };

	swap(a, b);

	if (a == 83 && b == 5)
	{
		std::cout << "the numbers have been swapped";
	}
	else
		std::cout << "The numbers aren't swapped, oops!";
	return 0;
}