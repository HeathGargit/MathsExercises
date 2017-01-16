#ifndef _MATRIX2_H_
#define _MATRIX2_H_

#include "Vector2.h"

class Matrix2
{
public:
	//constructors
	Matrix2();
	Matrix2(float a_m1, float a_m2, float a_m3, float a_m4);
	Matrix2(const Matrix2& other);
	~Matrix2();

	//overlaoded operators
	explicit operator float* () const;
	Matrix2 operator + (const Matrix2& a_RHS);
	Matrix2 operator - (const Matrix2& a_RHS);
	Matrix2 operator * (const Matrix2& a_RHS);
	Matrix2* operator = (const Matrix2& a_RHS);
	Vector2 operator * (const Vector2& a_RHS);

	//utility
	void setRotateZ(float a_rads);
	void transpose();

	union
	{
		struct { float m1, m2, m3, m4; };
		struct { float m[4]; };
		struct { float mm[2][2]; };
	};

private:
	//utility functions
	void set(float a_m1, float a_m2, float a_m3, float a_m4);
};

#endif