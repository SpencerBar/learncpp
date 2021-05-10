#include <iostream>
#include <limits>
#include "constants.h"

// main : needs to set time to 1 establish starting height


//get drophieght guaranteeed by input protecction loop


void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


double Getdroph() //need a function to calculate the height at a given time
{
	while (true)
	{
		std::cout << "Enter the Heigt the ball will be dropped from: ";
		double droph;
		std::cin >> droph;

		if ((droph <= 0) || std::cin.fail())
		{
			std::cin.clear();
			ignoreLine();
		}
		else
			return droph;
	}
}

double GetHeight(double droph, int time)
{
	double distance = { (constants::egrav * time *time) / 2 };
	double currenth = { droph - distance };
	return currenth;
}

void printit(double droph, int time) //need a loop function to print and call the current height untill hits height = 0
{
	while (true)
	{
		double currenth = GetHeight(droph, time);
		if (currenth > 0)
		{
			std::cout << "The ball at " << time << " seconds is " << currenth << '\n';
			++time;
		}
		else
		{
			std::cout << "The ball at " << time << " seconds is on the ground!";
			break;
		}
	} 
}

int main()
{
	double droph(Getdroph());
	int seconds = 0;
	printit(droph, seconds);
	return 0;

}