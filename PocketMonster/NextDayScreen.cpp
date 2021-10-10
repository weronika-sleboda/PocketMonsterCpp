#include "NextDayScreen.h"
#include "Message.h"
#include "PlayerSingleton.h"
#include <string>
#include "GameOverScreen.h"

typedef PlayerSingleton singleton;

using namespace std;

void NextDayScreen::display() const
{

	if (singleton::player().getMonster().getHunger() == 10)
	{

		GameOverScreen screen;
		screen.display();

	}

	else 
	{
	
		string monsterName = singleton::player().getMonster().getName();

		Message hungerMessage;
		hungerMessage.popup(monsterName + "'s hunger has been raised by + 1.");

		singleton::player().getMonster().gainHunger(1);

		//>>> Can participate in contests again

		singleton::player().letMonsterRest();

		Message restMessage;
		restMessage.popup
		(

			monsterName + " has rested and can participate in today's constests."

		);

	}

}