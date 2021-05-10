#include <iostream>
#include "Constants.h"

int main()
{
	using NumberOf = int;
	std::cout << "How mant students are in your class? ";
	NumberOf Students{};
	std::cin >> Students;

	if (Students > Constants::Max_class_size)
		std::cout << "There are too many students in this class";
	else
		std::cout << "This class isn't too large!";

	return 0;
}
