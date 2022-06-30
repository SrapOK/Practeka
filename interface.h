#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class interface {
	interface();
	void setPosition(int, int);
	void die();
	//sf::Text _text;
	sf::Text getText();
public:
	sf::Text _text;
};