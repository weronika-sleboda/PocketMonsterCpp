#include "PlayerSingleton.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include "Snaky.h"
#include "Dino.h"
#include "Furball.h"

using namespace std;

//*** [IMPORTANT] Dynamic memory allocation in initializer list ***//

PlayerSingleton::PlayerSingleton() :

	canFeed{ false },
	gold{ 10 },
	silver{ 10 },
	wonContests{ 0 },
	monster{ new Monster{} },
	itemSize{ 7 },
	items{ nullptr },
	contestPerDay{ 0 },
	canParticipate{ false },
	canBuy{ false }

{

	

	if (items == nullptr)
	{

		items = new Item[]
		{

			Item
			{ 

				"Strawberry", 
				"* Price: 2 silver\n* Hunger - 3, Mood + 1", 
				0, 0, 2, 3, 1, 0, 0, 0

			},

			Item
			{ 

				"Blueberry", 
				"* Pirce: 1 silver\n* Hunger - 1, Mood + 2",
				0, 0, 1, 1, 2, 0, 0, 0 
		
			},

			Item
			{ 

				"Cherry",
				"* Price: 2 silver\n* Hunger - 2, Mood + 1",
				0, 0, 2, 2, 1, 0, 0, 0 
		
			},

			Item
			{ 

				"Banana", 
				"* Price: 1 gold\n* Hunger - 2, Mood + 1, Strength + 1",
				0, 1, 0, 2, 1, 0, 0, 1 
		
			},

			Item
			{ 
				"Apple", 
				"* Price: 2 gold\n* Hunger - 1, Mood + 2, Agility + 1",
				0, 2, 0, 1, 2, 1, 0, 0 
		
			},

			Item
			{ 
				
				"Melon", 
				"* Price: 4 silver\n* Hunger - 4, Mood + 2",
				0, 0, 4, 4, 2, 0, 0, 0
		
			},

			Item
			{

				"Walnut",
				"* Price: 2 gold\n* Hunger - 4, Mood + 2, Intelligence + 1",
				0, 2, 0, 1, 1, 0, 1, 0

			}

		};

	}
	
}

//*** [IMPORTANT] Memory address of monster object is getting realeased. ***//

PlayerSingleton::~PlayerSingleton()
{

	delete monster;
	cout << "\nMonster has been deleted\n";

	delete[] items;
	cout << "\nArray has been deleted\n";

}


Monster& PlayerSingleton::getMonster()
{

	return *monster; 

}

void PlayerSingleton::setMonster(Monster* chosenMonster)
{
	//>>> If changes has been made before choosing the breed, save them.

	string name = monster->getName();
	string skinColor = monster->getSkinColor();
	string eyeColor = monster->getEyeColor();

	//***[IMPORTANT] Dynamic allocation, reassignment ***//

	// 1. Release memory
	// "new Monster" which was dynamically allocated in the constructor
	// gets deleted. It's not needed anymore.

	delete monster; 
	
	// 2. Change memory adrress of monster pointer so that it points to
	// the memory adress of chosenMonster 
	// (Now they both point to the same memory location)

	monster = chosenMonster;

	// 3. Let chosenMonster pointer point to null so that it doesn't point 
	// to the same memory adress as monster

	chosenMonster = nullptr;

	monster->setName(name);
	monster->setSkinColor(skinColor);
	monster->setEyeColor(eyeColor);

	if (name != "???") 
	{

		monster->nameIsChanged(true);

	}

	if (skinColor != "???")
	{

		monster->skinColorIsChanged(true);

	}

	if (eyeColor != "???")
	{

		monster->eyeColorIsChanged(true);

	}

}

void PlayerSingleton::resetMonsterProfile()
{

	//***[IMPORTANT] Dynamic allocation, reassignment ***//

	// 1. Release memory
	// Delete object which monster is pointing to.

	delete monster;

	// 2. Reassign monster pointer, so that it points to new memory address;
	
	monster = new Monster();

}

const unsigned int PlayerSingleton::getGold() const
{

	return gold;

}

const unsigned int PlayerSingleton::getSilver() const
{

	return silver;

}

const unsigned int PlayerSingleton::getWonContests() const
{

	return wonContests;

}

void PlayerSingleton::earnGold(unsigned int earnedGold)
{

	unsigned int maxGold = 999;

	gold += earnedGold;

	if (gold > maxGold) 
	{

		gold = maxGold;

	}

}

void PlayerSingleton::loseGold(unsigned int lostGold)
{

	gold -= lostGold;

	if (gold < 0) 
	{

		gold = 0;

	}

}

void PlayerSingleton::earnSilver(unsigned int earnedSilver)
{

	unsigned int maxSilver = 999;

	silver += earnedSilver;

	if (silver > maxSilver)
	{

		silver = maxSilver;

	}

}

void PlayerSingleton::loseSilver(unsigned int lostSilver)
{

	silver -= lostSilver;

	if (silver < 0)
	{

		silver = 0;

	}
}


void PlayerSingleton::earn(unsigned int earnedGold, unsigned int earnedSilver)
{

	earnGold(earnedGold);
	earnSilver(earnedSilver);

}

void PlayerSingleton::buy(unsigned int paidGold, unsigned int paidSilver)
{

	canBuy = false;

	bool hasGold{ false };
	bool hasSilver{ false };

	if (gold >= paidGold)
	{

		loseGold(paidGold);
		hasGold = true;

	}

	if (silver >= paidSilver) 
	{

		loseSilver(paidSilver);
		hasSilver = true;

	}

	if (hasGold && hasSilver)
	{

		canBuy = true;

	}

}

const bool PlayerSingleton::isAbleToBuy() const
{

	return canBuy;

}

void PlayerSingleton::feed(int index)
{

	canFeed = false;

	if (index < itemSize) 
	{

		items[index].use();

		if (items[index].isInBackpack())
		{

			canFeed = true;

		}

	}
	
}

void PlayerSingleton::win()
{

	unsigned int maxWins {999};

	if (wonContests < maxWins) 
	{

		++wonContests;

	}

}

void PlayerSingleton::itemsInfo() const
{

	int counter{1};

	for (size_t index = 0; index < itemSize; index++)
	{

		cout <<  counter++ << ". " << items[index].description() + "\n";

	}

}

const bool PlayerSingleton::isAbleToFeed() const
{

	return canFeed;

}

Item& PlayerSingleton::getItem(int index) const
{

	if (index < itemSize)
	{

		return items[index];

	}

	return items[0];

}

void PlayerSingleton::participateInContest()
{

	contestPerDay++;

	if (contestPerDay <= monster->getStrength())
	{

		canParticipate = true;

	}

	else
	{

		canParticipate = false;

	}
}

const bool PlayerSingleton::canParticipateInContest() const
{

	return canParticipate;

}

void PlayerSingleton::letMonsterRest() 
{

	contestPerDay = 0;

}

const unsigned int PlayerSingleton::getContestPerDay() const
{

	return contestPerDay;

}

void PlayerSingleton::loadPlayer
(

	unsigned int theGold,
	unsigned int theSilver,
	unsigned int theWonContests,
	unsigned int theContestPerDay,
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
	unsigned int theExperience,
	unsigned int theStrawberry,
	unsigned int theBlueberry,
	unsigned int theCherry,
	unsigned int theBanana,
	unsigned int theApple,
	unsigned int theMelon,
	unsigned int theWalnut

)
{

	gold = theGold;
	silver = theSilver;
	wonContests = theWonContests;
	contestPerDay = theContestPerDay;

	//>>> Load monster data

	getMonster().loadMonster
	(
	
		theBreed,
		theName,
		theSkinType,
		theSkinColor,
		theEyeColor,
		theHunger,
		theMood,
		theAgility,
		theIntelligence,
		theStrength,
		theExperience
	
	);

	if (monster->getBreed() == "Snaky")
	{
		//***[IMPORTANT] Dynamic memory allocation, reassignment

		Snaky* snaky = new Snaky();
		setMonster(snaky);
		snaky = nullptr;

	}

	if (monster->getBreed() == "Dino")
	{
		//***[IMPORTANT] Dynamic memory allocation, reassignment

		Dino* dino = new Dino();
		setMonster(dino);
		dino = nullptr;

	}

	if (monster->getBreed() == "Furball")
	{
		//***[IMPORTANT] Dynamic memory allocation, reassignment

		Furball* furball = new Furball();
		setMonster(furball);
		furball = nullptr;

	}

	//>>> Load items

	getItem(0).loadItem(theStrawberry);
	getItem(1).loadItem(theBlueberry);
	getItem(2).loadItem(theCherry);
	getItem(3).loadItem(theBanana);
	getItem(4).loadItem(theApple);
	getItem(5).loadItem(theMelon);
	getItem(6).loadItem(theWalnut);

}

