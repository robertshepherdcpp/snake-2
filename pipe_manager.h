#pragma once

#include<chrono>
#include<utility>

#include<SFML/Graphics.hpp>

#include "pipe.h"

struct pipe_manager
{
	pipe_manager();

	auto update() -> void; // if pipe out of bounds, it's dead value is set to true.

	auto print(sf::RenderWindow& w) -> void;

	auto random_pipe_one() -> int;
	auto random_pipe_two(int start) -> int;

	// stores a pair of pipes, first pipe is upper pipe, second is lower pipe.
	std::vector<std::pair<pipe, pipe>> pipes{ {pipe{760, -160}, pipe{760, 680} }};

	std::chrono::system_clock::time_point last = std::chrono::system_clock::now();
};