#include "LoadFileScreen.h"
#include "SaveFileConstant.h"
#include "PlayerSingleton.h"
#include "Message.h"
#include <iostream>
#include <fstream>
#include <string>
#include "StarterScreen.h"
#include "StarterMenuController.h"
#include "Message.h"
#include "ContinueNavigator.h"
#include "GamePlayScreen.h"
#include "GamePlayController.h"

typedef PlayerSingleton singleton;

using namespace std;

void LoadFileScreen::display() const
{

	//*** [IMPORTANT] It would be better to use a container to
	// store and load all this data, but for a small program like this
	// it works just fine. It can be improved later.

	unsigned int gold{ 0 };
	unsigned int silver{ 0 };
	unsigned int wonContests{ 0 };
	unsigned int contestPerDay{ 0 };
	string breed{ "" };
	string name{ "" };
	string skinType{ "" };
	string skinColor{ "" };
	string eyeColor{ "" };
	unsigned int hunger{ 0 };
	unsigned int mood{ 0 };
	unsigned int agility{ 0 };
	unsigned int intelligence{ 0 };
	unsigned int strength{ 0 };
	unsigned int experience{ 0 };
	unsigned int strawberry{ 0 };
	unsigned int blueberry{ 0 };
	unsigned int cherry{ 0 };
	unsigned int banana{ 0 };
	unsigned int apple{ 0 };
	unsigned int melon{ 0 };
	unsigned int walnut{ 0 };

	ifstream file{ fileName };
	string data;

	if (!file.is_open())
	{

		Message errorMessage;
		errorMessage.popup("There are no saved files.");

		goBackToStarterScreen();

	}

	else 
	{

		file >> gold;
		file >> silver;
		file >> wonContests;
		file >> contestPerDay;
		file >> breed;
		file >> name;
		file >> skinType;
		file >> skinColor;
		file >> eyeColor;
		file >> hunger;
		file >> mood;
		file >> agility;
		file >> intelligence;
		file >> strength;
		file >> experience;
		file >> strawberry;
		file >> blueberry;
		file >> cherry;
		file >> banana;
		file >> apple;
		file >> melon;
		file >> walnut;

		singleton::player().loadPlayer
		(

			gold,
			silver,
			wonContests,
			contestPerDay,
			breed,
			name,
			skinType,
			skinColor,
			eyeColor,
			hunger,
			mood,
			agility,
			intelligence,
			strength,
			experience,
			strawberry,
			blueberry,
			cherry,
			banana,
			apple,
			melon,
			walnut

		);

		goToGamePlay();

	}

}

void LoadFileScreen::goBackToStarterScreen() const
{

	StarterScreen screen;
	StarterMenuController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}

void LoadFileScreen::goToGamePlay() const
{

	GamePlayScreen screen;
	GamePlayController controller;
	controller.run(screen);

}