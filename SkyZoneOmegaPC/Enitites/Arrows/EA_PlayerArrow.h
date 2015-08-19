#pragma once

#include <SDL.h>
#include "EA_Arrow.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the PlayerArrow.
@author Jamie Slowgrove
*/
class EA_PlayerArrow : public EA_Arrow
{
public:
	/**
	@brief Constructs the PlayerArrow object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the PlayerArrow.
	@param dimensions The dimensions of the PlayerArrow.
	@param screenDimensions The dimensions of the screen.
	*/
	EA_PlayerArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions);

	/**
	@brief Destructs the PlayerArrow object.
	*/
	~EA_PlayerArrow();

	/**
	@brief A function that updates the PlayerArrow.
	@param dt The delta time.
	*/
	void update(float dt);

private:
	///The screen dimensions.
	C_Vec2 screenDimensions;
};