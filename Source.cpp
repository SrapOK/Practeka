#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"
#include "Hero.h"
#include "Enemy.h"
#include "interface.h"
#include <sstream>

sf::RenderWindow window(sf::VideoMode::VideoMode(600, 600), "My window");
Map mapee("Gameboy Tileset.png", "2.txt");
sf::View view1;
Manager manager;




int main(int artv, char** argc)
{
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

    float last_time = 0;
    mapee.initialize();
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        time /= 800;
        manager.update(time);

        //getPlayerCoordinateForView(hero->x(), hero->y());

        window.setView(view1);

        window.clear();
        
        mapee.print();
        
        manager.display();
        
        window.display();
    }
    return 0;
}