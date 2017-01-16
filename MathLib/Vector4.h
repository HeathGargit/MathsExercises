#ifndef _VECTOR4_H_
#define _VECTOR4_H_

class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_w);
	~Vector4();

	//overloaded operators
	Vector4& operator+ (const Vector4& other);
	Vector4& operator= (const Vector4& other);
	Vector4& operator- (const Vector4& other);
	Vector4& operator* (const float other);
	friend Vector4 operator * (float a_LHS, Vector4& a_RHS);

	//working functions
	float dot(const Vector4& other); //returns the dot product of this and another vector4
	Vector4 cross(const Vector4& other); //returns the cross product of this and another vector4

	//utility functions
	operator float* (); //casts the Vector4 to an array of four floats
	float magnitude(); // returns the magnitude of the 3d protion of the Vector4
	void normalise(); // normalises the 3d portion of the Vector4
	Vector4 normal(); //returns a copy of this Vector4 with the 3d portion normalised.

	union
	{
		struct { float x, y, z, w; };
		struct { float v[4]; };
	};
	//variables
	/*float x;
	float y;
	float z;
	float w;*/
};

#endif