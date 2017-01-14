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

Vector2& Vector2::operator-(const Vector2& other)
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 & Vector2::operator*(const float other)
{
	x *= other;
	y *= other;
	return *this;
}

float Vector2::magnitude()
{
	return sqrt((x*x)+(y*y));
}

void Vector2::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
}

Vector2 Vector2::normal()
{
	Vector2 normalOfThis(x, y);
	normalOfThis.normalise();
	return normalOfThis;
}

std::string Vector2::to_string()
{
	std::string toReturn = std::to_string(x) + ", " + std::to_string(y);
	return toReturn;
}

Vector2::operator float*() const
{
	return (float*)&x;
}

float Vector2::dot(const Vector2 & inputVector)
{
	return ((this->x * inputVector.x) + (this->y * inputVector.y));
}

Vector2 operator*(float a_LHS, Vector2& a_RHS)
{
	return Vector2(a_RHS * a_LHS);
}
