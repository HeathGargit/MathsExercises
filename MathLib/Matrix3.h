#ifndef _MATRIX3_H_
#define _MATRIX3_H_

class Vector3;

class Matrix3
{
public:
	//constructors
	Matrix3();
	Matrix3(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9);
	Matrix3(const Matrix3& other);
	~Matrix3();

	//overloaded operators
	operator float* ();
	Matrix3 operator + (Matrix3& a_RHS);
	Matrix3 operator - (Matrix3& a_RHS);
	Matrix3 operator * (Matrix3& a_RHS);
	Vector3 operator * (const Vector3& a_RHS);


	//utility functions
	void set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9);
	void setRotateX(float a_rads);
	void setRotateY(float a_rads);
	void setRotateZ(float a_rads);
	explicit operator float* () const;

	static Matrix3 createTranslation(float x, float y);

	union
	{
		struct { float m1, m2, m3, m4, m5, m6, m7, m8, m9; };
		struct { float m[9]; };
		struct { float mm[3][3]; };
	};
};

#endif // !_MATRIX3_H_