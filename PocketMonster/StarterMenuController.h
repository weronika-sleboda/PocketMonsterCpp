#ifndef STARTER_MENU_CONTROLLER_H
#define STARTER_MENU_CONTROLLER_H

#include "Controller.h"

class StarterMenuController : public Controller
{

public:

	StarterMenuController();

private:

	void navigate(int& input) const override;
	void navigateToCreatorScreen() const;
	void navigateToLoadScreen() const;
	void navigateToQuitScreen() const;
};

#endif