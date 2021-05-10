#include <iostream>
#include "advertrev.h"

AdRev GetAdvertising()
{
	AdRev temp{};
	std::cout << "Enter the number of ads seen today: ";
	std::cin >> temp.Adnum;
	std::cout << "Enter the % of ads clicked on today: ";
	std::cin >> temp.Adclick;
	std::cout << "Enter the amount made per ad clicked: ";
	std::cin >> temp.$perAd;
	return temp;
}

void PrintAdRev(AdRev ad)
{
	std::cout << "The # of Ads shown today: " << ad.Adnum << '\n';
	std::cout << "The % of Ads clicked on today: " << ad.Adclick << '\n';
	std::cout << "The $ made per ad clicked: $" << ad.$perAd << '\n';
	std::cout << "The gross earnings on ads today: $" << (ad.Adnum * ad.Adclick * ad.$perAd) << '\n';
}

int main()
{
	AdRev TodaysAdRev{GetAdvertising()};
	PrintAdRev(TodaysAdRev);
	
}