#include <iostream>
#include <cstddef> //for size_t
#include <iterator> // for std::size
#include <utility> // for std::swap


int main()
{
	double array[]{ 12.34,213.176,123.23,4325.34,567.1,231.98,540.45,954.237, 12, 2341, 1, 21 , 234 };
	constexpr std::size_t length{std::size(array)};
			
	for (static std::size_t currentIteration{ 0 }; currentIteration < length - 1; ++currentIteration)
	{
		std::size_t endOfArrayIndex{ length - currentIteration };

		bool swapped{ false };
		
	
			for (std::size_t currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
			{
				if (array[currentIndex] > array[currentIndex + 1])
				{
					std::swap(array[currentIndex], array[currentIndex + 1]);
					swapped = true;
				}
							
			}
		if (!swapped)
		{
				std::cout << "Early termination on iteration: " << currentIteration + 1 << '\n';
				break;
		}
	}
		
	
	for (std::size_t printIndex{ 0 }; printIndex < length; ++printIndex)
	{

		std::cout << array[printIndex] << ' ' << '\n';
		
	}
	
	return 0;
}