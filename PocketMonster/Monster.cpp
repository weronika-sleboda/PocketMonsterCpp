#include "Monster.h"

using namespace std;

	
//>>> Constructor begins

Monster::Monster() :

	breed{ "???" },
	name{ "???" },
	skinType{ "???" },
	skinColor{ "???" },
	eyeColor{ "???" }, 
	breedChanged{ false },
	nameChanged{ false },
	skinColorChanged{ false },
	eyeColorChanged{ false },
	hunger{ 0 },
	mood{ 10 },
	agility{ 0 },
	intelligence{ 0 },
	strength{ 0 },
	experience{ 0 }

{} 

//>>> Constructor ends


void Monster::setBreed(string chosenBreed)
{

	breed = chosenBreed;

}

void Monster::setName(string chosenName)
{

	name = chosenName;

}

void Monster::setSkinType(string breedSkinType)
{

	skinType = breedSkinType;

}

void Monster::setSkinColor(string chosenSkinColor)
{

	skinColor = chosenSkinColor;

}

void Monster::setEyeColor(string chosenEyeColor)
{

	eyeColor = chosenEyeColor;

}

const string Monster::getBreed() const
{

	return breed;

}

const string Monster::getName() const
{

	return name;

}

const string Monster::getSkinType() const
{

	return skinType;

}

const string Monster::getSkinColor() const
{

	return skinColor;

}

const string Monster::getEyeColor() const
{

	return eyeColor;

}

const bool Monster::breedIsChanged() const
{

	return breedChanged;

}

const bool Monster::nameIsChanged() const
{

	return nameChanged;

}

const bool Monster::skinColorIsChanged() const
{

	return skinColorChanged;

}

const bool Monster::eyeColorIsChanged() const
{

	return eyeColorChanged;

}


void Monster::breedIsChanged(bool breedIsChanged) 
{

	breedChanged = breedIsChanged;

}

void Monster::nameIsChanged(bool nameIsChanged) 
{

	nameChanged = nameIsChanged;

}

void Monster::skinColorIsChanged(bool skinColorIsChanged) 
{

	skinColorChanged = skinColorIsChanged;

}

void Monster::eyeColorIsChanged(bool eyeColorIsChanged)
{

	eyeColorChanged = eyeColorIsChanged;

}

void Monster::loseHunger(unsigned int lostHunger)
{

	hunger -= lostHunger;

	if (hunger < 0) 
	{

		hunger = 0;

	}

}

void Monster::gainHunger(unsigned int gainedHunger)
{
	unsigned int maxHunger{ 10 };

	hunger += gainedHunger;

	if (hunger > maxHunger) 
	
	{

		hunger = maxHunger;

	}

}

void Monster::loseMood(unsigned int lostMood)
{

	mood -= lostMood;

	if (mood < 0)
	{

		mood = 0;

	}

}

void Monster::gainMood(unsigned int gainedMood)
{

	unsigned int maxMood{ 10 };

	mood += gainedMood;

	if (mood > maxMood)
	{

		mood = maxMood;

	}

}

void Monster::gainAgility(unsigned int gainedAgility)
{

	unsigned int maxAgility{ 999 };

	agility += gainedAgility;

	if (agility > maxAgility)
	{

		agility = maxAgility;

	}

}

void Monster::gainIntelligence(unsigned int gainedIntelligence)
{

	unsigned int maxIntelligence{ 999 };

	intelligence += gainedIntelligence;

	if (intelligence > maxIntelligence)
	{

		intelligence = maxIntelligence;

	}

}

void Monster::gainStrength(unsigned int gainedStrength)
{

	unsigned int maxStrength{ 999 };

	strength += gainedStrength;

	if (strength > maxStrength)
	{

		strength = maxStrength;

	}

}

const unsigned int Monster::getHunger() const
{

	return hunger;

}

const unsigned int Monster::getMood() const
{

	return mood;

}

const unsigned int Monster::getAgility() const
{

	return agility;

}

const unsigned int Monster::getIntelligence() const
{

	return intelligence;

}

const unsigned int Monster::getStrength() const
{

	return strength;

}

void Monster::gainExperience()
{

	experience += intelligence;

}


const unsigned int Monster::getExperience() const
{

	return experience;

}

void Monster::loadMonster
(

	std::string theBreed,
	std::string theName,
	std::string theSkinType,
	std::string theSkinColor,
	std::string theEyeColor,
	unsigned int theHunger,
	unsigned int theMood,
	unsigned int theAgility,
	unsigned int theIntelligence,
	unsigned int theStrength,
	unsigned int theExperience

)
{

	breed = theBreed;
	name = theName;
	skinType = theSkinType;
	skinColor = theSkinColor;
	eyeColor = theEyeColor;
	hunger = theHunger;
	mood = theMood;
	agility = theAgility;
	intelligence = theIntelligence;
	strength = theStrength;
	experience = theExperience;

}
