#include <iostream>
#include <cassert>

bool isPrime(int x)
{
	//need to take x and check is if only divisible by 1 and self
	int dividedby{ 1 };
	for (int test{ 2 }; test <= x; ++test)
	{
		if ((x % test) == 0)
			++dividedby;

	}
	std::cout << x << " is divisible by " << dividedby << " numbers that are smaller or equal to it." << '\n';
	return (dividedby == 2);
}
int main()
{
	assert(!isPrime(0));
	assert(!isPrime(1));
	assert(isPrime(2));
	assert(isPrime(3));
	assert(!isPrime(4));
	assert(isPrime(5));
	assert(isPrime(7));
	assert(!isPrime(9));
	assert(isPrime(11));
	assert(isPrime(13));
	assert(!isPrime(15));
	assert(!isPrime(16));
	assert(isPrime(17));
	assert(isPrime(19));
	assert(isPrime(97));
	assert(!isPrime(99));
	assert(!isPrime(99));
	assert(isPrime(13417));

	std::cout << "Success!";

	return 0;
}