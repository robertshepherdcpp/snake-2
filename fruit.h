#pragma once

#include<random>

#include<SFML/Graphics.hpp>

struct fruit
{
	fruit();

	auto die() -> void;

	auto random_position() -> int;

	auto draw(sf::RenderWindow& w) -> void;

	bool dead = false;

	sf::Texture t;
	sf::Sprite s;
};