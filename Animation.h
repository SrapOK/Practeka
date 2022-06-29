#ifndef ANIMATION_H
#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Animation
{
private:
	int _frame_counter;
	float _speed;
	sf::Texture _texture;
	sf::Sprite _sprite;
	std::string _path;
	int _x, _y;
	int _width, _height;
	float _current_frame;
	std::string _animation_name;
public:
	sf::Sprite& get_sprite(void);
	sf::Texture& get_texture(void);
	std::string animation_name(void);
	Animation(std::string __animation_name, std::string __path, int __x, int __y, int __width, int __height);
	void play(float);
	Animation() = default;
};



#define ANIMATION_H
#endif // !ANIMATION_H


