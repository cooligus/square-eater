//
// Created by jarek on 11/15/23.
//

#ifndef BRICKSSPAWNER_H
#define BRICKSSPAWNER_H
#include <vector>

#include "Brick.h"


class BricksSpawner {
    std::vector<Brick> m_bricks;
    int m_bricksLimit;
public:
    explicit BricksSpawner(sf::Vector2u windowSize);
    void moveAndDraw(sf::RenderWindow& window);
    bool spawn();
    bool areCollisionsOnSite(MovableRectangle player);
};



#endif //BRICKSSPAWNER_H
