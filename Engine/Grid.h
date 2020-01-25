#pragma once
#include "Graphics.h"
#include "Snake.h"
#include "Apple.h"

enum class Obstacle
{
	empty,
	stone,
	poison,
	muschroom
};

class Grid
{
public:
	Grid(float& outStep);
	void Draw(Graphics & gfx);
	void Update(char input);
	bool IsOver() const;
private:
	void Eating();
	void HandleObstacle();
private:
	float* step = nullptr;
	bool isOver = false;
	static constexpr int tilesWidth = 40;
	static constexpr int tilesHeight = 40;
	Obstacle obstacles[tilesWidth * tilesHeight];
	Snake snake;
	Apple apple;
	float stepDecrease = 0.05f;
};