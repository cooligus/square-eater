//
// Created by jarek on 11/14/23.
//

#include "Brick.h"

#include <iostream>
#include <random>

Brick::Brick(Direction dir, sf::Vector2u windowSize):m_windowSize(windowSize), m_size(30) {
    sf::Color color;
    float posX = 0, posY = 0;
    m_dir = dir;

    std::mt19937 mt{std::random_device{}()};
    std::uniform_real_distribution<> randomX{0, (double)windowSize.x};
    std::uniform_real_distribution<> randomY{0, (double)windowSize.y};

    switch (dir) {
        case up:
            color = sf::Color::Magenta;
            posX = randomX(mt);
            posY = windowSize.y + m_size;
            break;
        case right:
            color = sf::Color::Green;
            posX -= m_size;
            posY = randomY(mt);
            break;
        case down:
            color = sf::Color::Yellow;
            posX = randomX(mt);
            posY -= m_size;
            break;
        case left:
            color = sf::Color::White;
            posX = windowSize.x + m_size;
            posY = randomY(mt);
            break;
        default: ;
    }
    m_shape.setPosition(posX, posY);
    m_shape.setSize(sf::Vector2f(m_size, m_size));
    m_shape.setFillColor(color);
}

bool Brick::isItOutside() const {
    const sf::Vector2f pos = m_shape.getPosition();
    if(m_dir == up && pos.y + m_size < 0) {
        return true;
    }
    if(m_dir == right && pos.x > m_windowSize.x) {
        return true;
    }
    if(m_dir == down&& pos.y > m_windowSize.y) {
        return true;
    }
    if(m_dir == left && pos.x + m_size < 0) {
        return true;
    }
    return false;
}