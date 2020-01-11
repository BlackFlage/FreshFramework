#include "Apple.h"

void Apple::Spawn(Snake& snake)
{
	std::random_device rd{};
	std::mt19937 rng(rd());

	std::uniform_int_distribution<int> xDist(0,19);
	std::uniform_int_distribution<int> yDist(0,14);

	Vector2 pos = { xDist(rng), yDist(rng) };

	while (true)
	{
		bool found = false;
		if (pos != snake.GetPosition())
		{
			for (int i = 0; i < snake.GetActualSegments(); i++)
			{
				if (pos == snake.GetSegments(i).GetPosition())
				{
					found = true;
				}
			}
		}
		if (!found)
		{
			break;
		}
		else
		{
			pos = { xDist(rng), yDist(rng) };
		}
	}

	position = pos;

}

Vector2 Apple::GetPosition() const
{
	return position;
}

Color Apple::GetColor() const
{
	return color;
}
