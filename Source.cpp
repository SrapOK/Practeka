#include "Creature.h"
#include "Manager.h"
#include "Map.h"
sf::RenderWindow window(sf::VideoMode(1920, 400), "My window");

int main(int artv, char** argc)
{

    //sf::Image map_image;
    //map_image.loadFromFile("map.png");
    //sf::Texture map;
    //map.loadFromImage(map_image);
    //sf::Sprite _s_map;
    //_s_map.setTexture(map);


    Map M1("Gameboy Tileset.png", 2);
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
        //M1.s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
        //window.draw(M1.s_map);
        //M1.s_map.setPosition(32, 32);
        

        window.display();
    }
    return 0;
}