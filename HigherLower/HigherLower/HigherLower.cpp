#include <iostream>
#include "GetNumber.h"

int main()
{
	std::cout << "Enter a Number: ";
	int Lower(GetNumber());
	std::cout << "Enter a Larger Number: ";
	int Higher(GetNumber());

	if (Lower > Higher)
	{
		std::cout << "Reordering Numbers!" << '\n';
		int temp(Higher);
		Higher = Lower;
		Lower = temp;
	}
	std::cout << "The smaller number is " << Lower << '\n';
	std::cout << "The larger number is " << Higher << '\n';
	return 0;
}