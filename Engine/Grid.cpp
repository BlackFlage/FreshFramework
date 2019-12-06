#include "Grid.h"

void Grid::Draw(Snake& snake, Graphics & gfx)
{
	gfx.DrawRectangle(snake.GetPosition().x * tilesWidth, snake.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, snake.GetHeadColor());
}
