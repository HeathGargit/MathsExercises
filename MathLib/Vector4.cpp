#include "Vector4.h"
#include <cmath>



Vector4::Vector4()
{
}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_w) : x(a_x), y(a_y), z(a_z), w(a_w)
{
}


Vector4::~Vector4()
{
}

Vector4 & Vector4::operator+(const Vector4 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4 & Vector4::operator=(const Vector4 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

Vector4 & Vector4::operator-(const Vector4 & other)
{
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4 & Vector4::operator*(const float other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

Vector4::operator float*()
{
	return (float*)&x;
}

float Vector4::magnitude()
{
	return sqrt((x*x) + (y*y) + (z*z));
}

void Vector4::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector4 Vector4::normal()
{
	Vector4 normalOfThis(x, y, z, w);
	normalOfThis.normalise();
	return normalOfThis;
}
