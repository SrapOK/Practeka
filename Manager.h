#pragma once
#ifndef MANAGER_H
#define MANAGER_H
#include "Creature.h"
#include "Header.h"






class Manager
{
private:
public:
	void print(void);
	std::list <Creature*> list;
};


#endif // !MANAGER_H
