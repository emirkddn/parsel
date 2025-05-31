#include <vector>
#include <SFML/Graphics.hpp>
#include "LinkedlistEntity.h"
#include "Arrow.h"

class Node {
public:
    Node(int value) : data(value), next(nullptr) {}
    Node(){data=0;next=nullptr;}
    
    int data;
    Node* next;
};
    
class Linkedlist {
public:
    Node* head;
    Linkedlist():head(nullptr){}
    
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    int size() {
        Node* temp = head;
        int counter = 0;
        while (temp != nullptr) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    void parsel(){

        if(head==nullptr) {

            sf::RenderWindow window(sf::VideoMode({800, 600}), "Linkedlist");

            while (window.isOpen()){
    
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>())
                        window.close();
                }
    
                window.clear(sf::Color::Black);
                window.display();
            }

        }

        else {

            sf::RenderWindow window(sf::VideoMode({800, 600}), "Linkedlist");
    
            std::vector<LinkedlistEntity> entities;
            std::vector<Arrow> arrows;

            Node* temp = head;

            int initialPositionX = 0;
            int initialPositionY = 0;
    
            while (temp != nullptr) {
                LinkedlistEntity entity(window);
                entity.setPosition(sf::Vector2f(initialPositionX, initialPositionY));
                entity.setData(std::to_string(temp->data));

                std::stringstream ss;
                ss << &temp->data;
                entity.setAddress(ss.str());

                entities.push_back(entity);

                if (temp->next != nullptr) {
                    Arrow arrow(window);
                    arrow.setPosition(sf::Vector2f(initialPositionX, initialPositionY));
                    arrows.push_back(arrow);
                }

                initialPositionX += 140;
                temp = temp->next;
            }


            while (window.isOpen()){
    
                while (const std::optional event = window.pollEvent())
                {
                    if (event->is<sf::Event::Closed>())
                        window.close();
                }
    
                window.clear(sf::Color::Black);

                for (auto& entity : entities) {
                    window.draw(entity);
                }

                for (auto& arrow : arrows) {
                    window.draw(arrow);
                }

                window.display();
    
            }

        }
    
    }

};

int main() {

    Linkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    list.insert(60);
    
    list.parsel();

}


