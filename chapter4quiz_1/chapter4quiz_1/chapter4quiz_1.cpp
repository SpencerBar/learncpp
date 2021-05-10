#include <iostream>
#include "GetDouble.h"
#include "GetOperator.h"
#include "PrintResult.h"
int main()
{
	double x{ GetDouble() };
	double y{ GetDouble() };
	char operation{ GetOperator() };
	PrintResult(x, operation, y);
	return 0;
	
}