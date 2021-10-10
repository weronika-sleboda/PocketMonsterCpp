#include "PlayerProfileScreen.h"
#include <iostream>
#include "Monster.h"
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void PlayerProfileScreen::display() const 
{

	cout << "-------------------------------\n";
	cout << "\t Player profile\n";
	cout << "-------------------------------\n";
	cout << "Owned monster: " << singleton::player().getMonster().getName();
	cout << "\nGold: " << to_string(singleton::player().getGold()) << "\n";
	cout << "Silver: " << to_string(singleton::player().getSilver()) << "\n";
	cout << "Won contests: " << to_string(singleton::player().getWonContests());
	cout << "\n\n";

}