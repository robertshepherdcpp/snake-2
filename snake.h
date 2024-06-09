#pragma once

#include<chrono>
#include<vector>

#include<SFML/Graphics.hpp>

struct snake
{
	snake();

	auto update() -> void; // every 0.25 seconds

	auto addPart() -> void; // add another snake part.

	auto moveLeft() -> void;
	auto moveRight() -> void;
	auto moveUp() -> void;
	auto moveDown() -> void;

	auto draw(sf::RenderWindow& w) -> void;

	double direction = 2; // 1 is up, 0.5 is right, 0 is down, -0.5 is left

	std::vector<sf::Sprite> snake_parts{};

	std::chrono::system_clock::time_point last = std::chrono::system_clock::now();

	sf::Texture tail_texture;
	sf::Sprite tail_sprite;

	sf::Texture head_texture;
	sf::Sprite head_sprite;
};