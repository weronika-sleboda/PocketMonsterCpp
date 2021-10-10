#include "NameIndieController.h"
#include <iostream>
#include <string>
#include "NameScreen.h"
#include "Message.h"
#include "MonsterCreatorScreen.h"
#include "MonsterCreatorController.h"
#include "ContinueNavigator.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void NameIndieController::run() const 
{

	NameScreen screen;
	screen.display();

	string input;
	cin >> input;

	singleton::player().getMonster().setName(input);
	singleton::player().getMonster().nameIsChanged(true);

	Message message;
	message.popup("The name has been changed.");

	pressOneToContinue();

}

void NameIndieController::pressOneToContinue() const
{

	MonsterCreatorScreen screen;
	MonsterCreatorController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}