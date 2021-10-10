#ifndef EYE_MENU_CONTROLLER_H
#define EYE_MENU_CONTROLLER_H

#include "Controller.h"

class EyeMenuController : public Controller
{

public:

	EyeMenuController();

private:

	void navigate(int& input) const override;
	void changeColorToBlue() const;
	void changeColorToBrown() const;
	void changeColorToRed() const;
	void changeColorToPurple() const;
	void navigateToCreatorMenu() const;
	void pressOneToContinue() const;
};

#endif