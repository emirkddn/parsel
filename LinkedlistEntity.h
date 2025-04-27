#ifndef LINKEDLISTENTITY_H
#define LINKEDLISTENTITY_H

#include <SFML/Graphics.hpp>

class LinkedlistEntity : public sf::Transformable, public sf::Drawable {
public:
    LinkedlistEntity();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape rectangle;
};

#endif