#include "SkinMenuController.h"
#include "Message.h"
#include "ContinueNavigator.h"
#include "MonsterCreatorScreen.h"
#include "MonsterCreatorController.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;


enum class SkinMenuOptions
{

	BLACK = 1,
	BROWN,
	WHITE,
	PURPLE,
	RED,
	BLUE,
	QUIT

};

SkinMenuController::SkinMenuController()
{

	setNumberOfOptions(7);

}

void SkinMenuController::navigate(int& input) const
{

	switch (static_cast<SkinMenuOptions>(input))
	{

	case SkinMenuOptions::BLACK:

		changeColorToBlack();
		pressOneToContinue();
		break;

	case SkinMenuOptions::BROWN:
		
		changeColorToBrown();
		pressOneToContinue();
		break;

	case SkinMenuOptions::WHITE:
		
		changeColorToWhite();
		pressOneToContinue();
		break;

	case SkinMenuOptions::PURPLE:
		
		changeColorToPurple();
		pressOneToContinue();
		break;

	case SkinMenuOptions::RED:
		
		changeColorToRed();
		pressOneToContinue();
		break;

	case SkinMenuOptions::BLUE:
		
		changeColorToBlue();
		pressOneToContinue();
		break;

	case SkinMenuOptions::QUIT:

		navigateToCreatorMenu();
		break;

	}
}

void SkinMenuController::changeColorToBlack() const
{

	singleton::player().getMonster().setSkinColor("Black");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to black.");

}

void SkinMenuController::changeColorToBrown() const
{

	singleton::player().getMonster().setSkinColor("Brown");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to brown.");

}

void SkinMenuController::changeColorToWhite() const
{

	singleton::player().getMonster().setSkinColor("White");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to white.");

}

void SkinMenuController::changeColorToPurple() const
{

	singleton::player().getMonster().setSkinColor("Purple");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to purple.");

}

void SkinMenuController::changeColorToRed() const
{

	singleton::player().getMonster().setSkinColor("Red");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to red.");

}

void SkinMenuController::changeColorToBlue() const
{

	singleton::player().getMonster().setSkinColor("Blue");
	singleton::player().getMonster().skinColorIsChanged(true);
	Message message;
	message.popup("Skin color has been changed to blue.");

}

void SkinMenuController::navigateToCreatorMenu() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	controller.run(screen);

}

void SkinMenuController::pressOneToContinue() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}