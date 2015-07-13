#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Stymphalian Bird.
@author Jamie Slowgrove
*/
class E_StyphBird : public E_Velocity
{
public:
	/**
	@brief Constructs the StyphBird object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the StyphBird.
	@param dimensions The dimensions of the StyphBird.
	@param screenDimensions The dimensions of the screen.
	*/
	E_StyphBird(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions);

	/**
	@brief Destructs the StyphBird object.
	*/
	~E_StyphBird();

	/**
	@brief A function that updates the StyphBird.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Returns the value of dead.
	@returns The value of dead.
	*/
	bool getDeadStatus();

private:
	///A boolean for if the StyphBird is dead and to be deleted.
	bool dead;
};