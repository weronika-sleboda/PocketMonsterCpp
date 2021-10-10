#include "FeedMenuController.h"
#include <iostream>
#include "PlayerSingleton.h"
#include "Message.h"
#include <string>

typedef PlayerSingleton singleton;

using namespace std;

enum class FeedMenuOptions
{

	STRAWBERRY = 1,
	BLUEBERRY,
	CHERRY,
	BANANA,
	APPLE,
	MELON,
	WALNUT

};

FeedMenuController::FeedMenuController()
{

	setNumberOfOptions(7);

}

void FeedMenuController::navigate(int& input) const
{

	switch (static_cast<FeedMenuOptions>(input))
	{

	case FeedMenuOptions::STRAWBERRY:

		feedMonster(0);
		break;

	case FeedMenuOptions::BLUEBERRY:

		feedMonster(1);
		break;

	case FeedMenuOptions::CHERRY:

		feedMonster(2);
		break;

	case FeedMenuOptions::BANANA:

		feedMonster(3);
		break;

	case FeedMenuOptions::APPLE:

		feedMonster(4);
		break;

	case FeedMenuOptions::MELON:

		feedMonster(5);
		break;

	case FeedMenuOptions::WALNUT:

		feedMonster(6);
		break;

	}

}

void FeedMenuController::feedMonster(int index) const
{

	static int counter{ 0 };

	singleton::player().feed(index);

	string monsterName = singleton::player().getMonster().getName();
	string itemName = singleton::player().getItem(index).getName();

	if (singleton::player().isAbleToFeed())
	{

		counter++;

		Message successMessage;
		successMessage.popup(monsterName + " has been fed with " + itemName + ".");

		if (counter == 10)
		{

			counter = 0;

			Message strengthMessage;
			strengthMessage.popup(monsterName + " gained + 1 strength.");

			singleton::player().getMonster().gainStrength(1);

		}

	}

	else {

		Message errorMessage;
		errorMessage.popup("You don't have " + itemName + " in your backpack.");

	}

}