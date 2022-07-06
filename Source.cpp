#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "Menu.h"
#include "View.h"
#include "Hero.h"
#include "Enemy.h"
#include "interface.h"
#include <sstream>

//std::string mapN;
int mapN;
sf::RenderWindow window(sf::VideoMode::VideoMode(600, 600), "Kolobock");

Map mapee("Gameboy Tileset.png", "2.txt");
Map mapee2("Gameboy Tileset.png", "3.txt");
Menu menu;

sf::View view1;
Manager manager;
int SCORE = 0;
int SESSION_RECORD = 0;
std::fstream record_file("record.txt", std::ios::app | std::ios::out | std::ios::in);



int main(int artv, char** argc)
{
    
    //mapee.initialize();
    mapN = menu.menu(window, 1);
    std::cout << mapN << std::endl;

    sf::Font font;
    std::string string_score;
    string_score = "Score: " + std::to_string(SCORE);
    if (font.loadFromFile("Manrope-ExtraLight.ttf"));
    sf::Text text_score("", font, 12);
    text_score.setString(string_score);
    text_score.setFillColor(sf::Color(200, 80, 50));
    int score = 0;

    
    

    view1.reset(sf::FloatRect(0, 0, 200, 200));
    sf::Clock clock;
    bool fl = 0;
    //fl = 0;
    float last_time = 0;
    int counter;
    counter = 0;
    float _time;
    _time = 0;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        counter++;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        time /= 800;

        if (counter >= 20 and counter < 60) {
            _time += time;
            manager.update(time);
        }
        else if (counter == 61) {
            _time /= 40;
            fl = 1;
        }

        if (fl == 1) manager.update(_time);

        window.setView(view1);

        window.clear();
        //std::cout << menu.get_mapN() << std::endl;
        if (menu.get_mapN() == 1) { mapee.print(); }
        if (menu.get_mapN() == 2) { mapee2.print(); }
        
        manager.display();
        string_score = "Score: " + std::to_string(SCORE);
        text_score.setString(string_score);
        text_score.setPosition(view1.getCenter().x + 50, view1.getCenter().y - 94);
        window.draw(text_score);

        
        window.display();
    }
    return 0;
}