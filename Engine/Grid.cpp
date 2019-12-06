#include "Grid.h"

void Grid::Draw(Snake& snake, Graphics & gfx)
{

	for (int i = 0; i < snake.GetActualSegments(); i++)
	{
		Segment s = snake.GetSegment(i);

		int x = s.GetPosition().x;
		int y = s.GetPosition().y;
		
		gfx.DrawRectangle(x * tilesWidth, y * tilesHeight, tilesWidth, tilesHeight, s.GetColor());
	}

	gfx.DrawRectangle(snake.GetPosition().x * tilesWidth, snake.GetPosition().y * tilesHeight, tilesWidth, tilesHeight, snake.GetHeadColor());
}
