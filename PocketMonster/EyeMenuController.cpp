#include "EyeMenuController.h"
#include <string>
#include "Message.h"
#include "MonsterCreatorController.h"
#include "MonsterCreatorScreen.h"
#include "ContinueNavigator.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

enum class EyeMenuOptions
{

	BLUE = 1,
	BROWN,
	RED,
	PURPLE,
	QUIT

};

EyeMenuController::EyeMenuController()
{

	setNumberOfOptions(5);

}	

void EyeMenuController::navigate(int& input) const
{

	switch (static_cast<EyeMenuOptions>(input))
	{

	case EyeMenuOptions::BLUE:

		changeColorToBlue();
		pressOneToContinue();
		break;

	case EyeMenuOptions::BROWN:

		changeColorToBrown();
		pressOneToContinue();
		break;

	case EyeMenuOptions::RED:

		changeColorToRed();
		pressOneToContinue();
		break;

	case EyeMenuOptions::PURPLE:

		changeColorToPurple();
		pressOneToContinue();
		break;

	case EyeMenuOptions::QUIT:

		navigateToCreatorMenu();
		break;
	}
}


void EyeMenuController::changeColorToBlue() const
{

	singleton::player().getMonster().setEyeColor("Blue");
	singleton::player().getMonster().eyeColorIsChanged(true);
	Message message;
	message.popup("Eye color has been changed to blue.");

}

void EyeMenuController::changeColorToBrown() const
{

	singleton::player().getMonster().setEyeColor("Brown");
	singleton::player().getMonster().eyeColorIsChanged(true);
	Message message;
	message.popup("Eye color has been changed to brown.");

}

void EyeMenuController::changeColorToRed() const
{

	singleton::player().getMonster().setEyeColor("Red");
	singleton::player().getMonster().eyeColorIsChanged(true);
	Message message;
	message.popup("Eye color has been changed to red.");

}

void EyeMenuController::changeColorToPurple() const 
{

	singleton::player().getMonster().setEyeColor("Purple");
	singleton::player().getMonster().eyeColorIsChanged(true);
	Message message;
	message.popup("Eye color has been changed to purple.");
}

void EyeMenuController::navigateToCreatorMenu() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	controller.run(screen);

}

void EyeMenuController::pressOneToContinue() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}