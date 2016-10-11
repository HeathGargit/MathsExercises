#include "Vector2.h"
#include <cmath>


Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(float a_x, float a_y) : x(a_x), y(a_y)
{
}


Vector2::~Vector2()
{
}

Vector2& Vector2::operator+(const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

float Vector2::magnitude()
{
	return sqrt((x*x)+(y*y));
}

void Vector2::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
}

Vector2 Vector2::normal()
{
	Vector2 normalOfThis(x, y);
	normalOfThis.normalize();
	return normalOfThis;
}
