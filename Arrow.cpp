#include "Arrow.h"

Arrow::Arrow(sf::RenderWindow& window) {

    rectangle.setSize(sf::Vector2f(50.f, 5.f));
    rectangle.setFillColor(sf::Color(100, 250, 50));

    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(0.f, 10.f));
    triangle.setPoint(2, sf::Vector2f(10.f, 5.f));
    triangle.setFillColor(sf::Color(100, 250, 50));

    sf::Vector2u windowSize = window.getSize();

    //float posXmain = (windowSize.x - rectangle.getSize().x) / 2.f;
    float posXmain = 95.f;
    float posYmain = (windowSize.y - rectangle.getSize().y) / 2.f;

    rectangle.setPosition(sf::Vector2f(posXmain, posYmain));
    triangle.setPosition(sf::Vector2f(posXmain + 50.f, posYmain - 3.f));

}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
    target.draw(triangle, states);
}