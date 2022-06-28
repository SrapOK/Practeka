#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

extern sf::RenderWindow window;

class Map
{
private:
	int HEIGHT_MAP = 25;
	int WIDTH_MAP = 40;
	sf::String TileMap[25] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0   s                                  0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};
public:

	sf::String File;
	//sf::Image image;
	//sf::Texture texture;
	sf::Sprite s_map;
	Map(sf::String F, int x) {
		sf::Image map_image;
		map_image.loadFromFile(F);
		sf::Texture map;
		map.loadFromImage(map_image);
		sf::Sprite _s_map;
		_s_map.setTexture(map);
		s_map = _s_map;

		File = F;
		
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
	/*void Print() {
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));

				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}
	}*/
};

