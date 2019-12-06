#pragma once
#include "Vector2.h"
#include "Colors.h"

class Snake
{
public:
	Snake(Vector2 startingPos, Color headColor);
	void Move();
	void Update();
	void GetInput(char input);
	Color GetHeadColor() const;
	Vector2 GetPosition() const;
private:
	Vector2 headPosition;
	Vector2 deltaPos = { 1, 0 };
	Color headColor;
};