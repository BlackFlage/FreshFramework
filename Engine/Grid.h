#pragma once
#include "Graphics.h"
#include "Snake.h"
#include "Apple.h"

class Grid
{
public:
	Grid(int& step);
	void Draw(Graphics & gfx);
	void Update(char input);
	bool GameOver() const;
private:
	int& step;
	int score = 0;
	bool gameOver = false;
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
	static constexpr int gridWidth = Graphics::ScreenWidth / tilesWidth;
	static constexpr int gridHeight = Graphics::ScreenHeight / tilesHeight;
	Snake snake;
	Apple apple;
};