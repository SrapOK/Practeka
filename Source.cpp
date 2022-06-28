#include "Header.h"



int main(int artv, char** argc)
{
    
    sf::Clock clock;


    Map M1("map.png", 1);

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

        for (int i = 0; i < M1.Get_HEIGHT_MAP(); i++)
            for (int j = 0; j < M1.Get_WIDTH_MAP(); j++)
            {
                if (M1.Get_Map()[i][j] == ' ')  M1.s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
                if (M1.Get_Map()[i][j] == 's')  M1.s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
                if ((M1.Get_Map()[i][j] == '0')) M1.s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������


                M1.s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

                window.draw(M1.s_map);//������ ���������� �� �����
            }

        window.display();
    }
	return 0;
}