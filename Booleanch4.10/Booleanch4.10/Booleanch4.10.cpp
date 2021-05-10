#include <iostream>
#include "enterint.h"
#include "CheckPrime.h" 


int main()
{
	int x{ GetInt()}; // gets integer from user defines it as x
	if (CheckPrime(x) ) // bool checks if number matches prime numbers between 1 and 9, returns false otherwise
		std::cout << "The number is prime!\n";
	else std::cout << " The number is NOT prime!\n";

return 0;

}