#pragma once
#include "Creature.h"
#include "View.h"
#include "interface.h"
#include <sstream>
class Hero : public Creature
{
	int _pdx = 1;
public:
	Hero(int __x, int __y, int __width, int __height);
	void get_command(float time) override;
	void move(void) override;
	void dammage(void);
	//void pdx(void);
};

