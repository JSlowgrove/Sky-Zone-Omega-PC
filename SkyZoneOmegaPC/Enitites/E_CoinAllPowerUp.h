#pragma once

#include <SDL.h>
#include "E_Pickup.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the CoinAllPowerUp.
@author Jamie Slowgrove
*/
class E_CoinAllPowerUp : public E_Pickup
{
public:
	/**
	@brief Constructs the CoinAllPowerUp object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the CoinAllPowerUp.
	@param dimensions The dimensions of the CoinAllPowerUp.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the CoinAllPowerUp.
	*/
	E_CoinAllPowerUp(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the CoinAllPowerUp object.
	*/
	~E_CoinAllPowerUp();
};