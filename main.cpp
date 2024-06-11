#include<iostream>

#include <SFML/Graphics.hpp>

#include "snake.h"
#include "fruit.h"
#include "pipe_manager.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

    snake s{};
    std::vector<fruit> f{ fruit{} };
    pipe_manager p{};

    int score = 0;
    bool show_pipes = true;

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
                if (event.key.code == sf::Keyboard::Q) { s.dead = false; }
                if (event.key.code == sf::Keyboard::N) { if (show_pipes) { show_pipes = false; } else { show_pipes = true; } }
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
                    score += 1;
                    f.push_back(fruit{});
                    s.addPart();

                    std::cout << "score: " << score << "\n";
                }
            }
        }

        if (show_pipes)
        {
            for (const auto& x : p.pipes)
            {
                for (const auto& y : s.snake_parts)
                {
                    if (x.first.s.getGlobalBounds().intersects(y.getGlobalBounds()) || x.second.s.getGlobalBounds().intersects(y.getGlobalBounds()))
                    {
                        s.dead = true;
                    }
                }
            }
        }

        if (show_pipes)
        {
            p.update();
        }

        window.clear();
        s.draw(window);
        for (auto& x : f)
        {
            x.draw(window);
        }
        if (show_pipes)
        {
            p.print(window);
        }
        window.display();
    }

    return 0;
}