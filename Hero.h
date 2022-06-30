#pragma once
#include "Creature.h"
class Hero : public Creature
{
public:
	Hero(int __x, int __y, int __width, int __height, int __hp) : Creature(__x, __y, __width, __height, __hp) {};
	void get_command(float time) override;
	void move(void) override;
	void dammage(void);
};

