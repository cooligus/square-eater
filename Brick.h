//
// Created by jarek on 11/14/23.
//

#ifndef BRICK_H
#define BRICK_H
#include "MovableRectangle.h"


class Brick: public MovableRectangle{
    sf::Vector2u m_windowSize;
    float m_size;
public:
    Brick(Direction dir, sf::Vector2u windowSize);
    bool isItOutside() const;
};



#endif //BRICK_H
