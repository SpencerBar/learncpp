#include <iostream>

#include "PrintHeight.h"
#include "HeightSec.h"

void PrintnCalcHeight(int Sec, double TowerHeight)
{
	double Height{ HeightSec(TowerHeight, Sec)}; // gets height current depending on seconds 
	PrintHeight (Height, Sec); // sends second values and current height to printheight
}