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

void Snake::Grow()
{
	actualSegments++;

	if (actualSegments > 1)
	{
		segments[actualSegments - 1].SetPosition(segments[actualSegments - 2].GetPosition());
	}
	else
	{
		segments[0].SetPosition(headPosition);
	}
}

void Snake::Update(char input)
{
	SetDelta(input);
	SegmentsFollow();
	Move();
}

int Snake::GetActualSegments() const
{
	return actualSegments;
}

void Snake::SegmentsFollow()
{
	for (int i = actualSegments - 1; i >= 0; i--)
	{
		if (i != 0)
		{
			segments[i].SetPosition(segments[i - 1].GetPosition());
		}
		else
		{
			segments[i].SetPosition(headPosition);
		}
	}
}

void Snake::SetDelta(char input)
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

Segment Snake::GetSegment(int segmentIndex) const
{
	return segments[segmentIndex];
}

Vector2 Snake::GetPosition() const
{
	return headPosition;
}
