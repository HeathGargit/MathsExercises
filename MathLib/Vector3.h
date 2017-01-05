#pragma once

#include <string>

class Vector3
{
public:
	//constructors
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();

	//overloaded operators
	Vector3& operator+ (const Vector3& other);
	Vector3& operator= (const Vector3& other);
	Vector3& operator- (const Vector3& other);

	//working functions
	//cross product
	Vector3 cross(const Vector3& other);

	//utility functions
	float magnitude();
	void normalize();
	Vector3 normal();
	std::string to_string();

	//variables
	float x;
	float y;
	float z;
};

