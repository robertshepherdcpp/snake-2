#include <SFML/Graphics.hpp>

#include "snake.h"
#include "fruit.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    snake s{};
    std::vector<fruit> f{ fruit{} };

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A) { s.moveLeft(); }
                if (event.key.code == sf::Keyboard::W) { s.moveUp(); }
                if (event.key.code == sf::Keyboard::S) { s.moveDown(); }
                if (event.key.code == sf::Keyboard::D) { s.moveRight(); }
                if (event.key.code == sf::Keyboard::X) { s.snake_parts[0].setPosition(sf::Vector2f(400, 400)); }
            }
        }

        s.update();

        for (const auto& x : s.snake_parts)
        {
            for (auto& f_s : f)
            {
                if (x.getGlobalBounds().intersects(f_s.s.getGlobalBounds()) && f_s.dead != true)
                {
                    f_s.dead = true;
                    f.push_back(fruit{});
                    s.addPart();
                }
            }
        }

        window.clear();
        s.draw(window);
        for (auto& x : f)
        {
            x.draw(window);
        }
        window.display();
    }

    return 0;
}