#include "Grid.h"

Grid::Grid()
	:
	snake({6, 10})
{
}

void Grid::Draw(Graphics & gfx)
{

	gfx.DrawRectangle(snake.GetPosition().x * tilesWidth, snake.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, snake.GetColor());
}

void Grid::Update(char input)
{
	snake.TakeInput(input);
	snake.Move();
	snake.MoveSegments();
}