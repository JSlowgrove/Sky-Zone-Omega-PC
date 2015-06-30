#pragma once

#include "../Enitites/E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief An object for a background layer that inherits Velocity Entity.
@author Jamie Slowgrove
*/
class B_Background : public E_Velocity
{
public:
	/**
	@brief Constructs the Background object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Background.
	@param dimensions The dimensions of the Background.
	@param velocities The velocities of the Background.
	*/
	B_Background(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities);

	/**
	@brief Destructs the Background object.
	*/
	~B_Background();

	/**
	@brief A function that updates the Background.
	@param dt The delta time.
	*/
	void update(float dt);
};