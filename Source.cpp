#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"

sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
Map mapee("Gameboy Tileset.png", "2.txt");
sf::View view1;
Manager manager;




int main(int artv, char** argc)
{
    view1.reset(sf::FloatRect(0, 0, 200, 200));
    sf::Clock clock;
    Creature hero(100, 320, 16, 16);
    Animation* walkR = new Animation("rmove", "Walk.png", 0, 0, 16, 16);
    Animation* walkL = new Animation("lmove", "WalkL.png", 0, 0, 16, 16);

    Animation* walkA = new Animation("amove", "Jump.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16);
    hero.add_animation(*walkR);
    hero.add_animation(*walkL);
    hero.add_animation(*walkA);
    hero.add_animation(*base);

    hero.set_default_sprite(*base);

    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        //if (time ) �������� ����������� �� update

        //���������� � update;
        manager.update(time);
        

        getPlayerCoordinateForView(hero.x(), hero.y());

        window.setView(view1);

        window.clear();

        mapee.print();
        manager.display();
        
        window.display();
    }
    return 0;
}