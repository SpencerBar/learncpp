#include <iostream>

int main()
{
	char alphabet{ 'A'};
	while (alphabet <= 'Z')
	{
		std::cout << alphabet << ' ' << static_cast<int>(alphabet) << '\n';
		++alphabet;
	}
	return 0;
}