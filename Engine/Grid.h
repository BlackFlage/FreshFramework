#pragma once
#include "Graphics.h"
#include "Snake.h"
#include "Apple.h"

class Grid
{
public:
	Grid();
	void Draw(Graphics & gfx);
	void Update(char input);

private:
	void Eating();

private:
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
	Snake snake;
	Apple apple;
};