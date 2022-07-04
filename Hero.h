#pragma once
#include "Creature.h"
#include "View.h"
#include "interface.h"
#include "Manager.h"
#include <sstream>



class Hero : public Creature
{
	float _pdx = 1;
	int _x;
	int _y;
	int _score;
public:
	Hero(int __x, int __y, int __width, int __height);
	void get_command(float time) override;
	void damage(void);
	void move(void) override;
	//void pdx(void);
	int get_x();
	int get_y();
};

