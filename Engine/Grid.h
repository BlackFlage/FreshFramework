#pragma once
#include "Graphics.h"
#include "Snake.h"

class Grid
{
public:
	void Draw( Snake& snake, Graphics & gfx);
private:
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
	static constexpr int girdWidth = Graphics::ScreenWidth / tilesWidth;
	static constexpr int gridHeight = Graphics::ScreenHeight / tilesHeight;
};