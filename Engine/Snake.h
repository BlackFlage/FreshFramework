#pragma once
#include "Vector2.h"
#include "Colors.h"

class Snake 
{
public:
	Snake(Vector2 inP);
	void Move();
	void TakeInput(char k);
	Vector2 GetPosition() const;
	Color GetColor() const;
private:
	Color color=Colors::Green;
	Vector2 position;
	Vector2 delta = { 0, -1 };
};