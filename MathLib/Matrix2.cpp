#include "Matrix2.h"
#include <memory.h>
#include <cmath>



Matrix2::Matrix2()
{
	set(0.0f, 0.0f,
		0.0f, 0.0f);
}

Matrix2::Matrix2(float a_m1, float a_m2, float a_m3, float a_m4)
{
	set(a_m1, a_m2, 
		a_m3, a_m4);
}

Matrix2::Matrix2(const Matrix2 & other)
{
	set(other.m1, other.m2, 
		other.m3, other.m4);
}

Matrix2::~Matrix2()
{
}

Matrix2::operator float*() const
{
	return (float*)&m1;
}

Matrix2 Matrix2::operator+(const Matrix2 & a_RHS)
{
	return Matrix2(m[0] + a_RHS.m[0], m[1] + a_RHS.m[1],
		m[2] + a_RHS.m[2], m[3] + a_RHS.m[3]);
}

Matrix2 Matrix2::operator-(const Matrix2 & a_RHS)
{
	return Matrix2(m[0] - a_RHS.m[0], m[1] - a_RHS.m[1],
		m[2] - a_RHS.m[2], m[3] - a_RHS.m[3]);
}

Matrix2 Matrix2::operator*(const Matrix2 & a_RHS)
{
	Matrix2 result(0, 0, 0, 0);
	for (int fr = 0; fr < 2; fr++)
	{
		for (int sc = 0; sc < 2; sc++)
		{
			for (int fc = 0; fc < 2; fc++)
			{
				result.mm[fr][sc] += mm[fr][fc] * a_RHS.mm[fc][sc];
			}
		}
	}
	//result.transpose();
	return result;
}

Matrix2* Matrix2::operator = (const Matrix2& a_RHS)
{
	for (int i = 0; i < 4; i++)
	{
		m[i] = a_RHS.m[i];
	}
	return this;
}

Vector2 Matrix2::operator * (const Vector2& a_RHS)
{
	//return Vector2((m1 * a_RHS.x) + (m3 * a_RHS.y), (m2 * a_RHS.x) + (m4 * a_RHS.y));
	
	
	Vector2 result(0, 0);
	for (int row = 0; row < 2; row++)
	{
		for (int column = 0; column < 2; column++)
		{
			result.v[row] += (mm[column][row] * a_RHS.v[column]);
		}
	}

	return result;
}

void Matrix2::setRotateZ(float a_rads)
{
	set(cosf(a_rads), sinf(a_rads),
		-sinf(a_rads), cosf(a_rads));
}

void Matrix2::transpose()
{
	Matrix2 temp(*this);
	set(temp.m1, temp.m3, temp.m2, temp.m4);
}

void Matrix2::set(float a_m1, float a_m2, float a_m3, float a_m4)
{
	memcpy(m, &a_m1, sizeof(float) * 4);
}
