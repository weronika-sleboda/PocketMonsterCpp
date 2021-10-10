#include "MonsterCreatorScreen.h"
#include <iostream>
#include <string>

using namespace std;

void MonsterCreatorScreen::display() const 
{

	cout << "-------------------------------\n";
	cout << "\t Create monster\n";
	cout << "-------------------------------\n";
	cout << "\t Choose option:\n\n";
	cout << "1. Change breed \n";
	cout << "2. Change name \n";
	cout << "3. Change skin color \n";
	cout << "4. Change eye color\n";
	cout << "5. Continue\n";
	cout << "6. QUIT\n";

}