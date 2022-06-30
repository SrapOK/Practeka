#ifndef CREATURE_H
#define CREATURE_H
#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Map.h"


extern sf::RenderWindow window;
extern Map mapee;

class Creature
{
protected:
	std::string _name;
	int _x, _y;
	float _dx, _dy;
	float _speed;

	int _width, _height;
	sf::Sprite _sprite;
	std::map<std::string, Animation*> animations;

public:
	Creature(int __x, int __y, int __width, int __height);
	void add_animation(Animation*);
	int x(void) const;
	int y(void) const;
	float dx(void) const;
	float dy(void) const;
	int width(void) const;
	int height(void) const;
	const sf::Sprite& sprite(void) const;
	void set_default_sprite(std::string __path);
	void set_default_sprite(Animation& __Anim_part);
	void set_default_sprite(sf::Texture& __Texture_part);
	void get_command(float);
//	int grtVector2f();
	//virtual void update(float) = 0;
};

#endif // !CREATURE_H

