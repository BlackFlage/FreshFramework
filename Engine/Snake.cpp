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

void Snake::Grow()
{
	actualSegments++;
}

void Snake::MoveSegments()
{
	for (int i = actualSegments - 1; i > 0; i--)
	{
		segments[i].Move(segments[i - 1].GetPosition());
	}
	
	segments[0].Move(position);
}

Segment::Segment(Vector2 inPos)
	:
	position(inPos)
{
}

void Segment::Move(Vector2 inPos)
{
	position = inPos;
}

Vector2 Segment::GetPosition() const
{
	return position;
}
