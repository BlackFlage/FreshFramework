#include "Apple.h"

Apple::Apple(Color c)
	:
	color(c)
{
}

void Apple::Spawn(int gridWidth, int gridHeight)
{
	std::random_device rd{};
	std::mt19937 rng(rd());

	std::uniform_int_distribution<int> xDist(0, gridWidth);
	std::uniform_int_distribution<int> yDist(0, gridHeight);

	Vector2 newPosition = Vector2(xDist(rng), yDist(rng));

	position = newPosition;
}
