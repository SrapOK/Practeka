#include "Creature.h"


Creature::Creature(std::string __path, int __x, int __y, int __width, int __height) 
    : _path(__path), _x(__x), _y(__y), _width(__width), _height(__height), _current_frame(0)
{
	sf::Texture CrTexture;
	CrTexture.loadFromFile(__path);
	_sprite.setTexture(CrTexture);
	_sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
}


int Creature::x(void)
{
    return _x;
}

int Creature::y(void)
{
    return _y;
}

double Creature::dx(void)
{
    return _dx;
}

double Creature::dy(void)
{
    return _dy;
}

int Creature::width(void)
{
    return _width;
}

int Creature::height(void)
{
    return _height;
}

const sf::Sprite& Creature::sprite(void)
{
    return _sprite;
}
