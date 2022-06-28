#ifndef CREATURE_H
#define CREATURE_H
#pragma once

#include <string>
#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

extern sf::RenderWindow window;

class Creature
{
protected:
	sf::Sprite _sprite;
	std::string _name;
	std::string _path;
	int _x, _y;
	double _dx, _dy;
	int _width, _height;
	short _current_frame;
public:
	Creature(std::string __path, int __x, int __y, int __width, int __height);
	int x(void);
	int y(void);
	double dx(void);
	double dy(void);
	int width(void);
	int height(void);
	const sf::Sprite& sprite(void);
	void update(float);
};

#endif // !CREATURE_H

