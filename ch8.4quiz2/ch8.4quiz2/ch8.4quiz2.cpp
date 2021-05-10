#include <iostream>
#include "Fraction.h"

Fraction GetFraction()
{
	Fraction temp{};
	std::cout << "Enter the numerator of your fraction: ";
	std::cin >> temp.numerator;
	std::cout << "Enter the Denominator of your fraction: ";
	std::cin >> temp.denominator;
	return temp;
}

double multiply(Fraction frac1, Fraction frac2)
{
	double decimal1 = (static_cast<double>(frac1.numerator) / frac1.denominator);
	double decimal2 = (static_cast<double>(frac2.numerator) / frac2.denominator);
	return (decimal1 / decimal2);
}

void printresult(double result)
{
	std::cout << "The reuslt of multiplying those fractions is " << result << '\n';
}
int main()
{
	Fraction frac1{ GetFraction() };
	Fraction frac2{ GetFraction() };
	const double result{ multiply( frac1, frac2) };
	printresult(result);
	return 0;
}