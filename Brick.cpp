//
// Created by jarek on 11/14/23.
//

#include "Brick.h"
#include <random>

Brick::Brick() : Brick(0, 0, 20, .3f, sf::Color::Blue, sf::Vector2u(), none) {
}

Brick::Brick(float posX, float posY, float size, float speed, sf::Color color, sf::Vector2u windowSize,
             Direction dir) : m_speed(speed), m_dir(none), m_size(size), m_windowSize(windowSize) {
    this->setSize(sf::Vector2f(m_size, m_size));
    this->setPosition(posX, posY);
    this->setFillColor(color);
}

Brick::Brick(Direction dir, sf::Vector2u windowSize)
    : Brick(.0f, .0f, 30.f, .35f, sf::Color::Red, windowSize, none) {
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
    this->setPosition(posX, posY);
    this->setSize(sf::Vector2f(m_size, m_size));
    this->setFillColor(color);
}

void Brick::draw(sf::RenderWindow&window) {
    window.draw(*this);
}

void Brick::changeDirection(Direction dir) {
    m_dir = dir;
}

void Brick::go() {
    unsigned time = m_clock.getElapsedTime().asMicroseconds();
    float realSpeed = m_speed * (time / 1000.f);
    switch (m_dir) {
        case up:
            this->move(0, -realSpeed);
            break;
        case right:
            this->move(realSpeed, 0);
            break;
        case down:
            this->move(0, realSpeed);
            break;
        case left:
            this->move(-realSpeed, 0);
            break;
        default:
            break;
    }
    m_clock.restart();
}

void Brick::resetTimer() {
    m_clock.restart();
}

sf::FloatRect Brick::getBounds() const {
    return this->getGlobalBounds();
}


bool Brick::isOutisde() const {
    const sf::Vector2f pos = this->getPosition();
    if (m_dir == up && pos.y + m_size < 0) {
        return true;
    }
    if (m_dir == right && pos.x > m_windowSize.x) {
        return true;
    }
    if (m_dir == down && pos.y > m_windowSize.y) {
        return true;
    }
    if (m_dir == left && pos.x + m_size < 0) {
        return true;
    }
    return false;
}
