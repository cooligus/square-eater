//
// Created by jarek on 11/15/23.
//

#include "BricksSpawner.h"

#include <iostream>

BricksSpawner::BricksSpawner(sf::Vector2u windowSize): m_bricksLimit(10){
    for (int i = 0; i < m_bricksLimit; ++i) {
        Brick brick(right, windowSize);
        m_bricks.push_back(brick);
    }
}

void BricksSpawner::moveAndDraw(sf::RenderWindow &window) {
    for(int i = 0, size = m_bricks.size(); i < size; i++) {
        m_bricks[i].move();
        m_bricks[i].draw(window);
    }
}

bool BricksSpawner::spawn() {
}

bool BricksSpawner::areCollisionsOnSite(MovableRectangle player) {
}

