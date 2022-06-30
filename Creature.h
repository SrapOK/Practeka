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
	bool up_is_pressed;
	void collision_x();
	void collision_y();
	std::string _name;
	float _dx, _dy;
	float _speed;
	sf::FloatRect box;

	int _width, _height;
	sf::Sprite _sprite;
	std::map<std::string, Animation*> animations;
	bool on_ground;

public:
	Creature(int __x, int __y, int __width, int __height);
	void add_animation(Animation*);
	float& x(void);
	float& y(void);
	float dx(void) const;
	float dy(void) const;
	float& width(void);
	float& height(void);
	const sf::Sprite& sprite(void) const;
	void set_default_sprite(std::string __path);
	void set_default_sprite(Animation& __Anim_part);
	void set_default_sprite(sf::Texture& __Texture_part);
	void get_command(float);
	void move(void);
	//	int grtVector2f();
		//virtual void update(float) = 0;
};

#endif // !CREATURE_H

