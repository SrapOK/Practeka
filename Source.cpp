#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"
#include "Hero.h"
#include "Enemy.h"

sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
Map mapee("Gameboy Tileset.png", "2.txt");
sf::View view1;
Manager manager;




int main(int artv, char** argc)
{
    Creature* hero = new Hero(100, 320, 16, 16);
    Creature* grip = new Enemy(200, 320, 16, 16);
    Animation* right = new Animation("right", "Walk.png", 0, 0, 16, 16);
    Animation* left = new Animation("left", "Walk.png", 16, 0, -16, 16);
    Animation* up = new Animation("up", "Jump.png", 0, 0, 16, 16);
    Animation* fall = new Animation("fall", "Fall.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16, 0.003);

    hero->add_animation(right);
    hero->add_animation(left);
    hero->add_animation(up);
    hero->add_animation(fall);
    hero->add_animation(base);
    hero->set_default_sprite(*base);
    grip->add_animation(base);

    view1.reset(sf::FloatRect(0, 0, 200, 200));
    sf::Clock clock;

    float last_time = 0;
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        time /= 800;
        manager.update(time);

        getPlayerCoordinateForView(hero->x(), hero->y());

        window.setView(view1);

        window.clear();

        mapee.print();
        manager.display();
        
        window.display();
    }
    return 0;
}