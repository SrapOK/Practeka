#include "interface.h"
#include "Hero.h"
/*extern sf::RenderWindow window;

interface::interface(std::string __tipe) {
    sf::Font font;
    font.loadFromFile("Manrope-VariableFont_wght.ttf");
    sf::Text text("", font, 20);
    _text = text;

    //text.setString(c);
    //text.setPosition(this->x(), this->y());
    //window.draw(text);
}

void interface::setPosition(int x, int y) {
    _text.setString(c);
    _text.setPosition(this->x(), this->y());
}*/
interface::interface() {
    sf::Font font;
    font.loadFromFile("Manrope-ExtraLight.ttf");
    sf::Text text("", font, 15);
    text.setString("Pizda tebe chelik");
    text.setPosition(0, 0);
    _text = text;
}

void interface::die() {
    /*sf::Font font;
    font.loadFromFile("Manrope-ExtraLight.ttf");
    sf::Text text("", font, 15);
    text.setString("Pizda tebe chelik");
    text.setPosition(0, 0);
    _text = text;*/

}

sf::Text interface::getText() {
    return _text;
}
