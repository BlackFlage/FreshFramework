#pragma once
#include "Vector2.h"
#include "Colors.h"

class Segment
{
public:
	Segment(Vector2 inPos);
	Segment() = default;
	void Move(Vector2 inPos);
	Vector2 GetPosition() const;
	Color GetColor() const;
private:
	Vector2 position = { 0, 0 };
	Color color = Colors::Yellow;
};

class Snake 
{
public:
	Snake(Vector2 inP);
	void Move();
	void TakeInput(char k);
	Vector2 GetPosition() const;
	Color GetColor() const;
	void Grow();
	void MoveSegments();
	int GetActualSegments();
	Segment GetSegments(int segmentIndex) const;
private:
	Color color=Colors::Green;
	Vector2 position;
	Vector2 delta = { 0, -1 };
	static constexpr int maxSegments = 299;
	int actualSegments = 3;
	Segment segments[maxSegments];
};