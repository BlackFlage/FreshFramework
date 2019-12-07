#pragma once
#include "Graphics.h"
#include "Snake.h"

class Grid
{
public:
	Grid();
	void Draw(Graphics & gfx);
	void Update();

private:
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
	Snake snake;
};