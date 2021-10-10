#ifndef BREED_MENU_CONTROLLER_H
#define BREED_MENU_CONTROLLER_H

#include "Controller.h"

class BreedMenuController : public Controller
{

public:

	BreedMenuController();

private:

	void navigate(int& input) const override;
	void createSnaky() const;
	void createDino() const;
	void createFurball() const;
	void navigateToCreatorMenu() const;
	void pressOneToContinue() const;

};

#endif