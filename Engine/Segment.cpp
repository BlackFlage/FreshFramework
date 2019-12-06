#include "Segment.h"

Segment::Segment(Vector2 inPosition, Color c)
	:
	position(inPosition),
	color(c)
{
}

void Segment::SetPosition(Vector2 segmentPosition)
{
	position = segmentPosition;
}

Color Segment::GetColor() const
{
	return color;
}

Vector2 Segment::GetPosition() const
{
	return position;
}
