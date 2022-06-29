#include "Creature.h"
#include "Manager.h"
#include "Map.h"
sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

int main(int artv, char** argc)
{
    Map M1("map.png", 1);
    sf::Clock clock;
    // Решить проблему с менеджером(не вызываются методы)
    Manager <Creature> manager;
    Creature hero(100, 100, 16, 16);
    //создать метод, чтобы не копировать размер персонажа в констукторы AnimationCreature
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
        //if (time ) дописать ограниченик на update

        //переделать в update;
        hero.get_command(time);
        window.clear();
        M1.Print();
        window.draw(hero.sprite());
        
        window.display();
    }
    return 0;
}