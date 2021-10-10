#include "BreedMenuController.h"
#include <iostream>
#include "Snaky.h"
#include "Dino.h"
#include "Furball.h"
#include "Message.h"
#include "MonsterCreatorController.h"
#include "MonsterCreatorScreen.h"
#include "ContinueNavigator.h"
#include "PlayerSingleton.h"
#include "Monster.h"


typedef PlayerSingleton singleton;

using namespace std;

enum class BreedMenuOptions 
{

	SNAKY = 1,
	DINO,
	FURBALL,
	QUIT

};

BreedMenuController::BreedMenuController()
{

	setNumberOfOptions(4);

}

void BreedMenuController::navigate(int& input) const
{

	switch (static_cast<BreedMenuOptions>(input)) 
	{

	case BreedMenuOptions::SNAKY :

		createSnaky();
		pressOneToContinue();
		break;

	case BreedMenuOptions::DINO:

		createDino();
		pressOneToContinue();
		break;

	case BreedMenuOptions::FURBALL:

		createFurball();
		pressOneToContinue();
		break;

	case BreedMenuOptions::QUIT:

		navigateToCreatorMenu();
		break;
	}

}

void BreedMenuController::createSnaky() const 
{

	//***[IMPORTANT] Monster dynamically allocated ***//

	Snaky* snaky = new Snaky;
	singleton::player().setMonster(snaky);
	singleton::player().getMonster().breedIsChanged(true);
	
	Message message;
	message.popup("Snaky has been created");

}

void BreedMenuController::createDino() const
{

	//***[IMPORTANT] Monster dynamically allocated ***//

	Dino* dino = new Dino;
	singleton::player().setMonster(dino);
	singleton::player().getMonster().breedIsChanged(true);

	Message message;
	message.popup("Dino has been created");

}

void BreedMenuController::createFurball() const
{

	//***[IMPORTANT] Monster dynamically allocated ***//

	Furball* furball = new Furball;
	singleton::player().setMonster(furball);
	singleton::player().getMonster().breedIsChanged(true);

	Message message;
	message.popup("Furball has been created");

}

void BreedMenuController::navigateToCreatorMenu() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	controller.run(screen);

}

void BreedMenuController::pressOneToContinue() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}
