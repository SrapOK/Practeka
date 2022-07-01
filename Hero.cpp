#include "Hero.h"

void Hero::move(void)
{
    this->x() += _dx;
    collision_x();

    this->y() += _dy;
    _on_ground = false;
    collision_y();

    //std::cout << _dx << '\t' << _dy << std::endl;

    _sprite.move(this->x(), this->y());

    _dx = 0;
    getPlayerCoordinateForView(this->x(), this->y());
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (_up_is_pressed == true) {
            animations["up"]->play(time);
            _sprite = animations["up"]->get_sprite();
            if (_on_ground) _dy += -_height / 2.6;
        }
        _up_is_pressed = false;
    }
    if (_on_ground == false) {
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
    if (!_on_ground) _dy += 0.027 * time;

}