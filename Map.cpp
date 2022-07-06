#include "Map.h"
#include "Hero.h"
#include "Enemy.h"
#include "Observer.h"
#include "Coin.h"
#include <SFML/Graphics.hpp>

extern Manager manager;

void Map::print() {
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			s_map.setTextureRect(sf::IntRect(189, 128, 16, 16));
			if (TileMap2[i][j] == 'J')  s_map.setTextureRect(sf::IntRect(32, 176, 16, 16));
			if (TileMap2[i][j] == 'M')  s_map.setTextureRect(sf::IntRect(64, 192, 16, 16));
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
			if ((TileMap2[i][j] == '0')) s_map.setTextureRect(sf::IntRect(48 + 16, 160, 16, 16));
			s_map.setPosition(j * 16, i * 16);

			window.draw(s_map);
		}
	}
}

void Map::initialize(void)
{
	Animation* right = new Animation("right", "Walk.png", 0, 0, 16, 16);
	Animation* left = new Animation("left", "Walk.png", 0, 0, -16, 16);
	Animation* upR = new Animation("upR", "Jump.png", 0, 0, 16, 16);
	Animation* upL = new Animation("upL", "Jump.png", 0, 0, -16, 16);
	Animation* fallR = new Animation("fallR", "Fall.png", 0, 0, 16, 16);
	Animation* fallL = new Animation("fallL", "Fall.png", 0, 0, -16, 16);
	Animation* base1 = new Animation("base1", "base.png", 0, 0, 16, 16, 0.003);
	Animation* base2 = new Animation("base2", "base.png", 0, 0, -16, 16, 0.003);
	Animation* baseGripR = new Animation("baseGripR", "simples_pimples.png", 417, 208, 16, 16, 0.003, 2);
	Animation* baseGripL = new Animation("baseGripL", "simples_pimples.png", 417, 208, -16, 16, 0.003, 2);
	Animation* _coin = new Animation("_coin", "Full_Coins.png", 0, 0, 16, 16, 0.003);

	for (size_t i = 0; i < manager.list.size(); i++) {
		manager.list[i]->kill();
	}

	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap2[i][j] == 'h') {

				Creature* hero = new Hero(j * 16, i * 16, 16, 16);
				//Observer heros();

				hero->add_animation(right);
				hero->add_animation(left);
				hero->add_animation(upR);
				hero->add_animation(upL);
				hero->add_animation(fallR);
				hero->add_animation(fallL);
				hero->add_animation(base1);
				hero->add_animation(base2);
			}
			if (TileMap2[i][j] == 'e') {
				Creature* grip = new Enemy(j * 16, i * 16, 16, 16);
				grip->add_animation(baseGripR);
				grip->add_animation(baseGripL);
			}
			if (TileMap2[i][j] == 'm') {

				//std::cout << "f";

				Creature* coin = new Coin(j * 16, i * 16, 16, 16);
				coin->add_animation(_coin);
			}
		}
	}
}

sf::String* Map::Get_Map() {
	return TileMap2;
}
char Map::at(int _x, int _y) {
	return TileMap2[_x][_y];
}
int Map::Get_HEIGHT_MAP() {
	return HEIGHT_MAP;
}
int Map::Get_WIDTH_MAP() {
	return WIDTH_MAP;
}



Map::Map(std::string _File, std::string _tile_map) : tile_map(_tile_map), File(_File) {

	map_image.loadFromFile(File);
	std::ifstream input;
	input.open(tile_map);
	std::string tmp;
	for (size_t i = 0; i < 25; i++) {
		if (!std::getline(input, tmp)) break;
		TileMap2[i] = tmp;
	}
	WIDTH_MAP = TileMap2[0].getSize();
	map_image.createMaskFromColor(sf::Color(255, 255, 255));
	map.loadFromImage(map_image);
	s_map.setTexture(map);
}