//
// Created by jarek on 11/14/23.
//

#include "MovableRectangle.h"

#include <iostream>

void MovableRectangle::setNewPos(float x, float y) {
    const auto pos = m_shape.getPosition();
    m_shape.setPosition(pos.x +x, pos.y + y);
}

MovableRectangle::MovableRectangle() : m_shape(sf::Vector2f(0, 0)), m_speed(.05f), m_dir(none){
}

MovableRectangle::MovableRectangle(float posX, float posY, float sizeX, float sizeY, sf::Color color) : m_shape(sf::Vector2f(sizeX, sizeY)), m_speed(.06f), m_dir(none){
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
    switch (m_dir) {
        case up:
            setNewPos(0, -m_speed);
            break;
        case right:
            setNewPos(m_speed, 0);
            break;
        case down:
            setNewPos(0, m_speed);
            break;
        case left:
            setNewPos(-m_speed, 0);
            break;
        default:
            break;
    }
}

sf::FloatRect MovableRectangle::getBounds() const {
    return m_shape.getGlobalBounds();
}

