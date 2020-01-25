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
	segments.emplace_back();
}

void Snake::MoveSegments()
{
	if ((int)segments.size() > 0)
	{
		for (int i = (int)segments.size() - 1; i > 0; i--)
		{
			segments.at(i).Move(segments.at(i - 1).GetPosition());
		}

		segments.at(0).Move(position);
	}
	}


Segment Snake::GetSegment(int segmentIndex) const
{
	return segments.at(segmentIndex);
}

int Snake::GetActualSegments() const
{
	return (int)segments.size();
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

Color Segment::GetColor() const
{
	return color;
}
