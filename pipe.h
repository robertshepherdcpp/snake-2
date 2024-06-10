#pragma once

#include<SFML/Graphics.hpp>

struct pipe
{
	pipe(int x, int y);

	auto move() -> void; // moves by 1px;

	auto print(sf::RenderWindow& w) -> void;

	bool dead = false;

	sf::Texture t;
	sf::Sprite s;
};