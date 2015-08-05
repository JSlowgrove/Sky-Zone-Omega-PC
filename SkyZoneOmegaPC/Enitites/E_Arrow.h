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
	*/
	E_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

	/**
	@brief Destructs the Arrow object.
	*/
	~E_Arrow();

	/**
	@brief A function that updates the Arrow.
	@param dt The delta time.
	*/
	void update(float dt);

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

private:
	///A boolean for if the Arrow is dead and to be deleted.
	bool dead;
};