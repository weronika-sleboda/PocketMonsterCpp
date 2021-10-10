#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Monster.h"
#include <string>
#include "Item.h"

class PlayerSingleton final {

public:

	static PlayerSingleton& player()
	{
		
		static PlayerSingleton player;
		return player;

	};

	Monster& getMonster();
	void setMonster(Monster* chosenMonster);
	void resetMonsterProfile();

	const unsigned int getGold() const;
	const unsigned int getSilver() const;
	const unsigned int getWonContests() const;

	void earnGold(unsigned int earnedGold);
	void loseGold(unsigned int lostGold);
	void earnSilver(unsigned int earnedSilver);
	void loseSilver(unsigned int lostSilver);

	void earn(unsigned int earnedGold, unsigned int earnedSilver);
	void buy(unsigned int paidGold, unsigned int paidSilver);
	void win();
	void feed(int index);
	Item& getItem(int index) const;
	void itemsInfo() const;
	const bool isAbleToFeed() const;
	void participateInContest();
	const bool canParticipateInContest() const;
	const bool isAbleToBuy() const;
	void letMonsterRest();
	const unsigned int getContestPerDay() const;

	void loadPlayer
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

	);

private:

	PlayerSingleton();
	~PlayerSingleton();
	PlayerSingleton(const PlayerSingleton&) = delete;
	PlayerSingleton(PlayerSingleton&&) = delete;
	PlayerSingleton& operator = (const PlayerSingleton&) = delete;
	PlayerSingleton& operator = (PlayerSingleton&&) = delete;

	bool canBuy;
	bool canFeed;
	unsigned int gold;
	unsigned int silver;
	unsigned int wonContests;

	Monster* monster;

	size_t itemSize;
	Item* items;

	unsigned int contestPerDay;
	bool canParticipate;

};

#endif