#include "MonsterProfileScreen.h"
#include <iostream>
#include "Monster.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void MonsterProfileScreen::display() const
{

	string skinType = singleton::player().getMonster().getSkinType();

	cout << "-------------------------------\n";
	cout << "\t Monster profile\n";
	cout << "-------------------------------\n";
	cout << "Breed: " + singleton::player().getMonster().getBreed() << "\n";
	cout << "Name: " + singleton::player().getMonster().getName() << "\n";

	if (skinType == "Fur")
	{
		
		cout << "Fur color: ";

	}

	else
	{

		cout << "Scale color: ";

	}

	cout << singleton::player().getMonster().getSkinColor() << "\n";
	cout << "Eye Color: " + singleton::player().getMonster().getEyeColor() << "\n";
	cout << "Hunger: " + to_string(singleton::player().getMonster().getHunger()) << "\n";
	cout << "Mood: " + to_string(singleton::player().getMonster().getMood()) << "\n";
	cout << "Agility: " + to_string(singleton::player().getMonster().getAgility()) << "\n";
	cout << "Intelligence: " + to_string(singleton::player().getMonster().getIntelligence());
	cout << "\nStrength: " + to_string(singleton::player().getMonster().getStrength());
	cout << "\nExperience: " + to_string(singleton::player().getMonster().getExperience());
	cout << "\n\n";

}