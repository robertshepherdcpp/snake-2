#include "fruit.h"

fruit::fruit()
{
	t.loadFromFile("fruit.png");
	s.setTexture(t);

	s.setPosition(sf::Vector2f(random_position(), random_position()));
}

auto fruit::die() -> void
{
	dead = true;
}

auto fruit::random_position() -> int
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 19);

	return dist6(rng) * 40;
}

auto fruit::draw(sf::RenderWindow& w) -> void
{
	if (!dead)
	{
		w.draw(s);
	}
}
