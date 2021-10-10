#ifndef GAME_PLAY_CONTROLLER_H
#define GAME_PLAY_CONTROLLER_H

#include "Controller.h"

class GamePlayController : public Controller
{

public:

	GamePlayController();

private:

	void navigate(int& input) const override;
	void displayMonsterProfile() const;
	void displayPlayerProfile() const;
	void feedMonster() const;
	void playWithMonster() const;
	void trainMonster() const;
	void participateInContest() const;
	void enterShop() const;
	void nextDay() const;
	void save() const;
	void quitGame() const;
	void goBackToGamePlayMenu() const;

};

#endif