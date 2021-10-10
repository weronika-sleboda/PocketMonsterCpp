#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{

public:

	Item
	(

		std::string theName,
		std::string theInfo,
		unsigned int theAmount,
		unsigned int theGold,
		unsigned int theSilver,
		unsigned int theHunger,
		unsigned int theMood,
		unsigned int theAgility,
		unsigned int theIntelligence,
		unsigned int theStrength

	);

	const unsigned int getAmount() const;
	void use();
	void buy(unsigned int goldPrice, unsigned int silverPrice);
	const std::string description() const;
	const bool isInBackpack() const;
	const std::string getName() const;
	const unsigned int getGold() const;
	const unsigned int getSilver() const;
	void add(unsigned int item);
	void loadItem(unsigned int theAmount);

private:

	bool owns;
	bool canBuy;
	std::string name;
	std::string info;
	unsigned int amount;
	unsigned int gold;
	unsigned int silver;
	unsigned int hunger;
	unsigned int mood;
	unsigned int agility;
	unsigned int intelligence;
	unsigned int strength;

};

#endif