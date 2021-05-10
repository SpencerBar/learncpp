#include <iostream>

void  PrintHeight(double Height, int Sec)// checks if ball is on the ground ( x>0) and prints the height in 
//relation to the # of seconds passed
{
	if (Height > 0)
		std::cout << "The ball's height at " << Sec << " seconds is " << Height << '\n';
	else
		std::cout << "At " << Sec << " seconds the ball is on the ground!";
}