#include "Matrix4.h"
#include <memory.h>
#include <cmath>



Matrix4::Matrix4()
{
	set(0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 0.0f);
}

Matrix4::Matrix4(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16)
{
	set(a_m1, a_m2, a_m3, a_m4,
		a_m5, a_m6, a_m7, a_m8,
		a_m9, a_m10, a_m11, a_m12, 
		a_m13, a_m14, a_m15, a_m16);
}

Matrix4::Matrix4(const Matrix4 & other)
{
	set(other.m1, other.m2, other.m3, other.m4,
		other.m5, other.m6,	other.m7, other.m8, 
		other.m9, other.m10, other.m11, other.m12,
		other.m13, other.m14, other.m15, other.m16);
}


Matrix4::~Matrix4()
{
}

Matrix4::operator float*() const
{
	return (float*)&m1;
}

void Matrix4::setRotateX(float a_rads)
{
	set(1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, cosf(a_rads), sinf(a_rads), 0.0f,
		0.0f, -sinf(a_rads), cosf(a_rads), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

void Matrix4::setRotateY(float a_rads)
{
	set(cosf(a_rads), 0.0f, -sinf(a_rads), 0.0f,
		0.0f,		  1.0f, 0.0f,		   0.0f,
		sinf(a_rads), 0.0f, cosf(a_rads),  0.0f,
		0.0f,		  0.0f, 0.0f,		   1.0f);
}

void Matrix4::setRotateZ(float a_rads)
{
	set(cosf(a_rads),  sinf(a_rads), 0.0f, 0.0f,
		-sinf(a_rads), cosf(a_rads), 0.0f, 0.0f,
		0.0f,		   0.0f,		 1.0f, 0.0f,
		0.0f,		   0.0f,		 0.0f, 1.0f);
}

void Matrix4::transpose()
{
	Matrix4 temp(*this);
	set(temp.m1, temp.m5, temp.m9, temp.m13, temp.m2, temp.m6, temp.m10, temp.m14, temp.m3, temp.m7, temp.m11, temp.m15, temp.m4, temp.m8, temp.m12, temp.m16);
}

Matrix4 Matrix4::operator+(const Matrix4 & a_RHS)
{

	return Matrix4(m[0] + a_RHS.m[0], m[1] + a_RHS.m[1], m[2] + a_RHS.m[2], m[3] + a_RHS.m[3],
		m[4] + a_RHS.m[4], m[5] + a_RHS.m[5], m[6] + a_RHS.m[6], m[7] + a_RHS.m[7],
		m[8] + a_RHS.m[8], m[9] + a_RHS.m[9], m[10] + a_RHS.m[10], m[11] + a_RHS.m[11],
		m[12] + a_RHS.m[12], m[13] + a_RHS.m[13], m[14] + a_RHS.m[14], m[15] + a_RHS.m[15]);
}

Matrix4 Matrix4::operator-(const Matrix4 & a_RHS)
{
	return Matrix4(m[0] - a_RHS.m[0], m[1] - a_RHS.m[1], m[2] - a_RHS.m[2], m[3] - a_RHS.m[3],
		m[4] - a_RHS.m[4], m[5] - a_RHS.m[5], m[6] - a_RHS.m[6], m[7] - a_RHS.m[7],
		m[8] - a_RHS.m[8], m[9] - a_RHS.m[9], m[10] - a_RHS.m[10], m[11] - a_RHS.m[11],
		m[12] - a_RHS.m[12], m[13] - a_RHS.m[13], m[14] - a_RHS.m[14], m[15] - a_RHS.m[15]);
}

Matrix4 Matrix4::operator*(const Matrix4 & a_RHS)
{
	Matrix4 result;
	for (int fr = 0; fr < 4; fr++)
	{
		for (int sc = 0; sc < 4; sc++)
		{
			for (int fc = 0; fc < 4; fc++)
			{
				result.mm[fr][sc] += mm[fc][fr] * a_RHS.mm[sc][fc];
			}
		}
	}
	result.transpose();
	return result;
}

Matrix4* Matrix4::operator=(const Matrix4 & a_RHS)
{
	for (int i = 0; i < 16; i++)
	{
		m[i] = a_RHS.m[i];
	}

	return this;
}

void Matrix4::set(float a_m1, float a_m2, float a_m3, float a_m4, float a_m5, float a_m6, float a_m7, float a_m8, float a_m9, float a_m10, float a_m11, float a_m12, float a_m13, float a_m14, float a_m15, float a_m16)
{
	memcpy(m, &a_m1, sizeof(float) * 16);
}

Vector4 operator*(const Matrix4 a_LHS, const Vector4 & a_RHS)
{
	Vector4 result(0, 0, 0, 0);
	for (int resultColumn = 0; resultColumn < 4; resultColumn++)
	{
		for (int matrixRow = 0; matrixRow < 4; matrixRow++)
		{
			result.v[resultColumn] += (a_LHS.mm[matrixRow][resultColumn] * a_RHS.v[matrixRow]);
		}
	}


	return result;
}
