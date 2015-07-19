#pragma once

#include <SDL.h>
#include "E_Pickup.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Coin.
@author Jamie Slowgrove
*/
class E_Coin : public E_Pickup
{
public:
	/**
	@brief Constructs the Coin object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Coin.
	@param dimensions The dimensions of the Coin.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Coin.
	*/
	E_Coin(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the Coin object.
	*/
	~E_Coin();
};