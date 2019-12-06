#include "Snake.h"

Snake::Snake(Vector2 startingPos, Color headColor)
	:
	headPosition(startingPos),
	headColor(headColor)
{
}

void Snake::Move()
{
	headPosition += deltaPos;
}

void Snake::Update()
{
	Move();
}

void Snake::GetInput(char input)
{
	switch (input)
	{
	case 'A':
		deltaPos = { -1, 0 };
		break;
	case 'D':
		deltaPos = { 1, 0 };
		break;
	case 'W':
		deltaPos = { 0, -1 };
		break;
	case 'S':
		deltaPos = { 0, 1 };
		break;
	}
}

Color Snake::GetHeadColor() const
{ 
	return headColor;
}

Vector2 Snake::GetPosition() const
{
	return headPosition;
}
