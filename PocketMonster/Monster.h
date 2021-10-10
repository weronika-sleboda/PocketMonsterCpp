#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster 
{

public:

	Monster();
	virtual ~Monster() {}

	void setBreed(std::string chosenBreed);
	void setName(std::string chosenName);
	void setSkinType(std::string breedSkinType);
	void setSkinColor(std::string chosenSkinColor);
	void setEyeColor(std::string chosenEyeColor);

	const std::string getBreed() const;
	const std::string getName() const;
	const std::string getSkinType() const;
	const std::string getSkinColor() const;
	const std::string getEyeColor() const;

	const bool breedIsChanged() const;
	const bool nameIsChanged() const;
	const bool skinColorIsChanged() const;
	const bool eyeColorIsChanged() const;

	void breedIsChanged(bool breedIsChanged);
	void nameIsChanged(bool nameIsChanged);
	void skinColorIsChanged(bool skinColorIsChanged);
	void eyeColorIsChanged(bool eyeColorIsChanged);

	void loseHunger(unsigned int lostHunger);
	void gainHunger(unsigned int gainedHunger);
	void loseMood(unsigned int lostMood);
	void gainMood(unsigned int gainedMood);

	void gainAgility(unsigned int gainedAgility);
	void gainIntelligence(unsigned int gainedIntelligence);
	void gainStrength(unsigned int gainedStrength);

	const unsigned int getHunger() const;
	const unsigned int getMood() const;
	const unsigned int getAgility() const;
	const unsigned int getIntelligence() const;
	const unsigned int getStrength() const;

	void gainExperience();
	const unsigned int getExperience() const;

	void loadMonster
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

	);

private:

	Monster(Monster&) = delete;
	Monster(Monster&&) = delete;
	Monster& operator = (Monster&) = delete;
	Monster& operator = (Monster&&) = delete;

	std::string breed;
	std::string name;
	std::string skinType;
	std::string skinColor;
	std::string eyeColor;

	bool breedChanged;
	bool nameChanged;
	bool skinColorChanged;
	bool eyeColorChanged;

	unsigned int hunger;
	unsigned int mood;
	unsigned int agility;
	unsigned int intelligence;
	unsigned int strength;

	unsigned int experience;
};

#endif