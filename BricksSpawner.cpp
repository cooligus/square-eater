//
// Created by jarek on 11/15/23.
//

#include "BricksSpawner.h"

#include <random>
#include <SFML/System/Time.hpp>

BricksSpawner::BricksSpawner(sf::Vector2u windowSize): m_bricksLimit(50), m_spawn(false),
                                                       m_windowSize(windowSize), m_resetPeriod(.1f),
                                                       m_collisionHappened(false) {
}

void BricksSpawner::moveAndDraw(sf::RenderWindow&window) {
    spawn();
    for (int i = 0, size = m_bricks.size(); i < size; i++) {
        m_bricks[i].go();
        m_bricks[i].draw(window);

        if (m_bricks[i].isOutisde()) {
            m_bricks.erase(m_bricks.begin() + i);
        }
    }
}

bool BricksSpawner::collsionHappened() {
    return m_collisionHappened;
}

bool BricksSpawner::spawn() {
    if (m_spawningClock.getElapsedTime().asSeconds() > m_resetPeriod && m_bricks.size() < m_bricksLimit) {
        m_spawningClock.restart();
        std::mt19937 mt{std::random_device{}()};
        std::uniform_int_distribution<> dist{0, 3};
        const Brick brick((Direction)dist(mt), m_windowSize);
        m_bricks.push_back(brick);
        return true;
    }
    return false;
}

bool BricksSpawner::areCollisionsOnSite(Brick player) {
    for (auto brick: m_bricks) {
        if (brick.getBounds().intersects(player.getBounds()))
            m_collisionHappened = true;
    }
}
