#ifndef LINKEDLISTENTITY_H
#define LINKEDLISTENTITY_H

#include <SFML/Graphics.hpp>

class LinkedlistEntity : public sf::Transformable, public sf::Drawable {
public:
    LinkedlistEntity(sf::RenderWindow& window);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    const sf::Text& getAddress() const { return address; }
    const sf::Text& getData() const { return data; }

    void setAddress(const std::string& addressStr);
    void setData(const std::string& dataStr);

private:
    sf::RectangleShape rectangleMain;
    sf::RectangleShape rectangleAdd;
    sf::Text address;
    sf::Text data;
    sf::Font font;
};

#endif