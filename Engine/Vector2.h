#pragma once

struct Vector2
{
	Vector2(int inX, int inY);
	int x;
	int y;
	Vector2 operator+(Vector2 rhs);
	Vector2 operator-(Vector2 rhs);
	Vector2 operator*(Vector2 rhs);
	Vector2 operator/(Vector2 rhs);
	Vector2& operator+=(Vector2 rhs);
	Vector2& operator-=(Vector2 rhs);
	Vector2& operator*=(Vector2 rhs);
	Vector2& operator/=(Vector2 rhs);
	Vector2& operator=(Vector2 rhs);
	bool operator==(Vector2 rhs);
	bool operator!=(Vector2 rhs);
	

	
};
