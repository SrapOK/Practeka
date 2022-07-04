#include "Animation.h"

#include <cmath>

sf::Sprite& Animation::get_sprite(void)
{
	return _sprite;
}

sf::Texture& Animation::get_texture(void)
{
	return _texture;
}

std::string Animation::animation_name(void)
{
	return _animation_name;
}

Animation::Animation(std::string __animation_name, std::string __path, int __x, int __y, int __width, int __height, float __speed, int __frame)
	: _animation_name(__animation_name), _path(__path), _x(__x), _y(__y), _width(__width), _height(__height), _speed(__speed), _current_frame(0), _frame_counter(0)
{	
	_image.loadFromFile(__path);
	sf::Vector2u tmp =_image.getSize();
	if (__frame == -1) {
		_frame_counter = tmp.x / abs(_width);
	}
	else _frame_counter = __frame;
	

	_texture.loadFromFile(__path);
	_sprite.setTexture(_texture);
	_sprite.setTextureRect(sf::IntRect(_x, _y, _width, _height));
}

void Animation::play(float __time)
{
	_current_frame += _speed * __time;
	if (_current_frame > _frame_counter) _current_frame = 0;

	if (_width < 0) _sprite.setTextureRect(sf::IntRect(abs(_width * tolower(_current_frame)) - _width + _x, _y, _width, _height));
	if (_width > 0) _sprite.setTextureRect(sf::IntRect(abs(_width * tolower(_current_frame)) + _x, _y, _width, _height));
	
}