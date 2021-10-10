#include "Item.h"
#include "PlayerSingleton.h"
#include <string>

using namespace std;

typedef PlayerSingleton singleton;

Item::Item
(

	string theName,
	string theInfo,
	unsigned int theAmount,
	unsigned int theGold,
	unsigned int theSilver,
	unsigned int theHunger,
	unsigned int theMood,
	unsigned int theAgility,
	unsigned int theIntelligence,
	unsigned int theStrength

) :

	owns{ false },
	canBuy{ false },
	name{ theName },
	info{ theInfo },
	amount{ theAmount },
	gold{ theGold },
	silver{ theSilver },
	hunger{ theHunger },
	mood{ theMood },
	agility{ theAgility },
	intelligence{ theIntelligence },
	strength{ theStrength }

{}

const unsigned int Item::getAmount() const
{

	return amount;

}

void Item::use()
{

	owns = false;

	if (amount >= 1) 
	{

		owns = true;

		--amount;

		singleton::player().getMonster().loseHunger(hunger);
		singleton::player().getMonster().gainMood(mood);
		singleton::player().getMonster().gainAgility(agility);
		singleton::player().getMonster().gainIntelligence(intelligence);
		singleton::player().getMonster().gainStrength(strength);

	}

}

void Item::buy(unsigned int goldPrice, unsigned int silverPrice)
{

	canBuy = false;

	if 
	(
		
		singleton::player().getGold() >= goldPrice &&
		singleton::player().getSilver() >= silverPrice

	)
	{

		canBuy = true;
		singleton::player().buy(goldPrice, silverPrice);

	}

}

const string Item::description() const
{

	return  name + " [Amount: " + to_string(amount) + "]\n" + info + "\n";
			
}

const bool Item::isInBackpack() const
{

	return owns;

}

const std::string Item::getName() const
{

	return name;

}

const unsigned int Item::getGold() const
{

	return gold;

}

const unsigned int Item::getSilver() const
{

	return silver;

}

void Item::add(unsigned int item)
{

	unsigned int maxItems = 999;

	amount += item;

	if (amount > maxItems)
	{

		amount = maxItems;

	}

}

void Item::loadItem(unsigned int theAmount)
{

	amount = theAmount;

}

