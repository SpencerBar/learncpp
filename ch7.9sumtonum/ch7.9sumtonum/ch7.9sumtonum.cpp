#include <iostream>

int sum(int value)
{
	int total{ 0 };
	for (int count{ 1 }; count <= value; ++count)
	{
		total += count;
	}
	return total;
}

int main()
{
	
	std::cout << sum(90);

	return 0;
}