#include "ShopMenuController.h"
#include <iostream>
#include "Message.h"
#include "PlayerSingleton.h"
#include "GamePlayScreen.h"
#include "GamePlayController.h"
#include "ContinueNavigator.h"
#include "ShopScreen.h"

typedef PlayerSingleton singleton;

enum class ShopMenuOptions
{

	BUY_STRAWBERRY = 1,
	BUY_BLUEBERRY,
	BUY_CHERRY,
	BUY_BANANA,
	BUY_APPLE,
	BUY_MELON,
	BUY_WALNUT,
	QUIT

};


ShopMenuController::ShopMenuController()
{

	setNumberOfOptions(8);

}

void ShopMenuController::navigate(int& input) const
{

	switch (static_cast<ShopMenuOptions>(input))
	{

	case ShopMenuOptions::BUY_STRAWBERRY:

		buyStrawberry();
		break;

	case ShopMenuOptions::BUY_BLUEBERRY:

		buyBlueberry();
		break;

	case ShopMenuOptions::BUY_CHERRY:

		buyCherry();
		break;

	case ShopMenuOptions::BUY_BANANA:

		buyBanana();
		break;

	case ShopMenuOptions::BUY_APPLE:

		buyApple();
		break;

	case ShopMenuOptions::BUY_MELON:

		buyMelon();
		break;

	case ShopMenuOptions::BUY_WALNUT:

		buyWalnut();
		break;

	case ShopMenuOptions::QUIT:

		quitToGameplayMenu();
		break;

	}

}

void ShopMenuController::buyStrawberry() const
{

	unsigned int gold{ singleton::player().getItem(0).getGold() };
	unsigned int silver{ singleton::player().getItem(0).getSilver() };
	
	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(0).add(1);

		Message message;
		message.popup("You bought + 1 strawberry.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyBlueberry() const
{

	unsigned int gold{ singleton::player().getItem(1).getGold() };
	unsigned int silver{ singleton::player().getItem(1).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(1).add(1);

		Message message;
		message.popup("You bought + 1 blueberry.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyCherry() const
{

	unsigned int gold{ singleton::player().getItem(2).getGold() };
	unsigned int silver{ singleton::player().getItem(2).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(2).add(1);

		Message message;
		message.popup("You bought + 1 cherry.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyBanana() const
{

	unsigned int gold{ singleton::player().getItem(3).getGold() };
	unsigned int silver{ singleton::player().getItem(3).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(3).add(1);

		Message message;
		message.popup("You bought + 1 banana.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyApple() const
{

	unsigned int gold{ singleton::player().getItem(4).getGold() };
	unsigned int silver{ singleton::player().getItem(4).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(4).add(1);

		Message message;
		message.popup("You bought + 1 apple.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyMelon() const
{

	unsigned int gold{ singleton::player().getItem(5).getGold() };
	unsigned int silver{ singleton::player().getItem(5).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(5).add(1);

		Message message;
		message.popup("You bought + 1 melon.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::buyWalnut() const
{

	unsigned int gold{ singleton::player().getItem(6).getGold() };
	unsigned int silver{ singleton::player().getItem(6).getSilver() };

	singleton::player().buy(gold, silver);


	if (singleton::player().isAbleToBuy()) {

		singleton::player().getItem(6).add(1);

		Message message;
		message.popup("You bought + 1 walnut.");

	}

	else
	{

		Message message;
		message.popup("You don't have enough money.");

	}

	goBackToShopMenu();

}

void ShopMenuController::quitToGameplayMenu() const
{

	GamePlayScreen screen;
	GamePlayController controller;
	controller.run(screen);

}

void ShopMenuController::goBackToShopMenu() const
{

	ShopScreen screen;
	ShopMenuController controller;
	ContinueNavigator navigator;
	navigator.run(screen, controller);

}
