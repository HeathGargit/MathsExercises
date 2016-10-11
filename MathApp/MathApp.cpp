// MathApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utility.h"
#include <iostream>
#include <Vector2.h>

void testLMBSet();
void testAdd();
void testRMBSet();
void testIsBitSet();
void testGetRightMostSetBit();
void testPrintVoid();
void testIsPowerOfTwo();

int main()
{
	//testAdd();
	//testLMBSet();
	//testRMBSet();
	//testIsBitSet();
	//testGetRightMostSetBit();
	//testPrintVoid();
	//std::cout << multiply(1, 0) << std::endl;
	//std::cout << divide(46996668, 8199) << std::endl;
	//testIsPowerOfTwo();

	Vector2 a(1, 2), b(2, 2), c;

	c = a + b;

	std::cout << "c= " << c.x << ", " << c.y << ". Magnitude is: " << c.magnitude() << std::endl;


	system("pause");

    return 0;
}

//Testing functions
void testAdd()
{
	std::cout << add(10, 5) << std::endl;
	std::cout << add(10, 6) << std::endl;
	system("pause");
}

void testLMBSet()
{
	unsigned int testInt = 0xFFFFFFFF;
	
	std::cout << testInt << ": leftmost should be True " << isLeftMostBitSet(testInt) << std::endl;

	testInt = 0x80000000;

	std::cout << testInt << ": leftmost should be True " << isLeftMostBitSet(testInt) << std::endl;

	testInt = 0x80000001;

	std::cout << testInt << ": leftmost should be True " << isLeftMostBitSet(testInt) << std::endl;

	testInt = 0x7FFFFFFF;

	std::cout << testInt << ": leftmost should be False " << isLeftMostBitSet(testInt) << std::endl;

	testInt = 0x00000000;

	std::cout << testInt << ": leftmost should be False " << isLeftMostBitSet(testInt) << std::endl;
}

void testRMBSet()
{
	//testing value 0, should be false (00)
	unsigned int testInt = 0x00;

	std::cout << testInt << ": rightmost should be false " << isRightMostBitSet(testInt) << std::endl;

	//testing value 1, should be true (01)
	testInt = 0x01;

	std::cout << testInt << ": rightmost should be true " << isRightMostBitSet(testInt) << std::endl;

	//testing value 2, should be false (10)
	testInt = 0x02;

	std::cout << testInt << ": rightmost should be false " << isRightMostBitSet(testInt) << std::endl;

	//testing value 3 (11), should be true
	testInt = 0x03;

	std::cout << testInt << ": rightmost should be true " << isRightMostBitSet(testInt) << std::endl;

	//testing value 2147483648 should be true
	testInt = 0xFFFFFFFF;

	std::cout << testInt << ": rightmost should be true " << isRightMostBitSet(testInt) << std::endl;

}

void testIsBitSet()
{
	unsigned int valueToCheck;
	unsigned char positionToCheck;
	unsigned int positionConvertedToInt;

	//testing value 1 against position 0 should be true/1
	valueToCheck = 0x01;
	positionToCheck = 0x00;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be True: " << isBitSet(valueToCheck, positionToCheck) << std::endl;

	//testing value 1 against position 1 should be false/0
	valueToCheck = 0x01;
	positionToCheck = 0x01;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be False: " << isBitSet(valueToCheck, positionToCheck) << std::endl;

	//testing value 32 against position 5 should be true/1
	valueToCheck = 0x20;
	positionToCheck = 0x05;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be True: " << isBitSet(valueToCheck, positionToCheck) << std::endl;

	//testing value 2147483648 against position 31 should be true/1
	valueToCheck = 0x80000000;
	positionToCheck = 0x1F;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be True: " << isBitSet(valueToCheck, positionToCheck) << std::endl;

	//testing value 4294967295 against position 31 should be true/1
	valueToCheck = 0xFFFFFFFF;
	positionToCheck = 0x1F;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be True: " << isBitSet(valueToCheck, positionToCheck) << std::endl;

	//testing value 4294967295 against position 20 should be true/1
	valueToCheck = 0xFFFFFFFF;
	positionToCheck = 0x14;
	positionConvertedToInt = positionToCheck;
	std::cout << valueToCheck << ": is bit at " << positionConvertedToInt << " set? Should be True: " << isBitSet(valueToCheck, positionToCheck) << std::endl;
}

void testGetRightMostSetBit()
{
	//testing 0. should return -1
	unsigned int testThis = 0x00;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;

	//testing 1, should return 0
	testThis = 0x01;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;

	//testing 2, should return 1
	testThis = 0x02;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;

	//testing 3, should return 1
	testThis = 0x03;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;

	//testing 24, should return 27
	testThis = 0x18;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;

	//testing 2147483648, should return 31
	testThis = 0x80000000;

	std::cout << testThis << "'s right most set bit is at position: " << GetRightMostSetBit(testThis) << std::endl;
}

void testPrintVoid()
{
	//test 00
	unsigned int testThis = 0x00;

	std::cout << testThis << " as binary is: ";
	PrintBinary(testThis);
	std::cout << std::endl;

	//test 01
	testThis = 0x01;

	std::cout << testThis << " as binary is: ";
	PrintBinary(testThis);
	std::cout << std::endl;

	//test 02
	testThis = 0x02;

	std::cout << testThis << " as binary is: ";
	PrintBinary(testThis);
	std::cout << std::endl;

	//test 03
	testThis = 0x03;

	std::cout << testThis << " as binary is: ";
	PrintBinary(testThis);
	std::cout << std::endl;

	//test 255
	testThis = 0xFF;

	std::cout << testThis << " as binary is: ";
	PrintBinary(testThis);
	std::cout << std::endl;
}

void testIsPowerOfTwo()
{
	std::cout << "Is " << 0x01 << "a power of 2? Expecting 1: " << isPowerOfTwo(0x01) << std::endl;

	std::cout << "Is " << 0x04 << "a power of 2? Expecting 1: " << isPowerOfTwo(0x04) << std::endl;

	std::cout << "Is " << 0x10 << "a power of 2? Expecting 1: " << isPowerOfTwo(0x10) << std::endl;

	std::cout << "Is " << 0x03 << "a power of 2? Expecting 0: " << isPowerOfTwo(0x03) << std::endl;

	std::cout << "Is " << 0x80000000 << "a power of 2? Expecting 1: " << isPowerOfTwo(0x80000000) << std::endl;

	std::cout << "Is " << 0xFFFFFFFF << "a power of 2? Expecting 0: " << isPowerOfTwo(0xFFFFFFFF) << std::endl;
}