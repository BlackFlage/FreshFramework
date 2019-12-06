#pragma once
#include "Vector2.h"
#include "Colors.h"
#include <random>

class Apple
{
public:
	Apple(Color c);
	void Spawn(int gridWidth, int gridHeight);
private:
	Color color;
	Vector2 position = { 0, 0 };
};