#pragma once
#include "Manager.h"
#include "Header.h"

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
	Creature(std::string __path, int __x, int __y, int __width, int __height) : _path(__path), _x(__x), _y(__y), _width(__width), _height(__height), _current_frame(0){};
	int x(void);
	int y(void);
	double dx(void);
	double dy(void);
	int width(void);
	int height(void);
	const sf::Sprite& sprite(void);
	void update(float);
};

