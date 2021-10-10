#ifndef FEED_MENU_CONTROLLER_H
#define FEED_MENU_CONTROLLER_H

#include "Controller.h"

class FeedMenuController : public Controller
{

public:

	FeedMenuController();

private:

	void navigate(int& input) const override;
	void feedMonster(int index) const;

};

#endif