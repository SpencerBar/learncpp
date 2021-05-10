#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int sumTo(const int a)
{
	int sum{ 0 };
	for (int index{ 1 }; index <= a; ++index)
	{
		sum += index;
	}
	return sum;
}

std::pair <int, int> minmax(const int a, const int b)
{	
	if (a > b)
	{
		return std::pair<int, int>(a, b);
	}
	return std::pair<int, int>(b, a);
}

struct employee
{
	std::string name{};
	int num{};
};

void printEmployee(const employee& Employee)
{
	std::cout << Employee.name << ' ';
	std::cout << Employee.num << '\n';
}

int GetIndexLargestValue(const std::vector<int>& array)
{
	auto result = std::max_element(array.begin(), array.end()) - array.begin();
	std::cout << "The index of the largest element is " << result << '\n';
	return result;
}

const std::string& getElement(const std::vector<std::string>& array, const int index)
{
	std::cout << array[index] << '\n';
	return array[index];
}
int main()
{
	int sum{ sumTo(4) };
	std::cout << sum << '\n';
	auto [a, b] {minmax(6, 8)};
	std::cout << a << b << '\n';
	employee Employee{ "Bob", 1 };
	printEmployee(Employee);
	std::vector maxIndex{ 1,2,3,4,2,5,7,2,5 };
	int largestindex{ GetIndexLargestValue(maxIndex) };
	std::vector<std::string> array{ "bob", "james", "pete" , "jones"};
	
	for( auto i: array)
	{
		std::cout << i;
	}

	getElement(array, 1);
	
	return 0;
}