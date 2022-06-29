#include "Creature.h"


Creature::Creature(int __x, int __y, int __width, int __height) 
    : _x(__x), _y(__y), _width(__width), _height(__height), _dx(0), _dy(0)
{
    _sprite.setPosition(sf::Vector2f(_x, _y));
}

void Creature::add_animation(Animation& an)
{
    animations[an.animation_name()] = an;
}



int Creature::x(void) const
{
    return _x;
}

int Creature::y(void) const
{
    return _y;
}

double Creature::dx(void) const
{
    return _dx;
}

double Creature::dy(void) const
{
    return _dy;
}

int Creature::width(void) const
{
    return _width;
}

int Creature::height(void) const
{
    return _height;
}

const sf::Sprite& Creature::sprite(void) const
{
    return _sprite;
}

void Creature::get_command(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animations["rmove"].play(time);
        _sprite = animations["rmove"].get_sprite();
        _sprite.setPosition(sf::Vector2f(_x, _y));
    }
    else  {
        animations["base"].play(time);
        _sprite = animations["base"].get_sprite();
        _sprite.setPosition(sf::Vector2f(_x, _y));
    }
}


void Creature::set_default_sprite(Animation& __Anim_part)
{
    _sprite.setTexture(__Anim_part.get_texture());
    _sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
}

void Creature::set_default_sprite(sf::Texture& __Texture_part)
{
    _sprite.setTexture(__Texture_part);
    _sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
}

void Creature::set_default_sprite(std::string __path)
{
    sf::Texture __texture;
    __texture.loadFromFile(__path);
    _sprite.setTexture(__texture);
    _sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
}
