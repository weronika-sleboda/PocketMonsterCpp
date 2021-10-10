#include "FeedScreen.h"
#include <iostream>
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void FeedScreen::display() const 
{

	cout << "-------------------------------\n";
	cout << "\t Choose food\n";
	cout << "-------------------------------\n";

	singleton::player().itemsInfo();

}