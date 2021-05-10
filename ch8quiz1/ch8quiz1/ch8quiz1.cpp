#include <iostream>
#include "monsterenum.h"
#include <string>


struct Monster
{
	Monstertype race;
	int hp;
	std::string name;
};

std::string getMonsterType(Monstertype race)
{
	switch (race)
	{
	
		case Monstertype::Dragon:
			return "Dragon";
		case Monstertype::Giantspider:
			return "Giant Spider";
		case Monstertype::Ogre:
			return "Ogre";
		case Monstertype::Orc:
			return "Orc";
		case Monstertype::Slime:
			return "Slime";
		default:
			return "???";
	}
}

void PrintMonster(Monster monster)
{
	std::cout << "This " << getMonsterType(monster.race) << " is named " << monster.name << " and it has " <<
		monster.hp << " Health." << '\n';
}
int main()
{
	Monster Ogre{ Monstertype::Ogre, 175, "Inigo" };
	Monster Slime{ Monstertype::Slime, 2000, "King Slime" };
	PrintMonster(Ogre);
	PrintMonster(Slime);

	return 0;
}