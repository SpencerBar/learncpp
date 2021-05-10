#include <iostream>
#include "constants.h"
#include "GetHeight.h"
#include "PrintnCalcHeight.h"
int main()
{
const double TowerHeight {GetHeight()}; // assigns tower height to a double value
PrintnCalcHeight(0, TowerHeight);//all of these call printncalcheight at different time values
PrintnCalcHeight(1, TowerHeight);
PrintnCalcHeight(2, TowerHeight);
PrintnCalcHeight(3, TowerHeight);
PrintnCalcHeight(4, TowerHeight);
PrintnCalcHeight(5, TowerHeight);// path of program: main -> GetHeight -> printncalcheight -> heightsec -> printncalcheight -> print height -> main -> looptill5sec-> end
return 0;
}