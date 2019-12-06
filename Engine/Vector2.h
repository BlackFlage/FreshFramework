#pragma once
#include <utility>

struct Vector2
{
	Vector2( int inX, int inY );
	Vector2(std::pair<int, int> inPosition);
	int x;
	int y;

	void operator=(Vector2 rhs);
	bool operator==(Vector2 rhs);
	bool operator!=(Vector2 rhs);
	Vector2 operator+(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	Vector2 operator*(Vector2 rhs);
	Vector2 operator/(Vector2 rhs);
	Vector2& operator+=(Vector2 rhs);
	Vector2& operator-=(Vector2 rhs);
	Vector2& operator*=(Vector2 rhs);
	Vector2& operator/=(Vector2 rhs);
};