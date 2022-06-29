#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"

//sf::View view1;
sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
Map mapee("Gameboy Tileset.png", "2.txt");
sf::View view1;
Manager manager;


void getPlayerCoordinateForView(float x, float y) { //функция для считывания координат игрока
    float tempX = x; float tempY = y;//считываем коорд игрока и проверяем их, чтобы убрать края

    if (x < 100) tempX = 100;//убираем из вида левую сторону
    if (y < 100) tempY = 100;//верхнюю сторону
    if (y > 300) tempY = 300;//нижнюю сторону	

    view1.setCenter(tempX, tempY); //следим за игроком, передавая его координаты. 

}


int main(int artv, char** argc)
{
    view1.reset(sf::FloatRect(0, 0, 200, 200));

    sf::Clock clock;
    // ������ �������� � ����������(�� ���������� ������)
    Creature hero(100, 320, 16, 16);
    //������� �����, ����� �� ���������� ������ ��������� � ����������� AnimationCreature
    Animation* walkR = new Animation("rmove", "Walk.png", 0, 0, 16, 16);
    Animation* walkL = new Animation("lmove", "WalkL.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16);
    hero.add_animation(*walkR);
    hero.add_animation(*walkL);
    hero.add_animation(*base);
    hero.set_default_sprite(*base);
    manager.add(&hero);

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
        

        getPlayerCoordinateForView(hero.x(), hero.y());
        //viewmap(time);
        window.setView(view1);

        window.clear();

        mapee.print();
        manager.display();
        
        window.display();
    }
    return 0;
}