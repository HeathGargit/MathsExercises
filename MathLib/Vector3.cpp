#include "Vector3.h"



Vector3::Vector3()
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

Vector3 Vector3::cross(const Vector3 & other)
{
	Vector3 toReturn(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
	return toReturn;
}

float Vector3::magnitude()
{
	return sqrt((x*x)+(y*y)+(z*z));
}

void Vector3::normalize()
{
	float mag = magnitude();
	x /= mag;
	y /= mag;
	z /= mag;
}

Vector3 Vector3::normal()
{
	Vector3 normalOfThis(x, y, z);
	normalOfThis.normalize();
	return normalOfThis;
}

std::string Vector3::to_string()
{
	std::string toReturn = std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	return toReturn;
}
