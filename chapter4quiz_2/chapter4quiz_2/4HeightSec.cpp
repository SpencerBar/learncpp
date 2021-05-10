#include <iostream>
#include "constants.h"

double HeightSec(double TowerHeight, int Sec) // calculates current height with seconds from drop and tower height returns current height
{
	double DistanceFallen { gravity * (Sec * Sec) / 2 };
	double CurrentHeight{ TowerHeight - DistanceFallen };
	return CurrentHeight; // to printncalcheight
}