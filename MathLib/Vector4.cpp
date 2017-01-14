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

float Vector4::dot(const Vector4 & other)
{
	return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z) + (this->w * other.w));
}

Vector4 Vector4::cross(const Vector4& other)
{
	Vector4 toReturn(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x, 0);
	return toReturn;
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

Vector4 operator*(float a_LHS, Vector4 & a_RHS)
{
	return Vector4(a_RHS * a_LHS);
}
