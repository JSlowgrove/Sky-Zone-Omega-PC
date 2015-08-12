#pragma once

#include <SDL.h>
#include "E_Arrow.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the ArcherArrow.
@author Jamie Slowgrove
*/
class E_ArcherArrow : public E_Arrow
{
public:
	/**
	@brief Constructs the ArcherArrow object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the ArcherArrow.
	@param dimensions The dimensions of the ArcherArrow.
	*/
	E_ArcherArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

	/**
	@brief Destructs the ArcherArrow object.
	*/
	~E_ArcherArrow();

	/**
	@brief A function that updates the ArcherArrow.
	@param dt The delta time.
	*/
	void update(float dt);
};