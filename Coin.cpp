#include "Coin.h"
extern int mapN;

void Coin::get_command(float time)
{
	animations["_coin"]->play(time);
	_sprite = animations["_coin"]->get_sprite();

}
void Coin::move()
{
	this->x() += _dx;

	this->y() += _dy;
	_on_ground = false;
	collision_y(mapN);
	_sprite.move(this->x(), this->y());
}