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

        sf::RenderWindow window(sf::VideoMode({800, 600}), "Linkedlist");
    
        std::vector<LinkedlistEntity> entities;

        //LinkedlistEntity entity1(window);
        //LinkedlistEntity entity2(window);
        //LinkedlistEntity entity3(window);

        //Arrow arrow(window);

        Node* temp = head;

        int initialPositionX = 0;
        int initialPositionY = 0;
    
        while (temp != nullptr) {
            LinkedlistEntity entity(window);
            entity.setPosition(sf::Vector2f(initialPositionX, initialPositionY));
            entity.setData(std::to_string(temp->data));
            
            std::stringstream ss;
            ss << temp;
            entity.setAddress(ss.str());
        
            entities.push_back(entity);
        
            initialPositionX += 110;
            temp = temp->next;
        }

        while (window.isOpen()){
    
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
    
            window.clear(sf::Color::Black);
    
            //entity2.setPosition(sf::Vector2f(150.f,0.f));
            //entity3.setPosition(sf::Vector2f(-150.f,0.f));
    
            //entity2.setAddress("0x11122");
            //entity2.setData("13");
    
            //window.draw(entity1);
            //window.draw(entity2);
            //window.draw(entity3);
            //window.draw(arrow);

            for (auto& entity : entities) {
                window.draw(entity);
            }

            window.display();
    
        }
    
    }

};

int main() {

    Linkedlist list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    list.parsel();

}
