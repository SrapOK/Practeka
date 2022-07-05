#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "Menu.h"
#include "View.h"
#include "Hero.h"
#include "Enemy.h"
#include "interface.h"
#include <sstream>

sf::RenderWindow window(sf::VideoMode::VideoMode(600, 600), "My window");

Map mapee("Gameboy Tileset.png", "2.txt");
sf::View view1;
Manager manager;
int SCORE = 0;
int SESSION_RECORD = 0;
std::fstream record_file("record.txt", std::ios::app | std::ios::out | std::ios::in);



int main(int artv, char** argc)
{
    //sf::RenderWindow window(sf::VideoMode(1376, 768), "Kychka-pc.ru 31");
    //mapee.initialize();
    menu(window, 1);
    mapee.initialize();

    sf::Font font;
    std::string string_score;
    string_score = "Score: " + std::to_string(SCORE);
    if (font.loadFromFile("Manrope-ExtraLight.ttf"));
    sf::Text text_score("", font, 12);
    text_score.setString(string_score);
    text_score.setFillColor(sf::Color(200, 80, 50));
    int score = 0;

    /*
    Animation* right = new Animation("right", "Walk.png", 0, 0, 16, 16);
    Animation* left = new Animation("left", "Walk.png", 0, 0, -16, 16);
    Animation* up = new Animation("up", "Jump.png", 0, 0, 16, 16);
    Animation* fall = new Animation("fall", "Fall.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16, 0.003);
    hero->add_animation(right);
    hero->add_animation(left);
    hero->add_animation(up);
    hero->add_animation(fall);
    hero->add_animation(base);
    hero->set_default_sprite(*base);

    Animation* baseGripR = new Animation("baseGripR", "simples_pimples.png", 417, 208, 16, 16, 0.003, 2);
    Animation* baseGripL = new Animation("baseGripL", "simples_pimples.png", 417, 208, -16, 16, 0.003, 2);
    grip->add_animation(baseGripR);
    grip->add_animation(baseGripL);
    
    

    interface st();
    //hp.setPosition(-300, -300);
    */
    

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

        
        mapee.print();
        
        manager.display();
        string_score = "Score: " + std::to_string(SCORE);
        text_score.setString(string_score);
        text_score.setPosition(view1.getCenter().x + 50, view1.getCenter().y - 94);
        window.draw(text_score);

        
        window.display();
    }
    return 0;
}