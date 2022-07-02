#include "Hero.h"
extern Manager manager;

void Hero::move(void)
{
    this->x() += _dx;
    collision_x();

    this->y() += _dy;
    _on_ground = false;
    collision_y();
    for (int i = 0; i < manager.list.size(); i++) {
        if (this != manager.list[i]) {
            float tmp_x = manager.list[i]->x();
            float tmp_y = manager.list[i]->y();
            int tmp_width = manager.list[i]->width();
            int tmp_height = manager.list[i]->height();
            if (box.intersects(sf::FloatRect(tmp_x, tmp_y, tmp_width, tmp_height)) && _dy <= 0) {
                damage();
            }
            if (box.intersects(sf::FloatRect(tmp_x, tmp_y, tmp_width, tmp_height)) && _dy > 0) {
                manager.list[i]->damage();
            }
        }
    }

    _sprite.move(this->x(), this->y());
    if (_dx != 0) {
        _pdx = _dx;
        _dx = 0;
    }
    getPlayerCoordinateForView(this->x(), this->y());
}

Hero::Hero(int __x, int __y, int __width, int __height) : Creature(__x, __y, __width, __height)
{
    _hp = 3;
    int _x = __x;
    int _y = __y;
}

void Hero::get_command(float time)
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and _pdx > 0) {
        if (_up_is_pressed == true) {
            animations["upR"]->play(time);
            _sprite = animations["upR"]->get_sprite();

            if (_on_ground) _dy += -_height / 2.8 * time * _speed;

        }
        _up_is_pressed = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and _pdx < 0) {
        if (_up_is_pressed == true) {
            animations["upL"]->play(time);
            _sprite = animations["upL"]->get_sprite();

            if (_on_ground) _dy += -_height / 2.8 * time * _speed;
        }
        _up_is_pressed = false;
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and _pdx > 0) {
        animations["base1"]->play(time);
        _sprite = animations["base1"]->get_sprite();
    }
    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) and _pdx < 0) {
        animations["base2"]->play(time);
        _sprite = animations["base2"]->get_sprite();
    }
    if (_on_ground == false) {
        if (_dy < 0 and _pdx > 0) {
            animations["upR"]->play(time);
            _sprite = animations["upR"]->get_sprite();
        } if (_dy > 0 and _pdx > 0) {
            animations["fallR"]->play(time);
            _sprite = animations["fallR"]->get_sprite();
        }
        if (_dy < 0 and _pdx < 0) {
            animations["upL"]->play(time);
            _sprite = animations["upL"]->get_sprite();
        } if (_dy > 0 and _pdx < 0) {
            animations["fallL"]->play(time);
            _sprite = animations["fallL"]->get_sprite();
        }
    }
    
    if (!_on_ground) _dy += 0.03 * time;

}

int Hero::get_x() {
    return _x;
}
int Hero::get_y() {
    return _y;
}

void Hero::damage(void)
{

}


