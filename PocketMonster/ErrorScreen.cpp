#include "ErrorScreen.h"
#include <string>
#include <iostream>

using namespace std;

void ErrorScreen::display() const 
{

	string error;

	switch (errorType) 
	{

	case ErrorType::WRONG_INPUT :

		error = "\n[ERROR] Wrong input! Please enter\n"
				"the number from menu options.\n\n";
		break;

	case ErrorType::PROFILE_NOT_DONE :

		error = "\n[MESSAGE] Monster profile is not complete.\n"
				"Please, follow the instructions below.\n\n";
		break;

	default:

		error = "\n[ERROR] Undefined error.\n\n";
		break;

	}

	cout << error;

}

void ErrorScreen::setErrorType(ErrorType occurrentError) 
{

	errorType = occurrentError;

}