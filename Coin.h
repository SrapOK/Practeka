#pragma once
#include "Creature.h"

class Coin : public Creature
{
public:
	Coin(int __x, int __y, int __width, int __height) : Creature(__x, __y, __width, __height) {}
	void get_command(float time) override;
	//void move(void);
	void move(void) override;
	



};

