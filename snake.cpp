#include<chrono>

#include "snake.h"

using namespace std::chrono_literals;

snake::snake()
{
	// every sprite will be 40px by 40px
	head_texture.loadFromFile("snake_head.png");
	tail_texture.loadFromFile("snake_part.png");

	head_sprite.setTexture(head_texture);
	tail_sprite.setTexture(tail_texture);

	sf::Sprite copy_sprite = head_sprite;
	copy_sprite.setPosition(sf::Vector2f(400, 400));
	snake_parts.push_back(copy_sprite);

	copy_sprite = tail_sprite;
	copy_sprite.setPosition(sf::Vector2f(400, 440));
	snake_parts.push_back(copy_sprite);
	copy_sprite.setPosition(sf::Vector2f(400, 480));
	snake_parts.push_back(copy_sprite);
}

auto snake::update() -> void
{
	if ((std::chrono::system_clock::now() - last) > 0.25s)
	{
		int amount_to_move = 40;
		if (direction == 1)
		{
			sf::Sprite copy_sprite = tail_sprite;
			copy_sprite.setPosition(snake_parts[0].getPosition());
			snake_parts[0].move(0, -amount_to_move);
			for (int i = 1; i < snake_parts.size(); i++)
			{
				sf::Sprite temp = snake_parts[i];
				snake_parts[i].setPosition(copy_sprite.getPosition());
				copy_sprite = temp;
			}
		}
		if (direction == 0.5)
		{
			sf::Sprite copy_sprite = tail_sprite;
			copy_sprite.setPosition(snake_parts[0].getPosition());
			snake_parts[0].move(amount_to_move, 0);
			for (int i = 1; i < snake_parts.size(); i++)
			{
				sf::Sprite temp = snake_parts[i];
				snake_parts[i].setPosition(copy_sprite.getPosition());
				copy_sprite = temp;
			}
		}
		if (direction == 0)
		{
			sf::Sprite copy_sprite = tail_sprite;
			copy_sprite.setPosition(snake_parts[0].getPosition());
			snake_parts[0].move(0, amount_to_move);
			for (int i = 1; i < snake_parts.size(); i++)
			{
				sf::Sprite temp = snake_parts[i];
				snake_parts[i].setPosition(copy_sprite.getPosition());
				copy_sprite = temp;
			}
		}
		if (direction == -0.5)
		{
			sf::Sprite copy_sprite = tail_sprite;
			copy_sprite.setPosition(snake_parts[0].getPosition());
			snake_parts[0].move(-amount_to_move, 0);
			for (int i = 1; i < snake_parts.size(); i++)
			{
				sf::Sprite temp = snake_parts[i];
				snake_parts[i].setPosition(copy_sprite.getPosition());
				copy_sprite = temp;
			}
		}

		if (snake_parts[0].getPosition().x < 0)
		{
			snake_parts[0].setPosition(sf::Vector2f(760, snake_parts[0].getPosition().y));
		}
		if (snake_parts[0].getPosition().x >= 800)
		{
			snake_parts[0].setPosition(sf::Vector2f(0, snake_parts[0].getPosition().y));
		}
		if (snake_parts[0].getPosition().y < 0)
		{
			snake_parts[0].setPosition(sf::Vector2f(snake_parts[0].getPosition().x, 760));
		}
		if (snake_parts[0].getPosition().y >= 800)
		{
			snake_parts[0].setPosition(sf::Vector2f(snake_parts[0].getPosition().x, 0));
		}

		last = std::chrono::system_clock::now();
	}
}

auto snake::addPart() -> void
{
	// so we need to add a part to the end of the snake
	// we need to record the last move that the user took, which is in direction
	if (direction == 1)
	{
		// we need to plus 40 to the y position of the last sprite in the snake_parts vector.
		sf::Sprite copy_sprite = snake_parts[snake_parts.size() - 1];
		copy_sprite.move(0, 40);
		snake_parts.push_back(copy_sprite);
	}
	if (direction == 0)
	{
		// we need to plus 40 to the y position of the last sprite in the snake_parts vector.
		sf::Sprite copy_sprite = snake_parts[snake_parts.size() - 1];
		copy_sprite.move(0, -40);
		snake_parts.push_back(copy_sprite);
	}
	if (direction == 0.5)
	{
		// we need to plus 40 to the y position of the last sprite in the snake_parts vector.
		sf::Sprite copy_sprite = snake_parts[snake_parts.size() - 1];
		copy_sprite.move(-40, 0);
		snake_parts.push_back(copy_sprite);
	}
	if (direction == -0.5)
	{
		// we need to plus 40 to the y position of the last sprite in the snake_parts vector.
		sf::Sprite copy_sprite = snake_parts[snake_parts.size() - 1];
		copy_sprite.move(40, 0);
		snake_parts.push_back(copy_sprite);
	}
}

auto snake::moveLeft() -> void
{
	if (direction != 0.5)
	{
		direction = -0.5;
	}
}

auto snake::moveRight() -> void
{
	if (direction != -0.5)
	{
		direction = 0.5;
	}
}

auto snake::moveUp() -> void
{
	if (direction != 0)
	{
		direction = 1;
	}
}

auto snake::moveDown() -> void
{
	if (direction != 1)
	{
		direction = 0;
	}
}

auto snake::draw(sf::RenderWindow& w) -> void
{
	if (!dead)
	{
		for (auto& s : snake_parts)
		{
			w.draw(s);
		}
		w.draw(snake_parts[0]); // so that the head appears above everything else.
	}
}