#include "Creature.h"
#include "Manager.h"
#include "Hero.h"
#include "interface.h"
#include <fstream>
#include "Enemy.h"

extern Manager manager;
extern Menu menu;

void Creature::damage(void) {
    _hp--;
    if (_hp <= 0 && this->alive()) kill();
    this->x() = 100;
    this->y() = 320;
}

Creature::Creature(int __x, int __y, int __width, int __height)
    : _width(__width), _height(__height), _dx(0), _dy(0), _speed(0.1), _on_ground(false), _up_is_pressed(false), _alive(true)
{
    box.left = __x;
    box.top = __y;
    box.width = __width;
    box.height = __height;
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

int Creature::hp(void)
{
    return _hp;
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

//////////////////////////////////////////collision не меняет карту///////////////////////////////

bool Creature::collision_x(int _mapN)
{
    //std::cout << _mapN << "collision_x" << std::endl;
    //std::cout << this->y() / _height << " " << (this->y() + _height) / _height << std::endl;
    bool flag = false;
    for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++) {
        for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++) {
            //std::cout << i << " " << j << std::endl;
            if (menu.get_mapN() == 1) {
                if (!(mapee.at(i, j) == ' ' || mapee.at(i, j) == 'h' || mapee.at(i, j) == 'e' || mapee.at(i, j) == 'm')) {
                    flag = true;
                    if (_dx > 0) this->x() = j * _width - _width;
                    if (_dx < 0)  this->x() = j * _width + _width;
                }
                if (mapee.at(i, j) == 'M') {
                    //_hp = 0;
                    kill();
                    menu.menu(window, 3);
                    //mapee.initialize();
                    //vin(window);
                    //damage();
                }
                if (mapee.at(i, j) == 's') {
                    damage();
                }

            }
            if (menu.get_mapN() == 2) {
                if (!(mapee2.at(i, j) == ' ' || mapee2.at(i, j) == 'h' || mapee2.at(i, j) == 'e' || mapee2.at(i, j) == 'm')) {
                    flag = true;
                    if (_dx > 0) this->x() = j * _width - _width;
                    if (_dx < 0)  this->x() = j * _width + _width;
                }
                if (mapee2.at(i, j) == 'M') {
                    //_hp = 0;
                    kill();
                    menu.menu(window, 3);
                    //mapee.initialize();
                    //vin(window);
                    //damage();
                }
                if (mapee2.at(i, j) == 's') {
                    damage();
                }

            }
        }
    }
    return flag;
}
bool Creature::collision_y(int _mapN)
{
    //std::cout << _mapN << "collision_y" << std::endl;
    //std::cout << this->y() / _height << " " << (this->y() + _height) / _height << std::endl;
    bool flag = false;
    for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++) {
        for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++) {
            if (menu.get_mapN() == 1) {
                if (!(mapee.at(i, j) == ' ' || mapee.at(i, j) == 'h' || mapee.at(i, j) == 'e' || mapee.at(i, j) == 'm')) {
                    flag = true;
                    if (_dy > 0) { this->y() = i * _height - _height;  _dy = 0;   _on_ground = true; _up_is_pressed = true; }
                    if (_dy < 0) { this->y() = i * _height + _height;  _dy = 0; }
                }
                if (mapee.at(i, j) == 'M') {
                    //_hp = 0;
                    kill();
                    menu.menu(window, 3);
                    //mapee.initialize();
                    //vin(window);
                    //damage();
                }
                if (mapee.at(i, j) == 's') {
                    damage();
                }
            }
            if (menu.get_mapN() == 2) {
                if (!(mapee2.at(i, j) == ' ' || mapee2.at(i, j) == 'h' || mapee2.at(i, j) == 'e' || mapee2.at(i, j) == 'm')) {
                    flag = true;
                    if (_dy > 0) { this->y() = i * _height - _height;  _dy = 0;   _on_ground = true; _up_is_pressed = true; }
                    if (_dy < 0) { this->y() = i * _height + _height;  _dy = 0; }
                }
                if (mapee2.at(i, j) == 'M') {
                    //_hp = 0;
                    kill();
                    menu.menu(window, 3);
                    //mapee.initialize();
                    //vin(window);
                    //damage();
                }
                if (mapee2.at(i, j) == 's') {
                    damage();
                }
            }
        }
    }
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
