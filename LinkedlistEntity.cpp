#include "LinkedlistEntity.h"
#include <iostream>

using namespace std;

LinkedlistEntity::LinkedlistEntity(sf::RenderWindow& window){  
    
    if (!font.openFromFile("arial.ttf")) {
        std::cout << "FONT ERROR" << std::endl;
    }

    address.setFont(font);
    address.setString("0x1234");
    address.setCharacterSize(14);
    address.setFillColor(sf::Color::White);

    data.setFont(font);
    data.setString("10");
    data.setCharacterSize(14);
    data.setFillColor(sf::Color::White);
    
    rectangleMain.setSize(sf::Vector2f(100.f, 100.f));
    rectangleMain.setFillColor(sf::Color(100, 250, 50));

    rectangleAdd.setSize(sf::Vector2f(100.f,30.f));
    rectangleAdd.setFillColor(sf::Color(100, 150, 50));
    
    sf::Vector2u windowSize = window.getSize();
    
    //rectangleMain
    float posXmain = (windowSize.x - rectangleMain.getSize().x) / 2.f;
    float posYmain = (windowSize.y - rectangleMain.getSize().y) / 2.f;
    rectangleMain.setPosition(sf::Vector2f(posXmain, posYmain));

    //rectangleAdd
    float posXadd = (windowSize.x - rectangleAdd.getSize().x) / 2.f;
    float posYadd = (windowSize.y - rectangleAdd.getSize().y) / 2.f - 40.f;
    rectangleAdd.setPosition(sf::Vector2f(posXadd, posYadd));
    address.setPosition(sf::Vector2f(posXadd, posYadd));
    
}

void LinkedlistEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(rectangleMain, states);
    target.draw(rectangleAdd, states);
    target.draw(address, states);
    target.draw(data, states);
}

void LinkedlistEntity::setAddress(const std::string& addressStr) {
    address.setString(addressStr);
}

void LinkedlistEntity::setData(const std::string& dataStr) {
    data.setString(dataStr);
}