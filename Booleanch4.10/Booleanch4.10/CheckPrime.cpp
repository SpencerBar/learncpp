#include <iostream>

bool CheckPrime(int x) // first bool function ever gets x and checks if prime
{
	if (x == 2)
		return true;
	else if (x == 3)
		return true;
	else if (x == 5)
		return true;
	else if (x == 7)
		return true;
	else
		return false;
}