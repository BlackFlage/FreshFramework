#pragma once
#include "Vector2.h"
#include "Colors.h"
#include "Segment.h"

class Snake
{
public:
	Snake(Vector2 startingPos, Color headColor);
	void Grow();
	void Update(char input);
	int GetActualSegments() const;
	Color GetHeadColor() const;
	Segment GetSegment( int segmentIndex ) const;
	Vector2 GetPosition() const;
private:
	void Move();
	void SegmentsFollow();
	void SetDelta(char input);
private:
	static constexpr int maxSegments = 50;
	int actualSegments = 0;
	Color headColor;
	Vector2 headPosition;
	Vector2 deltaPos = { 1, 0 };
	Segment segments[maxSegments];
};