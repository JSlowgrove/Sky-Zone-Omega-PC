#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Arrow.
@author Jamie Slowgrove
*/
class E_Arrow : public E_Velocity
{
public:
	/**
	@brief Constructs the Arrow object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Arrow.
	@param dimensions The dimensions of the Arrow.
	@param velocity The velocity of the Arrow.
	*/
	E_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocity);

	/**
	@brief Destructs the Arrow object.
	*/
	~E_Arrow();

	/**
	@brief Sets the value of dead.
	@param dead The new value of dead.
	*/
	void setDeadStatus(bool dead);

	/**
	@brief Returns the value of dead.
	@returns The value of dead.
	*/
	bool getDeadStatus();

protected:
	///A boolean for if the Arrow is dead and to be deleted.
	bool dead;
};