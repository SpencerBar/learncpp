#include <iostream>
#include <iterator> // for begin and end std

/*int *find( int *pointToBegin, int *pointToEnd,int value) // uses pointers to know the location of the begining and end of a array 
{
	for (int *pointerInUse{ pointToBegin }; pointerInUse != end; ++pointerInUse) // uses a pointer with that starting location of the array and iterates it untill it reached thew end pointer
	{
		if (*pointerInUse == value) // *pointerinuse turns the location into the actual value and compares it to the required value
		{
			return pointerInUse;
		}
	}
	return pointToEnd;
} */

int main()
{
	int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };
	auto found{ std::find(std::begin(arr),std::end(arr), 20) }; // std::find makes all that work irrelevant :)

	if (found != std::end(arr))
	{
		std::cout << *found << " at " << found << '\n'; // * found print the pointers value and found just prints the location
	}
	return 0;
}