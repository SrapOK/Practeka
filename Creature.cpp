#include "Creature.h"
#include "Manager.h"
#include <fstream>

extern Manager manager;

Creature::Creature(int __x, int __y, int __width, int __height)
    : _width(__width), _height(__height), _dx(0), _dy(0), _speed(0.1), on_ground(false), up_is_pressed(false)
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


void Creature::get_command(float time)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animations["right"]->play(time);
        _sprite = animations["right"]->get_sprite();
        _dx = _speed * time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animations["left"]->play(time);
        _sprite = animations["left"]->get_sprite();
        _dx = -_speed * time;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (up_is_pressed == true) {
            animations["up"]->play(time);
            _sprite = animations["up"]->get_sprite();
            if (on_ground) _dy += -_height / 1.8;
        }
        up_is_pressed = false;
    }
    if (on_ground == false) {
        if (_dy < 0) {
            animations["up"]->play(time);
            _sprite = animations["up"]->get_sprite();
        } if (_dy > 0) {
            animations["fall"]->play(time);
            _sprite = animations["fall"]->get_sprite();
        }
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))) {
        animations["base"]->play(time);
        _sprite = animations["base"]->get_sprite();
    }
    if (!on_ground) _dy += 0.035 * time;

}

void Creature::move(void)
{
    this->x() += _dx;
    collision_x();

    this->y() += _dy;
    on_ground = false;
    collision_y();

    //std::cout << _dx << '\t' << _dy << std::endl;

    _sprite.move(this->x(), this->y());

    _dx = 0;

}

void Creature::collision_x()
{
    {
        for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++)
            for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++)
            {
                if (mapee.at(i, j) != ' ')
                {
                    if (_dx > 0) this->x() = j * _width - _width;
                    if (_dx < 0)  this->x() = j * _width + _width;
                }
            }

    }
}
void Creature::collision_y()
{
    {
        for (int i = this->y() / _height; i < (this->y() + _height) / _height; i++)
            for (int j = this->x() / _width; j < (this->x() + _width) / _width; j++)
            {
                if (mapee.at(i, j) != ' ')
                {
                    if (_dy > 0) { this->y() = i * _height - _height;  _dy = 0;   on_ground = true; up_is_pressed = true; }
                    if (_dy < 0) { this->y() = i * _height + _height;  _dy = 0; }
                }
            }

    }
}

/*
void Creature::get_command(float time)
{
    int X = _x/16;
    int Xp = (_x - 1) / 16;
    int Xn = (_x + 16) / 16;
    int Y = _y/16;
    int Yp = (_y - 1) / 16;
    int Yn = (_y + 16) / 16;
    //_sprite.setPosition(sf::Vector2f(100, 100));
    int Fl;
    //int Y = _y  / 16;
    if (mapee.at(Yn, X) == ' ') {
        Fl = 0;
        for (int i = _x; i < _x + 16; i++) {
            if (mapee.at(Yn, i / 16) == '1' or mapee.at(Yn, i / 16) == '2' or mapee.at(Yn, i / 16) == 'G' or mapee.at(Yn, i / 16) == 'T' or mapee.at(Yn, i / 16) == '_' or mapee.at(Yn, i / 16) == '-' or mapee.at(Yn, i / 16) == 'X' or mapee.at(Yn, i / 16) == 'V' or mapee.at(Yn, i / 16) == 'B') {
                Fl = 1;
            }
            else if (mapee.at(Yn, i / 16) == 's') {
                _y = 310;
                _x = 100;
            }
        }
        if (Fl == 0) {
            _dy += _speed * 0.10 * time;
            _x += _dx;
            _y += _dy;
            _x = tolower(_x);
            _x = tolower(_x);
            std::cout << _x << '\t' << _y << std::endl;
        }
        std::cout << "BEBRAAAA\n";
        animations["rmove"]->play(time);
        _sprite = animations["rmove"]->get_sprite();
        _sprite.setPosition((int)_x, (int)_y);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        //std::cout << X << " " << Y << " " << mapee.at(Y, X) << " " << Xp << " " << Xn << "\n\n";
        Fl = 0;
        for (int i = _y; i < _y + 16; i++) {
            if (mapee.at(i / 16, Xn) == '1' or mapee.at(i / 16, Xn) == '2' or mapee.at(i / 16, Xn) == 'G' or mapee.at(i / 16, Xn) == 'T' or mapee.at(i / 16, Xn) == '_' or mapee.at(i / 16, Xn) == '-' or mapee.at(i / 16, Xn) == 'X' or mapee.at(i / 16, Xn) == 'B') { Fl = 1; }
            else if (mapee.at(i / 16, Xn) == 's') {
                _y = 310;
                _x = 100;
            }
        }
        if (Fl == 0){
            _dx = _speed * time;
            _x += _dx;
            _y += _dy;
            _x = tolower(_x);
            _x = tolower(_x);
            std::cout << _x << '\t' << _y << std::endl;
        }
        animations["rmove"]->play(time);
        _sprite = animations["rmove"]->get_sprite();
        _sprite.setPosition((int)_x, (int)_y);

    }else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        //std::cout << X << " " << Y << " " << mapee.at(Y, X) << " " << Xp << " " << Xn << "\n\n";
        Fl = 0;
        for (int i = _y; i < _y + 16; i++) {
            if (mapee.at(i / 16, Xp) == '1' or mapee.at(i / 16, Xp) == '2' or mapee.at(i / 16, Xp) == 'G' or mapee.at(i / 16, Xp) == 'T' or mapee.at(i / 16, Xp) == '_' or mapee.at(i / 16, Xp) == '-' or mapee.at(i / 16, Xp) == 'X' or mapee.at(i / 16, Xp) == 'B') { Fl = 1; }
            else if (mapee.at(i / 16, Xp) == 's') {
                _y = 310;
                _x = 100;
            }
        }
        if (Fl == 0) {
            _dx = -_speed * time;
            _x += _dx;
            _y += _dy;
            _x = tolower(_x);
            _x = tolower(_x);
            std::cout << _x << '\t' << _y << std::endl;
        }
        animations["lmove"]->play(time);
        _sprite = animations["lmove"]->get_sprite();
        _sprite.setPosition((int)_x, (int)_y);
    }
    else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            Fl = 0;
            for (int i = _x; i < _x + 16; i++) {
                if (mapee.at(Yp, i / 16) == '1' or mapee.at(Yp, i / 16) == '2' or mapee.at(Yp, i / 16) == 'G' or mapee.at(Yp, i / 16) == 'T' or mapee.at(Yp, i / 16) == '_' or mapee.at(Yp, i / 16) == '-' or mapee.at(Yp, i / 16) == 'X' or mapee.at(Yp, i / 16) == 'V' or mapee.at(Yp, i / 16) == 'B') { Fl = 1; }
                else if (mapee.at(Yp, i / 16) == 's') {
                    _y = 310;
                    _x = 100;
                }
            }
            if (Fl == 0) {
                _dy = - _speed * time * 1.7;
                _x += _dx;
                _y += _dy;
                _x = tolower(_x);
                _x = tolower(_x);
                std::cout << _x << '\t' << _y << std::endl;
            }
            animations["amove"]->play(time);
            _sprite = animations["amove"]->get_sprite();
            _sprite.setPosition((int)_x, (int)_y);

    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            Fl = 0;
            for (int i = _x; i < _x + 16; i++) {
                if (mapee.at(Yn, i / 16) == '1' or mapee.at(Yn, i / 16) == '2' or mapee.at(Yn, i / 16) == 'G' or mapee.at(Yn, i / 16) == 'T' or mapee.at(Yn, i / 16) == '_' or mapee.at(Yn, i / 16) == '-' or mapee.at(Yn, i / 16) == 'X' or mapee.at(Yn, i / 16) == 'V' or mapee.at(Yn, i / 16) == 'B') {
                    Fl = 1;
                }
                else if (mapee.at(Yn, i / 16) == 's') {
                    _y = 310;
                    _x = 100;
                }
            }
            if (Fl == 0) {
                _dx = _speed * time;
                _x += _dx;
                _y += _dy;
                _x = tolower(_x);
                _x = tolower(_x);
                std::cout << _x << '\t' << _y << std::endl;
            }
            animations["amove"]->play(time);
            _sprite = animations["amove"]->get_sprite();
            _sprite.setPosition((int)_x, (int)_y);
        }
    else  {
        std::cout << "?\n";
        _dx = 0;
        _dy = 0;
        animations["base"]->play(time);
        _sprite = animations["base"]->get_sprite();
        _sprite.setPosition((int)_x, (int)_y);
    }
}
*/


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