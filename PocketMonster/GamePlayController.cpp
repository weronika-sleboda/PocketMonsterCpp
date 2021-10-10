#include "GamePlayController.h"
#include <iostream>
#include "GoodByeScreen.h"
#include "MonsterProfileScreen.h"
#include "PlayerProfileScreen.h"
#include "ContinueNavigator.h"
#include "GamePlayScreen.h"
#include "FeedScreen.h"
#include "FeedMenuController.h"
#include "PlaygroundIndieController.h"
#include "TrainingScreen.h"
#include "ContestMenuScreen.h"
#include "ShopScreen.h"
#include "ShopMenuController.h"
#include "NextDayScreen.h"
#include "SaveFileScreen.h"


using namespace std;

enum class GamePlayOptions
{

	MONSTER_PROFILE = 1,
	PLAYER_PROFILE,
	FEED_MONSTER,
	PLAY_WITH_MONSTER,
	TRAIN_MONSTER,
	CONTEST,
	SHOP,
	NEXT_DAY,
	SAVE,
	QUIT

};

GamePlayController::GamePlayController()
{

	setNumberOfOptions(10);

}

void GamePlayController::navigate(int& input) const
{

	switch (static_cast<GamePlayOptions>(input))
	{

	case GamePlayOptions::MONSTER_PROFILE:

		displayMonsterProfile();
		break;

	case GamePlayOptions::PLAYER_PROFILE:

		displayPlayerProfile();
		break;

	case GamePlayOptions::FEED_MONSTER:

		feedMonster();
		break;

	case GamePlayOptions::PLAY_WITH_MONSTER:

		playWithMonster();
		break;

	case GamePlayOptions::TRAIN_MONSTER:

		trainMonster();
		break;

	case GamePlayOptions::CONTEST:

		participateInContest();
		break;

	case GamePlayOptions::SHOP:

		enterShop();
		break;

	case GamePlayOptions::NEXT_DAY:

		nextDay();
		break;

	case GamePlayOptions::SAVE:

		save();
		break;

	case GamePlayOptions::QUIT:

		quitGame();
		break;

	}

}

void GamePlayController::displayMonsterProfile() const
{

	MonsterProfileScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}


void GamePlayController::displayPlayerProfile() const
{

	PlayerProfileScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}

void GamePlayController::feedMonster() const 
{

	FeedScreen screen;
	FeedMenuController controller;
	controller.run(screen);
	goBackToGamePlayMenu();

}

void GamePlayController::playWithMonster() const
{

	PlaygroundIndieController controller;
	controller.run();
	goBackToGamePlayMenu();

}

void GamePlayController::trainMonster() const
{

	TrainingScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}

void GamePlayController::participateInContest() const
{

	ContestMenuScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}

void GamePlayController::enterShop() const 
{

	ShopScreen screen;
	ShopMenuController controller;
	controller.run(screen);

}

void GamePlayController::nextDay() const
{

	NextDayScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}

void GamePlayController::save() const
{

	SaveFileScreen screen;
	screen.display();
	goBackToGamePlayMenu();

}

void GamePlayController::quitGame() const
{

	GoodByeScreen screen;
	screen.display();

}

void GamePlayController::goBackToGamePlayMenu() const
{

	GamePlayScreen screen;
	GamePlayController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);
	
}
