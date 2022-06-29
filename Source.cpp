#include "Creature.h"
#include "Manager.h"
#include "Map.h"
#include "View.h"

//sf::View view1;
sf::RenderWindow window(sf::VideoMode(600, 600), "My window");
sf::View view1;

void viewmap(float time) { //функция для перемещения камеры по карте


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        view1.move(0.1 * time, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view1.move(0, 0.1 * time);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        view1.move(-0.1 * time, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        view1.move(0, -0.1 * time);
    }

}

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


    Map M1("Gameboy Tileset.png", 2);

    sf::Clock clock;
    // ������ �������� � ����������(�� ���������� ������)
    Manager <Creature> manager;
    Creature hero(100, 320, 16, 16);
    //������� �����, ����� �� ���������� ������ ��������� � ����������� AnimationCreature
    Animation* walkR = new Animation("rmove", "Walk.png", 0, 0, 16, 16);
    Animation* walkL = new Animation("lmove", "WalkL.png", 0, 0, 16, 16);
    Animation* base = new Animation("base", "base.png", 0, 0, 16, 16);
    hero.add_animation(*walkR);
    hero.add_animation(*walkL);
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
        

        getPlayerCoordinateForView(hero.x(), hero.y());
        //viewmap(time);
        window.setView(view1);

        window.clear();

        M1.Print();
        window.draw(hero.sprite());
        
        window.display();
    }
    return 0;
}