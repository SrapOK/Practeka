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

//int Creature::grtVector2f() {
//    return sf::Vector2f[0];
//}

void Creature::get_command(float time)
{
    int X = _x/16;
    int Xp = (_x - 1) / 16;
    int Xn = (_x + 16) / 16;
    int Y = _y/16;

    int Fl;
    //int Y = _y  / 16;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        animations["rmove"].play(time);
        _sprite = animations["rmove"].get_sprite();
        _sprite.setPosition(sf::Vector2f(_x, _y));
        std::cout << X << " " << Y << " " << mapee.at(Y, X) << " " << Xp << " " << Xn << "\n\n";
        Fl = 0;
        for (int i = _y; i < _y + 16; i++) {
                if (mapee.at(i / 16, Xn) == '1' or mapee.at(i / 16, Xn) == '2' or mapee.at(i / 16, Xn) == '_') { Fl = 1; }
                //else _x++;
        }
        if (Fl == 0){ _x++; }
        //if (TileMap2[Y][Xn] == '1' or TileMap2[Y][Xn] == '2' or TileMap2[Y][Xn] == '_') {}
        //if (TileMap2[Y][Xn] == '2') { _x--; }
        //else if (TileMap2[Y][Xn] == '1') { _x--; }
        //else if (TileMap2[Y][Xn] == '_') { _x--; }
        //else _x++;
        //std::cout << _x << "\n";
    }else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        animations["lmove"].play(time);
        _sprite = animations["lmove"].get_sprite();
        _sprite.setPosition(sf::Vector2f(_x, _y));
        std::cout << X << " " << Y << " " << mapee.at(Y, X) << " " << Xp << " " << Xn << "\n\n";
        Fl = 0;
        for (int i = _y; i < _y + 16; i++) {
            if (mapee.at(i / 16, Xp) == '1' or mapee.at(i / 16, Xp) == '2' or mapee.at(i / 16, Xp) == '_') { Fl = 1; }
            //else _x++;
        }
        if (Fl == 0) { _x--; }
        //if (TileMap2[Y][Xp] == '1' or TileMap2[Y][Xp] == '2' or TileMap2[Y][Xp] == '_') {} //{ _x++; }
        //else if (TileMap2[Y][Xp] == '2') { _x++; }
        //else if (TileMap2[Y][Xp] == '_') { _x++; }
        //else if (TileMap2[Y][Xp] == '2') { _x++; }
        //else _x--;
        //std::cout << _x << "\n";
        //_x--;
        
    }
    else  {
        animations["base"].playB(time);
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
