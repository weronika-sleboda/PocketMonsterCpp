#include "Message.h"
#include <iostream>

void Message::popup(std::string message) const 
{

	std::cout << "\n>>> " << message << " <<<\n";

}