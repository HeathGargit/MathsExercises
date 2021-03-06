#include "Vector3.h"



Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(float a_x, float a_y, float a_z) : x(a_x), y(a_y), z(a_z)
{
}


Vector3::~Vector3()
{
}

Vector3 & Vector3::operator+(const Vector3 & other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3 & Vector3::operator=(const Vector3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector3 & Vector3::operator-(const Vector3 & other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 & Vector3::operator*(const float other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

Vector3 Vector3::cross(const Vector3 & other)
{
	Vector3 toReturn(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	return toReturn;
}

float Vector3::dot(const Vector3 & other)
{
	return ((this->x * other.x) + (this->y * other.y) + (this->z * other.z));
}

float Vector3::magnitude()
{
	return sqrt((x*x)+(y*y)+(z*z));
}

void Vector3::normalise()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3 Vector3::normal()
{
	Vector3 normalOfThis(x, y, z);
	normalOfThis.normalise();
	return normalOfThis;
}

std::string Vector3::to_string()
{
	std::string toReturn = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	return toReturn;
}

Vector3::operator float*() const
{
	return (float*)&x;
}

Vector3 operator*(float a_LHS, Vector3 & a_RHS)
{
	return Vector3(a_RHS * a_LHS);
}
