#include "ShopScreen.h"
#include <iostream>
#include "PlayerSingleton.h"

typedef PlayerSingleton singleton;

using namespace std;

void ShopScreen::display() const
{

	cout << "-------------------------------\n";
	cout << " Choose item you want to buy\n";
	cout << "-------------------------------\n";

	singleton::player().itemsInfo();

	cout << "8. QUIT\n\n";

}