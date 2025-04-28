#include <SFML/Graphics.hpp>
#include "LinkedlistEntity.h"

int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Linkedlist");

    LinkedlistEntity entity1(window);

    while (window.isOpen()){

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(entity1);
        window.display();

    }

    return 0;

}
