#pragma once

#include <SDL.h>
#include "E_Pickup.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Shield.
@author Jamie Slowgrove
*/
class E_Shield : public E_Pickup
{
public:
	/**
	@brief Constructs the Shield object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Shield.
	@param dimensions The dimensions of the Shield.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Shield.
	*/
	E_Shield(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the Shield object.
	*/
	~E_Shield();
};