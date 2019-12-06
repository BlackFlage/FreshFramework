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

	std::uniform_int_distribution<int> xDist(0, gridWidth - 1);
	std::uniform_int_distribution<int> yDist(0, gridHeight - 1);

	Vector2 newPosition = Vector2(xDist(rng), yDist(rng));

	position = newPosition;
}

Color Apple::GetColor() const
{
	return color;
}

Vector2 Apple::GetPosition() const
{
	return position;
}
