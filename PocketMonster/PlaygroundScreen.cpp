#include "PlaygroundScreen.h"
#include "Message.h"
#include "PlayerSingleton.h"
#include <string>

typedef PlayerSingleton singleton;

using namespace std;

void PlaygroundScreen::display() const
{

	string monsterName = singleton::player().getMonster().getName();

	Message message;
	message.popup(monsterName + "'s mood has been raised by + 1.");

}