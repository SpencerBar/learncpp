#include <iostream>
#include <iterator>


int main()
{
	int number;
	do
	{
		std::cout << "Enter a number between 1 and 9: ";
		std::cin >> number;
		if (std::cin.fail())
		{
			std::cin.clear(); // reset any error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer
		}
	} while (number < 1 || number > 9);
	
		constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
		constexpr int arrayLength{ static_cast<int>(std::size(array)) };

		for (int index{ 0 }; index < arrayLength; ++index)
		{
			std::cout << array[index] << ' ';
		}

		std::cout << '\n';

		for (int index{ 0 }; index < arrayLength; ++index)
		{
			if (array[index] == number)
			{
				std::cout << "The number " << number << "has takes up index " << index;
				break;
			}
		}
	
	return 0;
}
