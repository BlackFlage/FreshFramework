#include "Snake.h"

Snake::Snake(Vector2 inP)
	:
	position(inP)
{
}

void Snake::Move()
{
	position += delta;
}

void Snake::TakeInput(char k)
{
	switch (k)
	{
	case 'W':
	{
		delta = { 0, -1 };
		break;
	}
	case 'S':
	{
		delta = { 0, 1 };
		break;
	}
	case 'A':
	{
		delta = { -1, 0 };
		break;
	}
	case 'D':
	{
		delta = { 1, 0 };
		break;
	}
	}
}

Vector2 Snake::GetPosition() const
{
	return position;
}

Color Snake::GetColor() const
{
	return color;
}
