#include<chrono>
#include<random>

#include "pipe_manager.h"

using namespace std::chrono_literals;

pipe_manager::pipe_manager()
{
}

auto pipe_manager::update() -> void
{
	// takes 4 seconds for the pipes to get accross
	if (std::chrono::system_clock::now() - last >= 0.005s)
	{
		for (auto& x : pipes)
		{
			x.first.move();
			x.second.move();

			if (x.first.s.getPosition().x < 0 && x.first.dead != true)
			{
				x.first.dead = true;
				x.second.dead = true;

				int random_first = random_pipe_one();
				pipes.push_back(std::pair<pipe, pipe>{pipe{ 760, random_first }, pipe{760, random_pipe_two(random_first + 680)}});
			}
		}
		last = std::chrono::system_clock::now();
	}
}

auto pipe_manager::print(sf::RenderWindow& w) -> void
{
	for (auto& x : pipes)
	{
		x.first.print(w);
		x.second.print(w);
	}
}

auto pipe_manager::random_pipe_one() -> int
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 380);

	return 0 - dist6(rng);
}

auto pipe_manager::random_pipe_two(int start) -> int
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(start, 700);

	return dist6(rng);
}
