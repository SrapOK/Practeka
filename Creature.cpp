#include "Creature.h"
#include "Manager.h"
#include <fstream>

extern Manager manager;


Creature::Creature(int __x, int __y, int __width, int __height)
    : _width(__width), _height(__height), _dx(0), _dy(0), _speed(0.1), _on_ground(false), _up_is_pressed(false), _alive(true)
{
    box.left = __x;
    box.top = __y;
    _sprite.setPosition(__x, __y);

    manager.add(this);
}

void Creature::add_animation(Animation* an)
{
    animations[an->animation_name()] = an;
}


float& Creature::x(void)
{
    return box.left;
}

float& Creature::y(void)
{
    return box.top;
}

bool Creature::alive(void)
{
    return _alive;
}


float Creature::dx(void) const
{
    return _dx;
}

float Creature::dy(void) const
{
    return _dy;
}

float& Creature::width(void)
{
    return box.width;
}

float& Creature::height(void)
{
    return box.height;
}

const sf::Sprite& Creature::sprite(void) const
{
    return _sprite;
}


bool Creature::collision_x()
{
    bool flag = false;
    for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++) {
        for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++) {
            if (mapee.at(i, j) != ' ') {
                flag = true;
                if (_dx > 0) this->x() = j * _width - _width;
                if (_dx < 0)  this->x() = j * _width + _width;
            }
        }
    }
    std::cout << this->x() << "      " << this->y() << std::endl;
    return flag;
}
bool Creature::collision_y()
{
    bool flag = false;
    for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++) {
        for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++) {
            if (mapee.at(i, j) != ' ') {
                flag = true;
                if (_dy > 0) { this->y() = i * _height - _height;  _dy = 0;   _on_ground = true; _up_is_pressed = true; }
                if (_dy < 0) { this->y() = i * _height + _height;  _dy = 0; }
            }
        }
    }
    std::cout << this->x() << "      " << this->y() << std::endl;
    return flag;
}

void Creature::set_default_sprite(Animation& __Anim_part)
{
    _sprite.setTexture(__Anim_part.get_texture());
    _sprite.setTextureRect(sf::IntRect(0, 0, _width, _height));
}

void Creature::kill(void)
{
    _alive = false;
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
