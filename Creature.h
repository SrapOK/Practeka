#ifndef CREATURE_H
#define CREATURE_H
#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Map.h"
#include "Menu.h"

extern sf::RenderWindow window;
extern Map mapee;
extern Map mapee2;

class Creature
{
protected:
	bool _alive;
	bool _up_is_pressed;
	bool _on_ground;
	bool collision_x(int _mapN);
	bool collision_y(int _mapN);
	//void collision_obj();
	std::string _name;
	float _dx, _dy;
	float _speed;
	sf::FloatRect box;

	int _width, _height, _hp;
	sf::Sprite _sprite;
	std::map<std::string, Animation*> animations;
	

public:
	Creature(int __x, int __y, int __width, int __height);
	void add_animation(Animation*);
	float& x(void);
	float& y(void);
	virtual void damage(void);
	
	bool alive(void);
	float dx(void) const;
	float dy(void) const;
	float& width(void);
	float& height(void);
	int hp(void);
	void kill(void);
	const sf::Sprite& sprite(void) const;
	void set_default_sprite(std::string __path);
	void set_default_sprite(Animation& __Anim_part);
	void set_default_sprite(sf::Texture& __Texture_part);
	virtual void get_command(float) = 0;
	virtual void move(void) = 0;
	virtual ~Creature() {};
};

#endif // !CREATURE_H

