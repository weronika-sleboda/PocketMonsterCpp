#ifndef MONSTER_CREATOR_CONTROLLER_H
#define MONSTER_CREATOR_CONTROLLER_H

#include "Controller.h"

class MonsterCreatorController : public Controller
{

public:

	MonsterCreatorController();

private:

	void navigate(int& input) const override;
	void navigateToBreedMenu() const;
	void navigateToNameMenu() const;
	void navigateToSkinMenu() const;
	void navigateToEyeMenu() const;
	void acceptAndContinue() const;
	void navigateToStarterMenu() const;
	void profileNotDone() const;

};

#endif