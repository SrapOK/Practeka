#pragma once
#include "Creature.h"
class Enemy : public Creature
{
protected:
	int direction = 1;
public:
	Enemy(int __x, int __y, int __width, int __height);
	void get_command(float time) override;
	void move(void) override;
	virtual ~Enemy() {};
	int getPositionX(void);
	int getPositionY(void);
};

