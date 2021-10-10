#include "SaveFileScreen.h"
#include <iostream>
#include <fstream>
#include "PlayerSingleton.h"
#include "Message.h"
#include "SaveFileConstant.h"

typedef PlayerSingleton singleton;

using namespace std;

void SaveFileScreen::display() const
{

	saveFile();
	
	Message message;
	message.popup("The file has been succesfully saved;");

}

void SaveFileScreen::saveFile() const
{

	ofstream file{ fileName };

	//***[IMPORTANT] I know that a container and a loop
	// would be a better solution in this case, but I just want to
	// finish this project and this is the fastest way to do it
	// right now. It can be improved later.
	
	unsigned int gold = singleton::player().getGold();
	unsigned int silver = singleton::player().getSilver();
	unsigned int wonContests = singleton::player().getWonContests();
	unsigned int contestPerDay = singleton::player().getContestPerDay();
	string breed = singleton::player().getMonster().getBreed();
	string name = singleton::player().getMonster().getName();
	string skinType = singleton::player().getMonster().getSkinType();
	string skinColor = singleton::player().getMonster().getSkinColor();
	string eyeColor = singleton::player().getMonster().getEyeColor();
	unsigned int hunger = singleton::player().getMonster().getHunger();
	unsigned int mood = singleton::player().getMonster().getMood();
	unsigned int agility = singleton::player().getMonster().getAgility();
	unsigned int intelligence = singleton::player().getMonster().getIntelligence();
	unsigned int strength = singleton::player().getMonster().getStrength();
	unsigned int experience = singleton::player().getMonster().getExperience();
	unsigned int strawberry = singleton::player().getItem(0).getAmount();
	unsigned int bluberry = singleton::player().getItem(1).getAmount();
	unsigned int cherry = singleton::player().getItem(2).getAmount();
	unsigned int banana = singleton::player().getItem(3).getAmount();
	unsigned int apple = singleton::player().getItem(4).getAmount();
	unsigned int melon = singleton::player().getItem(5).getAmount();
	unsigned int walnut = singleton::player().getItem(6).getAmount();

	file << to_string(gold) << " ";
	file << to_string(silver) << " ";
	file << to_string(wonContests) << " ";
	file << to_string(contestPerDay) << " ";
	file << breed << " ";
	file << name << " ";
	file << skinType << " ";
	file << skinColor << " ";
	file << eyeColor << " ";
	file << to_string(hunger) << " ";
	file << to_string(mood) << " ";
	file << to_string(agility) << " ";
	file << to_string(intelligence) << " ";
	file << to_string(strength) << " ";
	file << to_string(experience) << " ";

	file.close();

}