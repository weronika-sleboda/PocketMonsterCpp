#include "Controller.h"
#include "StarterScreen.h"
#include <iostream>
#include "ErrorScreen.h"

using namespace std;

void Controller::run(Screen& screen) const 
{

	screen.display();

	int input;
	cin >> input;

	if (input <= numberOfOptions && input >= 1) 
	{

		navigate(input);

	}

	else 
	{

		ErrorScreen errorScreen;
		errorScreen.setErrorType(ErrorType::WRONG_INPUT);
		errorScreen.display();

	}

}

void Controller::setNumberOfOptions(int availableOptions) 
{

	numberOfOptions = availableOptions;

}
