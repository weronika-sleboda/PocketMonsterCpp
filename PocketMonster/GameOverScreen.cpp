#include "GameOverScreen.h"
#include <iostream>
#include "PlayerSingleton.h"
#include <string>
#include "Message.h"

typedef PlayerSingleton singleton;

using namespace std;

void GameOverScreen::display() const
{

	string monsterName = singleton::player().getMonster().getName();

	Message message;
	message.popup(monsterName + " died out of hunger.");


	cout << "\n*******************************\n\n";
	cout << "\t GAME OVER\n\n";
	cout << "*******************************\n\n";

}