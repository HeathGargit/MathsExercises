#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2
{
public:
	//constructors
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();

	//overloaded operators
	Vector2& operator+ (const Vector2& other);
	Vector2& operator= (const Vector2& other);

	//utility functions
	float magnitude();
	void normalize();
	Vector2 normal();

public:
	float x;
	float y;
};

#endif
