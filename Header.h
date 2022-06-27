#pragma once
#ifndef HEADER_H

#include <string>
#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Creature.h"
#include "Manager.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
Manager manager;
#endif // HEADER_H