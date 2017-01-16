#include <iostream>
#include "Vector2.h"
#include "Matrix2.h"


void main()
{
	Vector2 a(3, 7);
	Matrix2 b(2, 4, 6, 8);

	Vector2 v = b * a;



	system("pause");
}