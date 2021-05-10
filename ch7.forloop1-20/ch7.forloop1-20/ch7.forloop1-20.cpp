#include <iostream>

int main()
{
	
	for (int count20{ 0 }; count20 <= 20; ++count20)
	{
		
		if (count20 < 9)
			std::cout << count20 << "  ";
		else if (count20 == 10)
			std::cout << count20 << '\n';
		else
			std::cout << count20 << ' ';
	}
	return 0;
}