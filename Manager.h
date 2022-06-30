#ifndef MANAGER_H
#define MANAGER_H
#pragma once

#include "Creature.h"
#include <memory>
#include <list>
#include <deque>
#include <deque>
#include <exception>
extern sf::RenderWindow window;



class Manager
{
private:
	std::deque <Creature*> list;
public:
	void update(float _time);
	void add(Creature*);
	void display(void);
};


#endif // MANAGER_H