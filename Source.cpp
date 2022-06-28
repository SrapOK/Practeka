#include "Creature.h"
#include "Manager.h"
#include "Map.h"
sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

int main(int artv, char** argc)
{
    Map M1("map.png", 1);
    sf::Clock clock;
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        M1.Print();

        window.display();
    }
    return 0;
}