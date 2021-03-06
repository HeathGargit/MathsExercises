#ifndef _VECTOR2_H_
#define _VECTOR2_H_

#include <string>

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
	Vector2& operator- (const Vector2& other);
	Vector2& operator * (const float other);
	friend Vector2 operator * (float a_LHS, Vector2& a_RHS);

	//working functions
	float dot(const Vector2& inputVector);
	
	//utility functions
	float magnitude();
	void normalise();
	Vector2 normal();
	std::string to_string();
	explicit operator float* () const;

	union
	{
		struct { float x, y; };
		struct { float v[2]; };
	};
};

#endif
