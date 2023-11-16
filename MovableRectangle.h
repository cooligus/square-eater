//
// Created by jarek on 11/14/23.
//

#ifndef EATER_H
#define EATER_H

#include <SFML/Graphics.hpp>

enum Direction {
    right ,
    left,
    down,
    up,
    none,
};

class MovableRectangle {
protected:
    sf::RectangleShape m_shape;
    Direction m_dir;
    float m_speed;
public:
    MovableRectangle();
    MovableRectangle(float posX, float posY, float sizeX, float sizeY, sf::Color color);
    void draw(sf::RenderWindow &window);
    void changeDirection(Direction dir);
    void move();
    sf::FloatRect getBounds() const;
};



#endif //EATER_H
