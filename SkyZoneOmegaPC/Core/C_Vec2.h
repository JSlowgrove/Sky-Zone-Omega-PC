#pragma once

/**
@brief Contains the Vec2 structure with functions and overloaded operators.
@author Jamie Slowgrove
*/
struct C_Vec2
{
	///Position variables
	float x, y;
	
	/**
	@brief Constructs the Vec2 setting the values to 0,0.
	*/
	C_Vec2() : x(0.0f), y(0.0f){}

	/**
	@brief Constructs the Vec2 setting the values to the input coordinates.
	@param x The inputed x position.
	@param y The inputed y position.
	*/
	C_Vec2(float x, float y) : x(x), y(y){}

	/**
	@brief Constructs the Vec2 setting the values to the input coordinates.
	@param x The inputed x position.
	@param y The inputed y position.
	*/
	C_Vec2(int x, int y) : x((float)x), y((float)y){}

	/**
	@brief Overloads the += operator.
	@param vecIn The input Vec2.
	@returns The new vector.
	*/
	C_Vec2* operator += (C_Vec2 vecIn)
	{
		x += vecIn.x;
		y += vecIn.y;
		return this;
	}

	/**
	@brief Overloads the -= operator.
	@param vecIn The input Vec2.
	@returns The new vector.
	*/
	C_Vec2* operator -= (C_Vec2 vecIn)
	{
		x -= vecIn.x;
		y -= vecIn.y;
		return this;
	}
};

/**
@brief Overloads the - operator allowing a Vec2 to be inverted.
@param vecIn The input Vec2.
@returns The new vector.
*/
inline C_Vec2 operator - (C_Vec2 vecIn)
{
	C_Vec2 vecOut;
	vecOut.x = -vecIn.x;
	vecOut.y = -vecIn.y;
	return vecOut;
}

/**
@brief Overloads the - operator allowing Vec2's to be subtracted from each other.
@param vecInA One of the input Vec2's.
@param vecInB One of the input Vec2's.
@returns The new vector.
*/
inline C_Vec2 operator - (C_Vec2 vecInA, C_Vec2 vecInB)
{
	C_Vec2 vecOut;
	vecOut.x = vecInA.x - vecInB.x;
	vecOut.y = vecInA.y - vecInB.y;
	return vecOut;
}

/**
@brief Overloads the + operator.
@param vecInA One of the input Vec2's.
@param vecInB One of the input Vec2's.
@returns The new vector.
*/
inline C_Vec2 operator + (C_Vec2 vecInA, C_Vec2 vecInB)
{
	C_Vec2 vecOut;
	vecOut.x = vecInA.x + vecInB.x;
	vecOut.y = vecInA.y + vecInB.y;
	return vecOut;
}

/**
@brief Overloads the / operator allowing a Vec2 to be divided by a scalar.
@param vecInA One of the input Vec2's.
@param scalar The scalar to divide by.
@returns The new vector.
*/
inline C_Vec2 operator / (C_Vec2 vecInA, float scalar)
{
	C_Vec2 vecOut;
	vecOut.x = vecInA.x / scalar;
	vecOut.y = vecInA.y / scalar;
	return vecOut;
}

/**
@brief Overloads the * operator allowing a Vec2 to be multiplied by a scalar.
@param vecInA One of the input Vec2's.
@param scalar The scalar to multiply by.
@returns The new vector.
*/
inline C_Vec2 operator * (C_Vec2 vecInA, float scalar)
{
	C_Vec2 vecOut;
	vecOut.x = vecInA.x * scalar;
	vecOut.y = vecInA.y * scalar;
	return vecOut;
}

/**
@brief Overloads the * operator allowing a Vec2 to be multiplied by another Vec2.
@param vecInA One of the input Vec2's.
@param vecInB One of the input Vec2's.
@returns The new vector.
*/
inline C_Vec2 operator * (C_Vec2 vecInA, C_Vec2 vecInB)
{
	C_Vec2 vecOut;
	vecOut.x = vecInA.x * vecInB.x;
	vecOut.y = vecInA.y * vecInB.y;
	return vecOut;
}