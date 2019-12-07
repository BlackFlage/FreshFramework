#include "Vector2.h"

Vector2::Vector2(int inX, int inY)
{
	x = inX;
	y = inY;
}

Vector2 Vector2::operator+(Vector2 rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(Vector2 rhs)
{
	return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(Vector2 rhs)
{
	return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator/(Vector2 rhs)
{
	return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 & Vector2::operator+=(Vector2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2 & Vector2::operator-=(Vector2 rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vector2 & Vector2::operator*=(Vector2 rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	return *this;
}

Vector2 & Vector2::operator/=(Vector2 rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	return *this;
}

bool Vector2::operator==(Vector2 rhs)
{
	return (x == rhs.x && y == rhs.y);
}

bool Vector2::operator!=(Vector2 rhs)
{
	return (!(*this == rhs));
}

Vector2 & Vector2::operator=(Vector2 rhs)
{
	x = rhs.x;
	y = rhs.y;
	return *this;
}
