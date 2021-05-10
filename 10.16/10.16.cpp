#include <algorithm> // std::generate, std::find, std::min_element
#include <cmath> // std::abs
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using list_type = std::vector<int>;

namespace config
{
	constexpr int minMult{ 2 };
	constexpr int maxMult{ 4 };
	constexpr int maxDiff{ 4 };
}
list_type squareNum(int start, int iter,int multiplier)
{
	list_type list(static_cast<list_type::size_type>(iter));

	int x{ start };
	for (auto& number : list)
	{
		number = { (x * x) * multiplier };
		++x;
	}
	return list;
}
int getRandomNum(int min, int max)
{
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	
	return std::uniform_int_distribution{ min, max }(mt);
}

list_type getUserNum(int multiplier)
{
	int start{};
	int count{};

	std::cout << "Start where? ";
	std::cin >> start;

	std::cout << "How many? ";
	std::cin >> count;

	// Input validation omitted. All functions assume valid input.

	return squareNum(start, count, multiplier);
}

void printConditions(list_type::size_type iter, int multiplier)
{
	std::cout << "I generated " << iter << " square numbers and multiplied them each by " << multiplier << '\n'
		<< "Do you know what each of the numbers are?" << '\n';
}
int getGuess()
{
	int guess{};
	std::cout << "> ";
	std::cin >> guess;
	return guess;
}

bool SearchAndDestroy(list_type& list, int guess)
{
	auto find{ std::find(list.begin(),list.end(), guess) };
	if (find == list.end())
	{
		return false;
	}
	else
		list.erase(find);
		return true;
}

int findClosestNumb(const list_type& list, int guess)
{
	return *std::min_element(list.begin(), list.end(), [=](int a, int b) {
		return (std::abs(a - guess) < std::abs(b - guess));
	});
}
void printSuccess(list_type::size_type numbersLeft)
{
	if (numbersLeft == 0)
	{
		std::cout << "Congratulations you've found all the numbers!";
	}
	else
		std::cout << "Good job, that number was correct, you still have " << numbersLeft << " numbers remaining." << '\n';
}

void printFailure(const list_type& list, int guess)
{
	int close{ findClosestNumb(list, guess) };
	std::cout << guess << " is wrong!" << '\n';
	if (std::abs(close - guess) <= config::maxDiff)
	{
		std::cout << " Try " << close << " next time.\n";
	}
	else
	{
		std::cout << '\n';
	}
}


bool playRound(list_type& list)
{
	int guess{ getGuess() };

	if (SearchAndDestroy(list, guess))
	{
		printSuccess(list.size());
		return !list.empty();
	}
	else
	{
		printFailure(list, guess);
		return false;
	}
}
int main()
{
	int multiplier(getRandomNum(config::minMult, config::maxMult));
	list_type list{ getUserNum(multiplier) };

	printConditions(list.size(), multiplier);

	while (playRound(list))
		;

	return 0;
}