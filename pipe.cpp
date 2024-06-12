#include "pipe.h"

pipe::pipe(int x, int y)
{
	t.loadFromFile("pipe.png");
	s.setTexture(t);

	s.setColor(sf::Color(19, 82, 4));

	s.setPosition(float(x), float(y));
}

auto pipe::move() -> void
{
	s.move(-1, 0);
}

auto pipe::print(sf::RenderWindow& w) -> void
{
	if (!dead)
	{
		w.draw(s);
	}
}
