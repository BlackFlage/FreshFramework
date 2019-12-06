#pragma once
#include "Vector2.h"
#include "Colors.h"

class Segment
{
public:
	Segment() = default;
	Segment(Vector2 inPosition, Color c);
	void SetPosition( Vector2 segmentPosition );
	Color GetColor() const;
	Vector2 GetPosition() const;
private:
	Color color = Colors::Green;
	Vector2 position = { 0, 0 };
};