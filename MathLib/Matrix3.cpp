#include "Matrix3.h"
#include <math.h>
#include <memory.h>
#include "Vector3.h"



Matrix3::Matrix3()
{
	set(0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f,
		0.0f,0.0f,0.0f);
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

void Matrix3::setRotateY(float a_rads)
{
	set(cosf(a_rads), 0.0f, -sinf(a_rads),
		0.0f,         1.0f, 0.0f,
		sinf(a_rads), 0.0f, cosf(a_rads));
}

void Matrix3::setRotateZ(float a_rads)
{
	set(cosf(a_rads), sinf(a_rads), 0.0f,
		-sinf(a_rads), cosf(a_rads), 0.0f,
		0.0f, 0.0f, 1.0f);
}

Matrix3::operator float*() const
{
	return (float*)&m1;
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

Matrix3 Matrix3::operator-(Matrix3 & a_RHS)
{
	return Matrix3(m[0] - a_RHS.m[0], m[1] - a_RHS.m[1], m[2] - a_RHS.m[2],
		m[3] - a_RHS.m[3], m[4] - a_RHS.m[4], m[5] - a_RHS.m[5],
		m[6] - a_RHS.m[6], m[7] - a_RHS.m[7], m[8] - a_RHS.m[8]);
}

Matrix3 Matrix3::operator*(Matrix3 & a_RHS)
{	
	//Matrix3((mm[0][0] * a_RHS.mm[0][0])+(mm[0][1] * a_RHS.mm[0][1])
	Matrix3 result;
	for (int fr = 0; fr < 3; fr++)
	{
		for (int sc = 0; sc < 3; sc++)
		{
			for (int fc = 0; fc < 3; fc++)
			{
				result.mm[fr][sc] += mm[fc][fr] * a_RHS.mm[sc][fc];
			}
		}
	}
	result.transpose();
	return result;
}

Matrix3 Matrix3::createIdentity()
{
	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f);
}

Matrix3 Matrix3::createTranslation(float x, float y)
{

	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					x, y, 1.0f);
}

Matrix3 Matrix3::createTranslation(const Vector2 & a_vec)
{
	return Matrix3(1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		a_vec.x, a_vec.y, 1.0f);
}

Matrix3 Matrix3::createTranslation(const Vector3 & a_vec)
{
	return Matrix3(1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					a_vec.x, a_vec.y, a_vec.z);
}

Matrix3 Matrix3::createRotation(float a_rads)
{
	return Matrix3(cosf(a_rads), -sinf(a_rads), 0.0f,
					sinf(a_rads), cosf(a_rads), 0.0f,
					0.0f, 0.0f, 1.0f);
}

Matrix3 Matrix3::createScale(float a_xScale, float a_yScale)
{
	return Matrix3(a_xScale, 0.0f, 0.0f,
					0.0f, a_yScale, 0.0f,
					0.0f, 0.0f, 1.0f);
}

void Matrix3::transpose()
{
	Matrix3 temp(*this);
	set(temp.m1, temp.m4, temp.m7, temp.m2, temp.m5, temp.m8, temp.m3, temp.m6, temp.m9);
}

Matrix3* Matrix3::operator=(const Matrix3 & a_RHS)
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = a_RHS.m[i];
	}

	return this;
}

Vector3 operator*(const Matrix3 & a_LHS, const Vector3 & a_RHS)
{
	Vector3 result(0, 0, 0);
	for (int resultColumn = 0; resultColumn < 3; resultColumn++)
	{
		for (int matrixRow = 0; matrixRow < 3; matrixRow++)
		{
			result.v[resultColumn] += (a_LHS.mm[matrixRow][resultColumn] * a_RHS.v[matrixRow]);
		}
	}


	return result;
}
