#include <iostream>
#include <array> // std::array
#include <numeric> // std::reduce
#include "enum.h"

using PlayerInv = std::array<int, Inventory::max_items>;

int countItems(PlayerInv& Items)
{
	return std::reduce(Items.begin(), Items.end());
}


int main()
{
	PlayerInv Items{ 2, 5, 10 };
	std::cout << "The player has " << countItems(Items) << " Items total in their inventory!" << '\n';
	std::cout << "The player has " << Items[Inventory::torch_light] << " Torches total in their inventory!" << '\n';
	return 0;
}