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

void Snake::Update()
{
	SegmentsFollow();
	Move();
}

int Snake::GetActualSegments() const
{
	return actualSegments;
}

bool Snake::LoseCondition(int gridWidth, int gridHeight)
{
	return SegmentsColliding() || ScreenColliding(gridWidth, gridHeight);
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

bool Snake::ScreenColliding(int gridWidth, int gridHeight) const
{
	return headPosition.x + deltaPos.x < 0 ||
		   headPosition.x + deltaPos.x > gridWidth - 1 ||
		   headPosition.y + deltaPos.y < 0 ||
		   headPosition.y + deltaPos.y > gridHeight - 1;
}

bool Snake::SegmentsColliding()
{
	for (int i = 1; i < actualSegments; i++)
	{
		if (headPosition == segments[i].GetPosition())
		{
			return true;
		}
	}
	
	return false;
}

bool Snake::CollidingWithApple(Apple & apple)
{

	return headPosition == apple.GetPosition();
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
