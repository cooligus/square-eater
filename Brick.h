//
// Created by jarek on 11/14/23.
//

#ifndef EATER_H
#define EATER_H

#include <SFML/Graphics.hpp>

enum Direction {
    right,
    left,
    down,
    up,
    none,
};

class Brick : public sf::RectangleShape {
protected:
    sf::Clock m_clock;
    Direction m_dir;
    float m_speed;
    sf::Vector2u m_windowSize;
    float m_size;

public:
    Brick(Direction dir, sf::Vector2u windowSize);

    Brick();

    Brick(float posX, float posY, float size, float speed, sf::Color color, sf::Vector2u windowSize,
          Direction direction);

    void draw(sf::RenderWindow&window);

    void changeDirection(Direction dir);

    void go();

    void resetTimer();

    bool isOutisde() const;

    sf::FloatRect getBounds() const;
};


#endif //EATER_H
