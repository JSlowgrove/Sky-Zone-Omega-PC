#pragma once

#include <SDL.h>
#include "E_Pickup.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the KillAllPowerUp.
@author Jamie Slowgrove
*/
class E_KillAllPowerUp : public E_Pickup
{
public:
	/**
	@brief Constructs the KillAllPowerUp object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the KillAllPowerUp.
	@param dimensions The dimensions of the KillAllPowerUp.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the KillAllPowerUp.
	*/
	E_KillAllPowerUp(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the KillAllPowerUp object.
	*/
	~E_KillAllPowerUp();
};