#include <iostream>
#include <string_view>
#include <string>

std::string getUserName()
{
	std::cout << "Enter a name: ";
	std::string name{};
	std::cin >> name;
	return name;
}
int main()
{
	constexpr std::string_view array[]{ "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
	bool x{ true };
	while (x)
	{


		std::string UserName{ getUserName() };
		bool namematch{ false };

		for (const auto checkName : array)
		{
			if (checkName == UserName)
			{
				namematch = true;
				break;
			}
		}

		if (namematch)
		{
			std::cout << "The name " << UserName << " was found!\n";
		}
		else
		{
			std::cout << "The name " << UserName << " was not found!\n";
		}

		
			std::string yn{};
			std::cout << "Continue looking for names? (y/n): ";
			std::cin >> yn;
			if (yn == "y")
			{
				x = true;
				
			}
			else if( yn == "n")
			{ 
				x = false;
				
			}
		

	}
	return 0;
}