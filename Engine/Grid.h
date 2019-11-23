#pragma once
#include "Graphics.h"

class Grid
{
public:
	void Draw(/*Snake*/Graphics & gfx);

private:
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
};