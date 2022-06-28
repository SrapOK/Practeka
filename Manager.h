#ifndef MANAGER_H
#define MANAGER_H
#pragma once

#include "Creature.h"
#include <memory>
extern sf::RenderWindow window;


template<typename T>
class Manager
{
private:
	std::list <std::unique_ptr<T>> list;
public:
	void add(T&);
	void drow(void);
};

#endif // MANAGER_H