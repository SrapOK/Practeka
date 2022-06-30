#include "View.h"

extern sf::View view1;
void getPlayerCoordinateForView(float x, float y) { 
	float tempX = x; float tempY = y;

	if (x < 100) tempX = 100;
	if (y < 100) tempY = 100;
	if (y > 300) tempY = 300;	

	view1.setCenter(tempX, tempY);
}