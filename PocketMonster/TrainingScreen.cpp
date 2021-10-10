#include "TrainingScreen.h"
#include "Message.h"
#include "PlayerSingleton.h"
#include <string>

typedef PlayerSingleton singleton;

using namespace std;

void TrainingScreen::display() const
{

	int counter{ 10 };

	string monsterName = singleton::player().getMonster().getName();
	
	if (singleton::player().getMonster().getMood() > 5)
	{

		counter--;

		Message progressMessage;
		progressMessage.popup
		(
			monsterName + " has " + to_string(counter) + " points left to "
			"complete they training course."

		);

		if (counter == 0)
		{

			Message successMessage;
			successMessage.popup
			(

				monsterName + " completed their training course and "
				"gained + 1 intelligence."

			);

			singleton::player().getMonster().gainIntelligence(1);

		}

	}

	else
	{

		Message errorMessage;
		errorMessage.popup
		(

			monsterName + " is not in a mood for the training."

		);

	}

}