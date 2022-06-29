#include "View.h"

extern sf::View view1;
void getPlayerCoordinateForView(float x, float y) { //функция для считывания координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

	if (x < 100) tempX = 100;//убираем из вида левую сторону
	if (y < 100) tempY = 100;//верхнюю сторону
	if (y > 300) tempY = 300;//нижнюю сторону	

	view1.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 
}