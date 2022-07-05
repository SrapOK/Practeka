#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Map.h"
extern Map mapee;
extern Map mapee2;

void play1(float __time, sf::Sprite& _hero_memu, float& _hx);
void play2(float __time, sf::Sprite& _grip_memu, float& _gx);
int menu(sf::RenderWindow& window, int _tip);
//void vin(sf::RenderWindow& window);
