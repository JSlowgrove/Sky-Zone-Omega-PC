#pragma once

#include "E_Entity.h"
#include "../Core/C_Vec2.h"

/**
@brief An object for a background layer that inherits Entity.
@author Jamie Slowgrove
*/
class E_Background : public E_Entity
{
public:
	/**
	@brief Constructs the Background object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Background.
	@param dimensions The dimensions of the Background.
	@param velocity The velocity of the Background.
	*/
	E_Background(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float velocity);

	/**
	@brief Destructs the Background object.
	*/
	~E_Background();

	/**
	@brief A function that updates the Background.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Sets the velocity of the Background to the inputed velocity.
	@param velocity The inputed velocity.
	*/
	void setVelocity(float velocity);

private:
	///The Velocity of the background.
	float velocity;
};