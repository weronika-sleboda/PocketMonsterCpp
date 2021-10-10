#include "ContestMenuScreen.h"
#include "Message.h"
#include "PlayerSingleton.h"
#include <string>
#include <stdlib.h>

typedef PlayerSingleton singleton;

using namespace std;

void ContestMenuScreen::display() const
{

	string monsterName = singleton::player().getMonster().getName();

	singleton::player().participateInContest();

	if (singleton::player().canParticipateInContest())
	{

		if (won())
		{

			Message wonMessage;
			wonMessage.popup(monsterName + " won the contest!");

			takePrice();
		}

		else
		{

			Message lostMessage;
			lostMessage.popup(monsterName + " has lost the contest.");

			singleton::player().getMonster().loseMood(1);

			Message lostMood;
			lostMood.popup(monsterName + " lost - 1 mood.");

		}

		singleton::player().getMonster().gainExperience();

		Message experienceMessage;
		experienceMessage.popup
		(

			monsterName + " gained + " +
			to_string(singleton::player().getMonster().getIntelligence()) +
			" experience."
		);

		if (singleton::player().getMonster().getExperience() % 10 == 0)
		{

			gainSkill();

		}

	}

	else
	{

		Message errorMessage;
		errorMessage.popup
		(
			
			monsterName + " is too tired. Let them rest and come back tomorrow. "
		
		);

	}

}

bool ContestMenuScreen::won() const
{

	unsigned int firstDice = rand() % 100;
	unsigned int secondDice = rand() % 100;
	unsigned int thirdDice = rand() % 100; 
	unsigned int fourthDice = rand() % 100;

	int wins{ 0 };

	if (firstDice <= singleton::player().getMonster().getAgility())
	{

		wins++;

	}

	if (secondDice <= singleton::player().getMonster().getAgility())
	{

		wins++;

	}

	if (thirdDice <= singleton::player().getMonster().getStrength())
	{

		wins++;

	}

	if (fourthDice <= singleton::player().getMonster().getIntelligence())
	{

		wins++;

	}

	if (wins >= 3) 
	{

		return true;

	}

	else
	{

		return false;

	}

}

void ContestMenuScreen::takePrice() const
{

	int dice = rand() % 4;
	string info;

	switch (dice)
	{

	case 0:

		info = "You won 1 gold coin.";
		singleton::player().earnGold(1);
		break;

	case 1:

		info = "You won 1 silver coin.";
		singleton::player().earnSilver(1);
		break;

	case 2:

		info = "You won 2 silver coins.";
		singleton::player().earnSilver(2);
		break;

	case 3:

		info = "You won 3 silver coins.";
		singleton::player().earnSilver(3);
		break;

	default:


		info = "You won 1 silver coin.";
		singleton::player().earnSilver(1);
		break;

	}


	Message message;
	message.popup(info);

}

void ContestMenuScreen::gainSkill() const
{

	string monsterName = singleton::player().getMonster().getName();

	int dice = rand() % 3;
	string info;

	switch (dice)
	{

	case 0:

		info = monsterName + " gained + 1 agility-";
		singleton::player().getMonster().gainAgility(1);
		break;

	case 1:

		info = monsterName + " gained + 1 intelligence.";
		singleton::player().getMonster().gainIntelligence(1);
		break;

	case 2:

		info = monsterName + " gained + 1 strength.";
		singleton::player().getMonster().gainStrength(1);
		break;

	default:

		info = monsterName + " gained + 1 agility.";
		singleton::player().getMonster().gainAgility(1);
		break;

	}

	Message message;
	message.popup(info);

}