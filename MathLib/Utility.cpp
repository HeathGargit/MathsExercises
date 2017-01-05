#include "Utility.h"
#include <iostream>

int add(int a, int b)
{
	return a + b;
}

//function to multiply two unsigned ints.
int multiply(unsigned int a, unsigned int b)
{
	//figure out how many times to run the loop, based on the leftmost set bit, as any more times than this is just multiplying by zero a heap of times up to 32.
	int timesToIterate = GetLeftMostSetBit(b);

	//int to track the total
	unsigned int total = 0;

	if (timesToIterate > -1)
	{
		//iterates through each bit in "b" and if it is a 1, adds extra zeros depending on position, then adds to the total
		for (int i = 0; i <= timesToIterate; i++)
		{
			if (isRightMostBitSet(b >> i))
			{
				total += (a << i); //adds a 0 for each base unit checked.
			}
		}
	}
	
	return total;
}

//function to divide unsigned int a by unsigned int b. We kinda do it like it's long division
int divide(unsigned int a, unsigned int b)
{
	//a "substring" of the leftmost bits of the numerator to compare to the denominator until the denominator is greater than the substring. 
	unsigned int kindaSubString = 0x00;

	//number of times to iterate the loop, based on how many bits we have to compare in the numerator
	unsigned int timesToIterate = GetLeftMostSetBit(a);

	//to track the total as we work
	unsigned int total = 0;

	for (int i = timesToIterate; i >= 0; i--)
	{
		//move the bit to the left
		kindaSubString = (kindaSubString << 1);
		//"add" the next bit onto the substring in the last position.
		if (isBitSet(a, i))
		{
			kindaSubString++;
		}
		
		//check to see if the substring is biger than the denominator (like in long division). if it is, we set the bit in the position that we are checking and take the denominator off the substring so the remainder is added to the next bit that we are checking.
		if (kindaSubString >= b)
		{
			total += (0x01 << i);
			kindaSubString = kindaSubString - b;
		}
	}

	return total;
}

//function to find if the left most bit of an unsigned int is set.
bool isLeftMostBitSet(unsigned int value)
{
	//if the passed value has a bit set in the left most position, (value & 0x80000000) will equate to 0x80000000, as that should be the only place 1 & 1 appear
	if ((value & 0x80000000) == 0x80000000)
	{
		return true;
	}

	return false;
}

//function to find if the right most bit of an unsigned int is set.
bool isRightMostBitSet(unsigned int value)
{
	//if the passed value has a bit set in the right most position, (value & 1) will equate to 1, as that should be the only place 1 & 1 appear
	if ((value & 0x01) == 0x01)
	{
		return true;
	}

	return false;
}

//function to find if the bit at a particular position in an unsigned int is set. position is 0-31 running backwards from the LSB.
bool isBitSet(unsigned int value, unsigned char bit_to_check)
{
	//if the bit to check is less than or equal to 31, as this is the highed position possible with an unsigned int (0-31)
	if (bit_to_check <= 0x1F)
	{
		//create the binary number that has a 1 in the position where we are checking only. I could do this in the if statement, but i think it's easier to read this way.
		unsigned int bitCheckingNumber = 0x01 << bit_to_check;

		//if the value passed has a bit set in the position asked, then (value & mask) will be equal to the mask, as it should be the only place where a 1 & 1 appear.
		if ((value & bitCheckingNumber) == bitCheckingNumber)
		{
			return true;
		}
	}
	
	return false;
}

//this function returns the position of the lefttmost set bit of an unsigned integer, or -1 if there is no set bits.
int GetRightMostSetBit(unsigned int value)
{
	//check each bit
	for (int i = 0; i <= 31; i++)
	{
		//if the value passed has a bit set in the position asked, then (value & mask) will be equal to the mask, as it should be the only place where a 1 & 1 appear.
		if ((value & (0x01 << i)) == (0x01 << i))
		{
			return i;
		}
	}

	return -1;
}

//this function returns the position of the rightmost set bit of an unsigned integer, or -1 if there is no set bits.
int GetLeftMostSetBit(unsigned int value)
{
	//check each bit
	for (int i = 31; i >= 0; i--)
	{
		//if the value passed has a bit set in the position asked, then (value & mask) will be equal to the mask, as it should be the only place where a 1 & 1 appear.
		if ((value & (0x01 << i)) == (0x01 << i))
		{
			return i;
		}
	}

	return -1;
}

//this function prints the value of the unsigned int to the console.
void PrintBinary(unsigned char value)
{
	//loops 8 times, as there are only 8 bits in an unsigned int (1 byte according to google)
	for (int i = 7; i >= 0; i--)
	{

		std::cout << isBitSet(value, i);
		/*//if the bit is set, print a 1 to the console, else, print a 0.
		if (isBitSet(value, i))
		{
			std::cout << "1";
		}
		else
		{
			std::cout << "0";
		}*/
	}
}

//this function determines is a number is a function of two. This is kind of easy as we know that a power of two will only have one set bit.
bool isPowerOfTwo(unsigned int value)
{
	//finding how many bits we have to check
	unsigned int timesToIterate = GetLeftMostSetBit(value);
	unsigned int numberOfSetBits = 0;

	for (int i = 0; i <= timesToIterate; i++)
	{
		//if the bit we are checking is set, increase the total of set bits.
		if (isBitSet(value, i))
		{
			numberOfSetBits++;
		}
	}

	//if we have only one set bit, the number is a power of two (IE: return true)
	if (numberOfSetBits == 1)
	{
		return true;
	}

	return false;
}

//converts degrees to radians
float degToRad(float degrees)
{
	return degrees * _PI_OVER_180;
}

//converts radians to degrees
float radToDeg(float radians)
{
	return radians * _180_OVER_PI;
}

//returns exactly of float x
float LinearHalf(float x)
{
	float result = x * 0.5f;
	return result;
}

//returns the square of float x
float Quadratic(float x)
{
	float result = (x * x);
	return result;
}

//returns the Sine of float x
float Sine(float x)
{
	return sin(x);
}

//returns cosine of float x
float Cosine(float x)
{
	return cos(x);
}

//returns the absolute value of float x
float GetAbsolute(float x)
{
	int result = x;
	if (result < 0)
		result *= -1;
	
	return result;
}

//returns float x as a negative number, if it isn't already
float GetUnAbsolute(float x)
{
	int result = x;
	if (result > 0)
		result *= -1;

	return result;
}
