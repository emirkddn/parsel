#include <SFML/Graphics.hpp>
#include "LinkedlistEntity.h"
#include "Arrow.h"

int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Linkedlist");

    LinkedlistEntity entity1(window);
    LinkedlistEntity entity2(window);
    LinkedlistEntity entity3(window);
    Arrow arrow(window);

    while (window.isOpen()){

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        entity2.setPosition(sf::Vector2f(150.f,0.f));
        entity3.setPosition(sf::Vector2f(-150.f,0.f));

        entity2.setAddress("0x11122");
        entity2.setData("13");

        window.draw(entity1);
        //window.draw(entity2);
        //window.draw(entity3);
        window.draw(arrow);
        window.display();

    }

    return 0;

}
