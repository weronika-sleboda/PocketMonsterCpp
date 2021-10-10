#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Screen.h"

class Controller 
{

public:

	virtual void run(Screen& screen) const;
	void setNumberOfOptions(int availableOptions);

private:

	virtual void navigate(int& input) const = 0;

	int numberOfOptions = 0;

};

#endif