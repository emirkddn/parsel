#ifndef ARROW_H
#define ARROW_H

#include <SFML/Graphics.hpp>

class Arrow : public sf::Transformable, public sf::Drawable {
public:
    Arrow(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
    sf::RectangleShape rectangle;
    sf::ConvexShape triangle;
};


#endif