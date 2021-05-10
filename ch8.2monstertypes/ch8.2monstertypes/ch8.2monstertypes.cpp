#include <iostream>

enum class CreatureRace
{
	Orc,
	Goblin,
	Troll,
	Ogre,
	Skele,
};

std::string GetRace(CreatureRace Race)
{
	switch (Race)
	{
	case CreatureRace::Orc:
		return "Orc";
	case CreatureRace::Goblin:
		return "Goblin";
	case CreatureRace::Troll:
		return "Troll";
	case CreatureRace::Ogre:
		return "Ogre";
	case CreatureRace::Skele:
		return "Skeleton";
	default:
			return "???";
	}
}



int main()
{
	auto race{ CreatureRace::Troll };
	return 0
}