#ifndef CONTEST_MENU_SCREEN_H
#define CONTEST_MENU_SCREEN_H

#include "Screen.h"

class ContestMenuScreen : public Screen
{

public:

	void display() const override;

private:

	bool won() const;
	void takePrice() const;
	void gainSkill() const;

};

#endif