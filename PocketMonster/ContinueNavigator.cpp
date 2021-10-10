#include "ContinueNavigator.h"
#include "Message.h"
#include <iostream>
#include "Controller.h"

void ContinueNavigator::run
(

	Screen& screen,
	Controller& controller

) const
{

	Message message;
	message.popup("Press 1 to continue");

	int input;
	std::cin >> input;

	if (input == 1) 
	{

		controller.run(screen);

	}
}