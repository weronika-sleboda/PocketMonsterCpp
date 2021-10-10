#include "Game.h"
#include "StarterScreen.h"
#include "StarterMenuController.h"

void Game::run() const
{

	StarterScreen screen;
	StarterMenuController controller;
	controller.run(screen);

}