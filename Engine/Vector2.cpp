#include "Vector2.h"

Vector2::Vector2(int inX, int inY)
	:
	x(inX),
	y(inY)
{
}

Vector2::Vector2(std::pair<int, int> inPosition)
	:
	x(inPosition.first),
	y(inPosition.second)
{
}

void Vector2::operator=(Vector2 rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
}

bool Vector2::operator==(Vector2 rhs)
{
	return (this->x == rhs.x && this->y == rhs.y);
}

bool Vector2::operator!=(Vector2 rhs)
{
	return !(*this == rhs);
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

Vector2& Vector2::operator+=(Vector2 rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;

	return *this;
}

Vector2& Vector2::operator-=(Vector2 rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;

	return *this;
}

Vector2& Vector2::operator*=(Vector2 rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;

	return *this;
}

Vector2& Vector2::operator/=(Vector2 rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;

	return *this;
}