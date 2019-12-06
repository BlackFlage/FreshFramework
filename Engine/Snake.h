#pragma once
#include "Vector2.h"
#include "Colors.h"
#include "Segment.h"
#include "Apple.h"

class Snake
{
public:
	Snake(Vector2 startingPos, Color headColor);
	void Grow();
	void Update();
	void SetDelta(char input);
	int GetActualSegments() const;
	bool LoseCondition(int gridWidth, int gridHeight);
	bool CollidingWithApple(Apple& apple);
	Color GetHeadColor() const;
	Segment GetSegment( int segmentIndex ) const;
	Vector2 GetPosition() const;
private:
	void Move();
	void SegmentsFollow();
	bool SegmentsColliding();
	bool ScreenColliding(int gridWidth, int gridHeight) const;
private:
	static constexpr int maxSegments = 50;
	int actualSegments = 0;
	Color headColor;
	Vector2 headPosition;
	Vector2 deltaPos = { 1, 0 };
	Segment segments[maxSegments];
};