#include <iostream>
#include "checkten.h"

int GetInt()
{
	std::cout << "Enter a single digit integer: ";
	int x{};
	std::cin >> x; 
    CheckTen(x);
		return x;
}