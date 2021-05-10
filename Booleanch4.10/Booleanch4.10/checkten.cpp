#include <iostream>
#include "enterint.h"

bool CheckTen(int x)
{
	if (x < 10) // following lines loop function untill x<10
		return x;
	else if (x > 10)
		std::cout << "The number you entered is not a single digit!\n";
	int y(GetInt());
	return y;
}