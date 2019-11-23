#include "Grid.h"

void Grid::Draw(Graphics & gfx)
{
	gfx.DrawRectangle(13, 15, 20, 25, Colors::Blue);
	gfx.DrawRectangle(50, 60, 10, 15, Color({ 255,0,0 }));
	gfx.DrawRectangle(150, 200, 30, 40, { 0,255,0 });
}
