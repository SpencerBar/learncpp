#include <iostream>
#include "Constant.h"

double GetHeight()
{
	std::cout << "Enter the hieght of a given tower: ";
	double Towerheight;
	std::cin >> Towerheight;
	return Towerheight;
}

double Height(double towerheight, int time)
{
	double Distance{ gravity*(time * time) / 2 };
	double Height{ towerheight - Distance };
	return Height;
}

void Heightprint(double Towerheight, int time)
{
	double CurrentHeight{ Height(Towerheight, time) };
	if (CurrentHeight > 0.0)
		std::cout << "The ball is " << CurrentHeight << " meters off of the ground!" << '\n';
	else 
		std::cout << "The ball has hit the ground!" << '\n';

}
int main()
{
	double Towerheight{ GetHeight() };
	Heightprint(Towerheight, 0);
	Heightprint(Towerheight, 1);
	Heightprint(Towerheight, 2);
	Heightprint(Towerheight, 3);
	Heightprint(Towerheight, 4);
	Heightprint(Towerheight, 5);
	
	return 0;
}