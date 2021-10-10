#ifndef SKIN_MENU_CONTROLLER_H
#define SKIN_MENU_CONTROLLER_H

#include "Controller.h"

class SkinMenuController : public Controller
{

public:

	SkinMenuController();

private:

	void navigate(int& input) const override;
	void changeColorToBlack() const;
	void changeColorToBrown() const;
	void changeColorToWhite() const;
	void changeColorToPurple() const;
	void changeColorToRed() const;
	void changeColorToBlue() const;
	void navigateToCreatorMenu() const;
	void pressOneToContinue() const;

};

#endif