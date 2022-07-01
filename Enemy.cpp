#include "Enemy.h"

Enemy::Enemy(int __x, int __y, int __width, int __height) : Creature(__x, __y, __width, __height)
{
	_hp = 1;
}

void Enemy::get_command(float time)
{
	if (direction == -1) {
		animations["baseGripR"]->play(time);
		_sprite = animations["baseGripR"]->get_sprite();
		_dx = -_speed * time * direction;
		//std::cout << direction << std::endl;
	}
	if (direction == 1) {
		//std::cout << direction << std::endl;
		animations["baseGripL"]->play(time);
		_sprite = animations["baseGripL"]->get_sprite();
		_dx = -_speed * time * direction;
	}
}

void Enemy::move(void)
{
	this->x() += _dx;
	if (collision_x()) {
		direction *= -1;
		//kill();
	}

	this->y() += _dy;
	_on_ground = false;
	collision_y();


	_sprite.move(this->x(), this->y());

	_dx = 0;
}

int Enemy::getPositionX(void) {
	int x;
	x = this->y() / 16;
	return x;
}

int Enemy::getPositionY(void) {
	int y;
	y = this->y() / 16;
	return y;
}