#include <sstream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Brick.h"
#include "BricksSpawner.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Square Eater");
    Brick eater(400, 400, 40, .35f, sf::Color::Red, window.getSize(), none);
    BricksSpawner bricks_spawner(window.getSize());

    sf::Font font;
    font.loadFromFile("./font.otf");

    sf::Text text;
    text.setString("Click space to start");
    text.setColor(sf::Color::White);
    text.setFont(font);
    text.setCharacterSize(20);

    sf::Clock gameTime;

    bool started = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
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
                    case sf::Keyboard::Space:
                        started = true;
                        eater.resetTimer();
                        gameTime.restart();
                        break;
                    default: ;
                }
        }

        window.clear();

        if (started) {
            bricks_spawner.moveAndDraw(window);

            eater.go();

            if (eater.isOutisde())
                eater.setPosition(400, 400);


            bricks_spawner.areCollisionsOnSite(eater);
            if (bricks_spawner.collsionHappened()) {
                started = false;

                std::stringstream s;
                s << gameTime.getElapsedTime().asMilliseconds() / 1000.f;
                std::string result = s.str();

                text.setString("Your time: " + result);
                gameTime.restart();
                bricks_spawner = BricksSpawner(window.getSize());
            }
        }
        eater.draw(window);
        if (!started)
            window.draw(text);
        window.display();
    }

    return 0;
}
