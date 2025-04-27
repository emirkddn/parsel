#include "LinkedlistEntity.h"

LinkedlistEntity::LinkedlistEntity(){
    rectangle.setSize(sf::Vector2f(100.f, 100.f));
    rectangle.setFillColor(sf::Color(100, 250, 50));
    rectangle.setPosition(0, 0);
}

void LinkedlistEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangle, states);
}