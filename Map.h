#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
//#include <string>

extern sf::RenderWindow window;

class Map
{
private:
	const int HEIGHT_MAP = 25;
	const int WIDTH_MAP = 40*3;
	sf::String TileMap[25] = {
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                              0",
	"0   s                                                                                                                                                          0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	};
public:


	std::string File;
	//sf::Image image;
	//sf::Texture texture;
	sf::Sprite s_map;
	sf::Image map_image;
	sf::Texture map;
	sf::Sprite _s_map;
	Map(std::string F, int x) {
		File = F;
		
		map_image.loadFromFile(File);
		
		map.loadFromImage(map_image);
		
		s_map.setTexture(map);
		//s_map = _s_map;
		//s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
		//window.draw(s_map);
		//s_map.setPosition(92, 92);
		//window.draw(s_map);
		

	}

	sf::String* Get_Map() {
		return TileMap;
	}
	int Get_HEIGHT_MAP() {
		return HEIGHT_MAP;
	}
	int Get_WIDTH_MAP() {
		return WIDTH_MAP;
	}
	void Print() {
		//s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
		//window.draw(s_map);
		//s_map.setPosition(32, 32);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}
	}
};