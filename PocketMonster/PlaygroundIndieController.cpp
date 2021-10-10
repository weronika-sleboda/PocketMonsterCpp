#include "PlaygroundIndieController.h"
#include "PlayerSingleton.h"
#include "PlaygroundScreen.h"
#include "Message.h"
#include <string>

typedef PlayerSingleton singleton;

using namespace std;

void PlaygroundIndieController::run() const
{

	string monsterName = singleton::player().getMonster().getName();
	singleton::player().getMonster().gainMood(1);

	PlaygroundScreen screen;
	screen.display();

	static int counter{ 0 };
	counter++;

	if (counter == 10)
	{

		counter = 0;

		singleton::player().getMonster().gainAgility(1);

		Message message;
		message.popup(monsterName + " gained + 1 agility.");

	}

}