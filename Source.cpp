#include "Creature.h"
#include "Manager.h"
#include "Map.h"
sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

int main(int artv, char** argc)
{
    Map M1("map.png", 1);
    sf::Clock clock;
<<<<<<< HEAD


    Map M1("map.png", 1);

=======
>>>>>>> 2db793d707db5c2e95e71517da874a640a623d45
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
<<<<<<< HEAD

        for (int i = 0; i < M1.Get_HEIGHT_MAP(); i++)
            for (int j = 0; j < M1.Get_WIDTH_MAP(); j++)
            {
                if (M1.Get_Map()[i][j] == ' ')  M1.s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (M1.Get_Map()[i][j] == 's')  M1.s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
                if ((M1.Get_Map()[i][j] == '0')) M1.s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик


                M1.s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

                window.draw(M1.s_map);//рисуем квадратики на экран
            }
=======
        M1.Print();
>>>>>>> 2db793d707db5c2e95e71517da874a640a623d45

        window.display();
    }
	return 0;
}