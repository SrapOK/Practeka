#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"

//sf::View view1;
sf::RenderWindow window(sf::VideoMode(600, 400), "My window");
sf::View view1;

int main(int artv, char** argc)
{

    view1.reset(sf::FloatRect(0, 0, 640, 480));
    

    //sf::Image map_image;
    //map_image.loadFromFile("map.png");
    //sf::Texture map;
    //map.loadFromImage(map_image);
    //sf::Sprite _s_map;
    //_s_map.setTexture(map);


    Map M1("Gameboy Tileset.png", 2);

    sf::Clock clock;
    // ������ �������� � ����������(�� ���������� ������)
    Manager <Creature> manager;
    Creature hero(100, 100, 16, 16);
    //������� �����, ����� �� ���������� ������ ��������� � ����������� AnimationCreature
    Animation* walk = new Animation("rmove", "Walk.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16);
    hero.add_animation(*walk);
    hero.add_animation(*base);
    hero.set_default_sprite(*base);

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMilliseconds();
        clock.restart();
        

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }

        //if (time ) �������� ����������� �� update

        //���������� � update;
        hero.get_command(time);


        //GetPlayerCoordinateForView(100, 100);
        //viewmap(time);
        window.setView(view1);

        window.clear();

        M1.Print();
        window.draw(hero.sprite());
        
        window.display();
    }
    return 0;
}