#include "MonsterIndieController.h"
#include "MonsterProfileScreen.h"
#include <iostream>
#include "Message.h"
#include "ErrorScreen.h"
#include "GamePlayScreen.h"
#include "GamePlayController.h"
#include "MonsterCreatorScreen.h"
#include "MonsterCreatorController.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void MonsterIndieController::run() const
{

	MonsterProfileScreen screen;
	screen.display();

	Message message;
	message.popup("Press 1 to accept or 2 to decline.");
	
	int input;
	cin >> input;

	if (input == 1) 
	{

		navigateToGamePlayMenu();

	}

	else if (input == 2) {

		singleton::player().resetMonsterProfile();
		navigateToMonsterCreator();

	}

	else {

		ErrorScreen errorScreen;
		errorScreen.setErrorType(ErrorType::WRONG_INPUT);
		errorScreen.display();

	}
}

void MonsterIndieController::navigateToMonsterCreator() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	controller.run(screen);

}

void MonsterIndieController::navigateToGamePlayMenu() const
{

	GamePlayScreen gamePlayScreen;
	GamePlayController controller;
	controller.run(gamePlayScreen);

}
