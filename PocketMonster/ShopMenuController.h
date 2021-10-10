#ifndef SHOP_MENU_CONTROLLER_H
#define SHOP_MENU_CONTROLLER_H

#include "Controller.h"

class ShopMenuController : public Controller
{

public:

	ShopMenuController();

private:

	void navigate(int& input) const override;
	void buyStrawberry() const;
	void buyBlueberry() const;
	void buyCherry() const;
	void buyBanana() const;
	void buyApple() const;
	void buyMelon() const;
	void buyWalnut() const;
	void quitToGameplayMenu() const;
	void goBackToShopMenu() const;

};

#endif