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
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                                              0",
	"0                                                                                                                                      0                       0",
	"0                                                                                                                                     00                       0",
	"0                                                                                                                                    000                       0",
	"0                                                                                                                                   0000                       0",
	"0                                                                                                                                  00000                       0",
	"0                                               0        0                                                                        000000                       0",
	"0                                      000000 00000000000000                                                                     0000000                       0",
	"0                                  00         000000000000000                                                                   00000000                       0",
	"0                             00              0000000000000000                                                                 000000000                       0",
	"0             00   000   00                   00000000000000000                                                               0000000000                       0",
	"0             00sssssssss00sssssssssssssssssss000000000000000000            ssss                    00        00        00   00000000000sssssssssssssssssssssss0",
	"000000000000000000000000000000000000000000000000000000000000000000000000    000000000000000   000000000000000000000000000000000000000000000000000000000000000000",
	"00000000000000000000000000000000000000000000000000000000000000000000000000    00000000000    0000000000000000000000000000000000000000000000000000000000000000000",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000              000000000000000000000000000000000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	};

	const int HEIGHT_MAP2 = 25;
	const int WIDTH_MAP2 = 40 * 3;
	sf::String TileMap2[25] = {
	"YVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV0",
	"2     F                                                                                                                                                        0",
	"2     F                                                                                                                                                        0",
	"2     F                                                                                                                                                        0",
	"2     F                                                                                                                                                        0",
	"2     F                                                            B      B       B                                                                            0",
	"2     F                                                       ------------------------------------                                                             0",
	"2     F                                                                                                                                                        0",
	"2     F                                                    ---                                                                                                 0",
	"2     F                                                       ---                                 ---                                                          0",
	"2     F                                                          ---                                                                   0                       0",
	"2     F                                                             --         -                                                      00                       0",
	"2     F                                                             -----      -                     ---                             000                       0",
	"2     F                                                             --      ----                                                    0000                       0",
	"2    ZZZ                                                            ------     -                                                   00000                       0",
	"2    ZZZ                                        B        B          --                                                            000000                       0",
	"2    ZZZ                               ------ G________________T    XXXXXXXXXXXXXXXX   G__T           ----GT                     0000000                       0",
	"2                                  --         10000000000000000L__T    XXXXXXXXXXX    GJ002               1LT                   00000000                       0",
	"2                  ---        --              10000000000000000000L_T               G_J0002               10LT                 000000000                       0",
	"2             GT         GT                   1000000000000000000000L_______________J000002              B100LT               0000000000                       0",
	"2             12sssssssss12sssssssssssssssssss100000000000000000000000000000000000000000002sssssssssss- BB1000LT     ss      00000000000sssssssssssssssssssssss0",
	"L_____________JL_________JL___________________J0000000000000000000000000000000000000000000L__________T-BBB10000L_____________00000000000000000000000000000000000",
	"00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000J____J00000000000000000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	};

public:


	std::string File;
	//sf::Image image;
	//sf::Texture texture;
	int choice_Map;
	sf::Sprite s_map;
	sf::Image map_image;
	sf::Texture map;
	sf::Sprite _s_map;
	Map(std::string F, int x) {

		choice_Map = x;
		File = F;
		map_image.loadFromFile(File);

		map_image.createMaskFromColor(sf::Color(255, 255, 255));
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
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				s_map.setTextureRect(sf::IntRect(189, 128, 16, 16));
				if (choice_Map == 1) {
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
					if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
					if ((TileMap[i][j] == '0')) s_map.setTextureRect(sf::IntRect(64, 0, 32, 32));
				}
				if (choice_Map == 2) {
					if (TileMap2[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32, 176, 16, 16));
					if (TileMap2[i][j] == 'F')  s_map.setTextureRect(sf::IntRect(16, 48, 16, 16));
					if (TileMap2[i][j] == 'Z')  s_map.setTextureRect(sf::IntRect(128, 96, 16, 16));
					if (TileMap2[i][j] == 'Y')  s_map.setTextureRect(sf::IntRect(0, 144, 16, 16));
					if (TileMap2[i][j] == 'V')  s_map.setTextureRect(sf::IntRect(16, 144, 16, 16));
					if (TileMap2[i][j] == 'X')  s_map.setTextureRect(sf::IntRect(16, 16, 16, 16));
					if (TileMap2[i][j] == '-')  s_map.setTextureRect(sf::IntRect(32, 16, 16, 16));
					if (TileMap2[i][j] == 'B')  s_map.setTextureRect(sf::IntRect(0, 16, 16, 16));
					if (TileMap2[i][j] == 'T')  s_map.setTextureRect(sf::IntRect(80, 144, 16, 16));
					if (TileMap2[i][j] == '2')  s_map.setTextureRect(sf::IntRect(0, 160, 16, 16));
					if (TileMap2[i][j] == 'L')  s_map.setTextureRect(sf::IntRect(0, 176, 16, 16));
					if (TileMap2[i][j] == '_')  s_map.setTextureRect(sf::IntRect(16, 176, 16, 16));
					if (TileMap2[i][j] == 'G')  s_map.setTextureRect(sf::IntRect(48, 144, 16, 16));
					if (TileMap2[i][j] == '1')  s_map.setTextureRect(sf::IntRect(32, 160, 32, 32));
					if (TileMap2[i][j] == 's')  s_map.setTextureRect(sf::IntRect(144, 64, 16, 16));
					if ((TileMap2[i][j] == '0')) s_map.setTextureRect(sf::IntRect(48+16, 160, 16, 16));
				}
				s_map.setPosition(j * 16, i * 16);

				window.draw(s_map);
			}
	}
};