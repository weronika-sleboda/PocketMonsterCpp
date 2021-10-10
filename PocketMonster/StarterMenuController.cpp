#include "StarterMenuController.h"
#include "StarterScreen.h"
#include <iostream>
#include "MonsterCreatorController.h"
#include "MonsterCreatorScreen.h"
#include "GoodByeScreen.h"
#include "LoadFileScreen.h"

using namespace std;

enum class StarterOptions 
{

	PLAY = 1,
	LOAD,
	QUIT

};

StarterMenuController::StarterMenuController()
{

	setNumberOfOptions(3);

}

void StarterMenuController::navigate(int& input) const 
{

	switch (static_cast<StarterOptions>(input)) 
	{

	case StarterOptions::PLAY:

		navigateToCreatorScreen();
		break;

	case StarterOptions::LOAD:

		navigateToLoadScreen();
		break;


	case StarterOptions::QUIT:

		navigateToQuitScreen();
		break;

	}

}

void StarterMenuController::navigateToCreatorScreen() const 
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	controller.run(screen);

}

void StarterMenuController::navigateToLoadScreen() const
{

	LoadFileScreen screen;
	screen.display();

}

void StarterMenuController::navigateToQuitScreen() const
{

	GoodByeScreen screen;
	screen.display();

}