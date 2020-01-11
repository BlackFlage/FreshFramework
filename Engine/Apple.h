#pragma once
#include "Vector2.h"
#include "Colors.h"
#include <random>
#include "Snake.h"

class Apple
{
public:
	void Spawn(Snake& snake);
	Vector2 GetPosition() const;
	Color GetColor() const;
private:
	Vector2 position;
	Color color = Colors::Red;
};