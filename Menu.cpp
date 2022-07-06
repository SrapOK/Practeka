#include "Menu.h"
#include <fstream>

extern int SCORE;
extern int SESSION_RECORD;
extern std::fstream record_file;

void Menu::play1(float __time, sf::Sprite& _hero_memu, float& _hx) {
	static float _current_frame;
	_current_frame += 0.00002 * __time;
	if (_current_frame > 4) _current_frame = 0;
	_hero_memu.setTextureRect(sf::IntRect(16 * int(_current_frame), 0, 16, 16));
	_hx = _hx + 0.0002 * __time;
}

void Menu::play2(float __time, sf::Sprite& _grip_memu, float& _gx) {
	static float _current_frame;
	_current_frame += 0.000004 * __time;
	if (_current_frame > 2) _current_frame = 0;
	_grip_memu.setTextureRect(sf::IntRect(16 * int(_current_frame) + 417, 208, 16, 16));
	_gx = _gx + 0.0002 * __time;
	//_gy++;
}




int Menu::menu(sf::RenderWindow& window, int _tip) {
  int input_record = 0;
	record_file >> input_record;
	std::cout << "A: " << input_record << std::endl;
	//if (!record_file.good()) { input_record = 0; std::cout << "("; }
	if (SCORE > SESSION_RECORD) SESSION_RECORD = SCORE;
	if (input_record > SESSION_RECORD) SESSION_RECORD = input_record;
	int _mapN;
	_mapN = 0;
	//sf::Text menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	sf::Font font;
	font.loadFromFile("Manrope-ExtraLight.ttf");
	sf::Text PLAYm1("", font, 55);
	sf::Text PLAYm2("", font, 55);
	sf::Text EXIT("", font, 55);
	sf::Text WIN("", font, 55);
	sf::Text LOSS("", font, 55);
  sf::Text RECORD("", font, 55);
  RECORD.setString("Record: " + std::to_string(SESSION_RECORD));
	RECORD.setPosition(260, 5);
	PLAYm1.setString("PLAY MAP 1");
	PLAYm1.setPosition(170, 130-45);
	PLAYm2.setString("PLAY MAP 2");
	PLAYm2.setPosition(170, 130+45);
	EXIT.setString(" EXIT");
	EXIT.setPosition(240, 130 * 3);
	WIN.setString(" WIN");
	WIN.setPosition(240, 130 * 2);

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

		PLAYm1.setFillColor(sf::Color(82, 127, 57));
		PLAYm2.setFillColor(sf::Color(82, 127, 57));
		EXIT.setFillColor(sf::Color(82, 127, 57));
		WIN.setFillColor(sf::Color::Red);


		menuNum = 0;
		//window.clear(sf::Color(32, 70, 49));

		if (sf::IntRect(170, 130 - 45, 300, 55).contains(sf::Mouse::getPosition(window))) {
			PLAYm1.setFillColor(sf::Color(174, 196, 64)); menuNum = 1; play1(time, hero_memu, hx); hero_memu.setPosition(hx, hy);
		} else

		if (sf::IntRect(170, 130 + 45, 300, 55).contains(sf::Mouse::getPosition(window))) {
			PLAYm2.setFillColor(sf::Color(174, 196, 64)); menuNum = 2; play1(time, hero_memu, hx); hero_memu.setPosition(hx, hy);
		}
		else {
			hero_memu.setPosition(50, 25); hx = 50;
			hy = 25;
		}


		if (sf::IntRect(240, 130 * 3, 125, 55).contains(sf::Mouse::getPosition(window))) {

			EXIT.setFillColor(sf::Color(174, 196, 64)); menuNum = 3; play2(time, grip_memu, gx); grip_memu.setPosition(gx, gy);

		}
		else {
			grip_memu.setPosition(50, 525); gx = 50;
			gy = 525;
		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 1) {
				isMenu = false;
				_mapN = 1;
				std::cout << _mapN << std::endl;
			}
			if (menuNum == 2) {
				isMenu = false;
				_mapN = 2;
				std::cout << _mapN << std::endl;
			}
			//if (menuNum == 2) { window.draw(about); window.display(); while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)); }

			if (menuNum == 3) { 
				window.close();
				isMenu = false;
				record_file.close();
				std::fstream record_file2("record.txt", std::ios::trunc | std::ios::out | std::ios::in);
				record_file2 << SESSION_RECORD;
				std::cout << "out: " << SESSION_RECORD;
				record_file2.close();
			}


		}

		//window.draw(menuBg);
		//window.draw(menu1);
		window.clear();
		window.setView(window.getDefaultView());
		window.clear(sf::Color(32, 70, 49));
		if (_tip == 3)window.draw(WIN);
		if (_tip == 2)window.draw(LOSS);
		window.draw(hero_memu);
		window.draw(grip_memu);
		window.draw(EXIT);

		window.draw(PLAYm1);
		window.draw(PLAYm2);
    window.draw(RECORD);
		window.display();
	}
	if (_mapN == 1) { mapee.initialize(); std::cout << _mapN << std::endl;
	}
	if (_mapN == 2) { mapee2.initialize(); std::cout << _mapN << std::endl;
	}
	__mapN = _mapN;
	//mapee.initialize();
	return _mapN;
}

int Menu::get_mapN() {
	return __mapN;
}