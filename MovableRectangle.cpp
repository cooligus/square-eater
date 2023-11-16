//
// Created by jarek on 11/14/23.
//

#include "MovableRectangle.h"

MovableRectangle::MovableRectangle() : m_shape(sf::Vector2f(0, 0)), m_speed(.3f), m_dir(none){
}

MovableRectangle::MovableRectangle(float posX, float posY, float sizeX, float sizeY, sf::Color color) : m_shape(sf::Vector2f(sizeX, sizeY)), m_speed(.35f), m_dir(none){
    m_shape.setPosition(posX, posY);
    m_shape.setFillColor(color);
}

void MovableRectangle::draw(sf::RenderWindow& window) {
    window.draw(m_shape);
}

void MovableRectangle::changeDirection(Direction dir) {
    m_dir = dir;
}

void MovableRectangle::move() {
    unsigned time = m_clock.getElapsedTime().asMicroseconds();
    float realSpeed = m_speed*(time/1000.f);
    switch (m_dir) {
        case up:
            m_shape.move(0, -realSpeed);
            break;
        case right:
            m_shape.move(realSpeed, 0);
            break;
        case down:
            m_shape.move(0, realSpeed);
            break;
        case left:
            m_shape.move(-realSpeed, 0);
            break;
        default:
            break;
    }
    m_clock.restart();
}

void MovableRectangle::resetTimer() {
    m_clock.restart();
}

sf::FloatRect MovableRectangle::getBounds() const {
    return m_shape.getGlobalBounds();
}

