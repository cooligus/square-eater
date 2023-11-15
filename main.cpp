#include <iostream>
#include <SFML/Graphics.hpp>

#include "Brick.h"
#include "BricksSpawner.h"
#include "MovableRectangle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Square Eater");
    MovableRectangle eater(30, 30, 100, 100, sf::Color::Red);
    BricksSpawner bricks_spawner(window.getSize());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                switch (event.key.code) {
                    case sf::Keyboard::W:
                        eater.changeDirection(up);
                        break;
                    case sf::Keyboard::D:
                        eater.changeDirection(right);
                        break;
                    case sf::Keyboard::S:
                        eater.changeDirection(down);
                        break;
                    case sf::Keyboard::A:
                        eater.changeDirection(left);
                        break;
                    default: ;
                }
        }

        window.clear();

        bricks_spawner.moveAndDraw(window);

        eater.move();
        eater.draw(window);

        window.display();
    }

    return 0;
}
