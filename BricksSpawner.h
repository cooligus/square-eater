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
    sf::Clock m_clock;
    bool m_spawn;
    float m_resetPeriod;
    sf::Vector2u m_windowSize;
    bool m_collisionHappened;
public:
    explicit BricksSpawner(sf::Vector2u windowSize);
    void moveAndDraw(sf::RenderWindow& window);
    bool collsionHappened();
    bool spawn();
    bool areCollisionsOnSite(MovableRectangle player);
};

#endif //BRICKSSPAWNER_H
