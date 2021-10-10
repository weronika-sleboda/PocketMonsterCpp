#include "MonsterCreatorController.h"
#include "MonsterCreatorScreen.h"
#include <iostream>
#include "StarterMenuController.h"
#include "StarterScreen.h"
#include "BreedScreen.h"
#include "BreedMenuController.h"
#include "NameIndieController.h"
#include "EyeMenuController.h"
#include "EyeScreen.h"
#include "SkinScreen.h"
#include "SkinMenuController.h"
#include "MonsterIndieController.h"
#include "Monster.h"
#include "ContinueNavigator.h"
#include "Message.h"
#include "ErrorScreen.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;


using namespace std;

enum class CreatorOptions 
{

	CHANGE_BREED = 1,
	CHANGE_NAME,
	CHANGE_SKIN_COLOR,
	CHANGE_EYE_COLOR,
	CONTINUE,
	QUIT

};


MonsterCreatorController::MonsterCreatorController()
{

	setNumberOfOptions(6);

}

void MonsterCreatorController::navigate(int& input) const 
{

	switch (static_cast<CreatorOptions>(input)) 
	{

	case CreatorOptions::CHANGE_BREED:

		navigateToBreedMenu();
		break;

	case CreatorOptions::CHANGE_NAME:

		navigateToNameMenu();
		break;

	case CreatorOptions::CHANGE_SKIN_COLOR:

		navigateToSkinMenu();
		break;

	case CreatorOptions::CHANGE_EYE_COLOR:

		navigateToEyeMenu();
		break;

	case CreatorOptions::CONTINUE:

		acceptAndContinue();
		break;

	case CreatorOptions::QUIT:

		navigateToStarterMenu();
		break;

	default:

		MonsterCreatorScreen screen;
		run(screen);
		break;

	}

}

void MonsterCreatorController::navigateToBreedMenu() const
{

	BreedScreen screen;
	BreedMenuController controller;
	controller.run(screen);

}

void MonsterCreatorController::navigateToNameMenu() const
{

	NameIndieController controller;
	controller.run();
}

void MonsterCreatorController::navigateToSkinMenu() const 
{

	SkinScreen screen;
	SkinMenuController controller;
	controller.run(screen);

}

void MonsterCreatorController::navigateToEyeMenu() const
{

	EyeScreen screen;
	EyeMenuController controller;
	controller.run(screen);

}

void MonsterCreatorController::acceptAndContinue() const
{

	bool breedChanged = singleton::player().getMonster().breedIsChanged();
	bool nameChanged = singleton::player().getMonster().nameIsChanged();
	bool skinChanged = singleton::player().getMonster().skinColorIsChanged();
	bool eyeChanged = singleton::player().getMonster().eyeColorIsChanged();

	if (breedChanged && nameChanged && skinChanged && eyeChanged)
	{

		MonsterIndieController controller;
		controller.run();

	}

	else 
	{

		profileNotDone();

	}
	

}

void MonsterCreatorController::navigateToStarterMenu() const
{

	//>>> Reset monster profile
	
	singleton::player().resetMonsterProfile();

	//>>> Navigate to starter menu

	StarterScreen screen;
	StarterMenuController controller;
	controller.run(screen);

}

void MonsterCreatorController::profileNotDone() const
{

	bool breedChanged = singleton::player().getMonster().breedIsChanged();
	bool nameChanged = singleton::player().getMonster().nameIsChanged();
	bool skinChanged = singleton::player().getMonster().skinColorIsChanged();
	bool eyeChanged = singleton::player().getMonster().eyeColorIsChanged();

	ErrorScreen errorScreen;
	errorScreen.setErrorType(ErrorType::PROFILE_NOT_DONE);

	if (!breedChanged)
	{

		Message message;
		message.popup("Choose breed");

	}

	if (!nameChanged)
	{

		Message message;
		message.popup("Choose name");

	}

	if (!skinChanged)
	{

		Message message;
		message.popup("Choose skin color");

	}

	if (!eyeChanged)
	{

		Message message;
		message.popup("Choose eye color");

	}

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);
	
}