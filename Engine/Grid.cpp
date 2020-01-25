#include "Grid.h"

Grid::Grid()
	:
	snake({6, 10})
{
	apple.Spawn(snake);
}

void Grid::Draw(Graphics & gfx)
{

	gfx.DrawRectangle(snake.GetPosition().x * tilesWidth, snake.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, snake.GetColor());
	
	gfx.DrawRectangle(apple.GetPosition().x*tilesWidth, apple.GetPosition().y*tilesHeight, tilesWidth, tilesHeight, apple.GetColor());

	for (int i = 0; i < snake.GetActualSegments(); i++)
	{
		int x = snake.GetSegment(i).GetPosition().x * tilesWidth;
		int y = snake.GetSegment(i).GetPosition().y * tilesHeight;
		Color color = snake.GetSegment(i).GetColor();
		gfx.DrawRectangle(x, y, tilesWidth, tilesHeight, color);
	}
}

void Grid::Update(char input)
{
	snake.TakeInput(input);
	Eating();
	snake.MoveSegments();
	snake.Move();
}

void Grid::Eating()
{
	if (apple.GetPosition() == snake.GetPosition())
	{
		snake.Grow();
		apple.Spawn(snake);
	}
}
