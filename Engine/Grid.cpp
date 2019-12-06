#include "Grid.h"

Grid::Grid(int& step)
	:
	snake({gridWidth / 2, gridHeight / 2}, Colors::Blue),
	apple(Colors::Yellow),
	step(step)
{
	apple.Spawn(gridWidth, gridHeight);
}

void Grid::Draw(Graphics & gfx)
{

	for (int i = 0; i < snake.GetActualSegments(); i++)
	{
		Segment s = snake.GetSegment(i);

		int x = s.GetPosition().x;
		int y = s.GetPosition().y;
		
		gfx.DrawRectangle(x * tilesWidth, y * tilesHeight, tilesWidth, tilesHeight, s.GetColor());
	}

	gfx.DrawRectangle(snake.GetPosition().x * tilesWidth, snake.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, snake.GetHeadColor());
	gfx.DrawRectangle(apple.GetPosition().x * tilesWidth, apple.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, apple.GetColor());
}

void Grid::Update(char input)
{
	snake.SetDelta(input);

	if (!gameOver && !snake.LoseCondition(gridWidth, gridHeight))
	{
		if (snake.CollidingWithApple(apple))
		{
			apple.Spawn(gridWidth, gridHeight);
			snake.Grow();

			score++;

			if (score % 3 == 0)
			{
				step -= 1;
			}
		}

		snake.Update();
	}
	else
	{
		gameOver = true;
	}
}

bool Grid::GameOver() const
{
	return gameOver;
}
