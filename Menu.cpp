#include "Menu.h"

void play1(float __time, sf::Sprite& _hero_memu, float& _hx) {
	static float _current_frame;
	_current_frame += 0.00002 * __time;
	if (_current_frame > 4) _current_frame = 0;
	_hero_memu.setTextureRect(sf::IntRect(16 * int(_current_frame), 0, 16, 16));
	_hx = _hx + 0.0002 * __time;
}

void play2(float __time, sf::Sprite& _grip_memu, float& _gx) {
	static float _current_frame;
	_current_frame += 0.000004 * __time;
	if (_current_frame > 2) _current_frame = 0;
	_grip_memu.setTextureRect(sf::IntRect(16 * int(_current_frame) + 417, 208, 16, 16));
	_gx = _gx + 0.0002 * __time;
	//_gy++;
}



void menu(sf::RenderWindow& window, int _tip) {
	//sf::Text menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	sf::Font font;
	font.loadFromFile("Manrope-ExtraLight.ttf");
	sf::Text PLAY("", font, 55);
	sf::Text EXET("", font, 55);
	sf::Text VIN("", font, 55);
	sf::Text LOSS("", font, 55);
	PLAY.setString("PLAY");
	PLAY.setPosition(240, 130);
	EXET.setString("EXET");
	EXET.setPosition(240, 130 * 3);
	VIN.setString("  VIN");
	VIN.setPosition(240, 130 * 2);
	LOSS.setString("LOSS");
	LOSS.setPosition(240, 130 * 2);
	//sf::Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	sf::Texture _hero_memu;
	_hero_memu.loadFromFile("Walk.png");
	sf::Sprite hero_memu;
	hero_memu.setTexture(_hero_memu);
	hero_memu.setTextureRect(sf::IntRect(0, 0, 16, 16));
	float hx = 50;
	int hy = 25;
	hero_memu.setPosition(hx, hy);
	hero_memu.setScale(3.f, 3.f);
	sf::Texture _grip_memu;
	_grip_memu.loadFromFile("simples_pimples.png");
	sf::Sprite grip_memu;
	grip_memu.setTexture(_grip_memu);
	grip_memu.setTextureRect(sf::IntRect(417, 208, 16, 16));
	float gx = 50;
	int gy = 525;
	grip_memu.setPosition(gx, gy);
	grip_memu.setScale(3.f, 3.f);
	//Animation* fallR = new Animation("fallR", "Fall.png", 0, 0, 16, 16);
	//Creature* hero = new Hero(16, 16, 16, 16);
	//hero->add_animation(fallR);
	sf::Clock clock;
	
	while (isMenu)
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) window.close();
		}
		PLAY.setFillColor(sf::Color(82, 127, 57));
		EXET.setFillColor(sf::Color(82, 127, 57));
		VIN.setFillColor(sf::Color::Red);

		menuNum = 0;
		//window.clear(sf::Color(32, 70, 49));

		if (sf::IntRect(240, 130, 125, 55).contains(sf::Mouse::getPosition(window))) {
			PLAY.setFillColor(sf::Color(174, 196, 64)); menuNum = 1; play1(time, hero_memu, hx); hero_memu.setPosition(hx, hy);
		}
		else {
			hero_memu.setPosition(50, 25); hx = 50;
			hy = 25;
		}
		if (sf::IntRect(240, 130 * 3, 125, 55).contains(sf::Mouse::getPosition(window))) {
			EXET.setFillColor(sf::Color(174, 196, 64)); menuNum = 2; play2(time, grip_memu, gx); grip_memu.setPosition(gx, gy);
		}
		else {
			grip_memu.setPosition(50, 525); gx = 50;
			gy = 525;
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			//if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }
			if (menuNum == 2) { window.close(); isMenu = false; }

		}

		//window.draw(menuBg);
		//window.draw(menu1);
		window.clear();
		window.setView(window.getDefaultView());
		window.clear(sf::Color(32, 70, 49));
		if (_tip == 3)window.draw(VIN);
		if (_tip == 2)window.draw(LOSS);
		window.draw(hero_memu);
		window.draw(grip_memu);
		window.draw(EXET);
		window.draw(PLAY);
		window.display();
	}
}

/*void vin(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("Manrope-ExtraLight.ttf");
	sf::Text PLAY("", font, 55);
	sf::Text EXET("", font, 55);
	bool isMenu = 1;
	int menuNum = 0;
	while (isMenu) {
		window.clear();
		window.setView(window.getDefaultView());
		window.clear(sf::Color(32, 70, 49));
		
		window.display();
	}
}*/
