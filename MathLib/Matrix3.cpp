#include "Matrix3.h"
#include <math.h>
#include <memory.h>



Matrix3::Matrix3()
{
	set(1.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,
		0.0f,0.0f,1.0f);
}

Matrix3::Matrix3(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9)
{
	set(a_m1, a_m2, a_m3, 
		a_m4, a_m5, a_m6, 
		a_m7, a_m8, a_m9);
}

Matrix3::Matrix3(const Matrix3 & other)
{
	set(other.m1, other.m2, other.m3, 
		other.m4, other.m5, other.m6, 
		other.m7, other.m8, other.m9);
}


Matrix3::~Matrix3()
{
}

void Matrix3::set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9)
{
	memcpy(m, &a_m1, sizeof(float) * 9);
}

void Matrix3::setRotateX(float a_rads)
{
	set(1.0f, 0.0f, 0.0f,
		0.0f, cosf(a_rads), sinf(a_rads),
		0.0f, -sinf(a_rads), cosf(a_rads));
}

void Matrix3::setRotateZ(float a_rads)
{
	set(cosf(a_rads), sinf(a_rads), 0.0f,
		-sinf(a_rads), cosf(a_rads), 0.0f,
		0.0f, 0.0f, 1.0f);
}

Matrix3::operator float*()
{
	return m;
}

Matrix3 Matrix3::operator+(Matrix3 & a_RHS)
{
	return Matrix3(m[0] + a_RHS.m[0], m[1] + a_RHS.m[1], m[2] + a_RHS.m[2],
					m[3] + a_RHS.m[3], m[4] + a_RHS.m[4], m[5] + a_RHS.m[5],
					m[6] + a_RHS.m[6], m[7] + a_RHS.m[7], m[8] + a_RHS.m[8]);
}

Matrix3 Matrix3::createTranslation(float x, float y)
{

	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					x, y, 1.0f);
}
