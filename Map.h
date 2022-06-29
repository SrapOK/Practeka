#ifndef MAP_H
#define MAP_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>

extern sf::RenderWindow window;

class Map
{
private:
	const int HEIGHT_MAP = 25;
	const int WIDTH_MAP = 40*3;

	const int HEIGHT_MAP2 = 25;
	const int WIDTH_MAP2 = 40 * 3;
	sf::String TileMap2[25];
	std::string File;
	std::string tile_map;
	sf::Sprite s_map;
	sf::Image map_image;
	sf::Texture map;
	sf::Sprite _s_map;

public:
	Map(std::string _File, std::string _tile_map);
	void print(void);
	sf::String* Get_Map();
	char at(int _x, int _y);
	int Get_HEIGHT_MAP();
	int Get_WIDTH_MAP();
};



#endif // MAP_H