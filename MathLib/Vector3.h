#ifndef _VECTOR3_H_
#define _VECTOR3_H_


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
	Vector3& operator* (const float other);
	friend Vector3 operator * (float a_LHS, Vector3& a_RHS);
	//friend Vector3 operator * (Matrix3& a_LHS, Vector3& a_RHS);

	//working functions
	//cross product
	Vector3 cross(const Vector3& other); //finds the cross product of this and another vector
	float dot(const Vector3& other); //finds the dot product of this and another vector

	//utility functions
	float magnitude(); //returns the magnitude of the vector
	void normalise(); //normalises the vector to unit length
	Vector3 normal(); //returns a Vector3 that is the normal of this vector
	std::string to_string(); //converts to a std::string format x, y, z
	explicit operator float* () const; //casts the Vector3 to an array of three floats

	union 
	{
		struct { float x, y, z; };
		struct { float v[3]; };
	};
	
};

#endif