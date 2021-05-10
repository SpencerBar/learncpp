#include <iostream>
#include <limits>

void clearextra()
{ //clears std::cin after an input to make sure its ready for next input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getdouble()
{
	while (true) // infinite loop untill returned properly
	{
		std::cout << "Enter a Double value: ";
		double x;
		std::cin >> x;

		if (std::cin.fail()) // checks if wrong input was made
		{
			std::cin.clear();
			clearextra(); // removes extras
			std::cout << "Oops, thats an invalid input, please try again!" << '\n';
		}
		else
		{
			clearextra();
			return x;
		}

	}
}

char getop()
{
	while (true)
	{
		std::cout << "Enter a Mathematical Operation (*, %, +, -, /): ";
		char x;
		std::cin >> x;

		switch(x)
		{
		case '*':
		case '/':
		case '+':
		case '-':
		case '%':
			return x;
		default:
			std::cout << "Oops, thats an invalid input, please try again!" << '\n';
		}
	}
}

int getint()
{
	while (true)
	{
		std::cout << "Enter an Integer: ";
		int x;
		std::cin >> x;

		if (std::cin.fail())
		{
			std::cin.clear();
			clearextra();
			std::cout << "The number you entered is either too large or too small, Try again." << '\n';
		}
		else
		{
			clearextra();
			return x;
		}
	}
}
int main()
{
	int x(getint());
	double y(getdouble());
	char op(getop());
}