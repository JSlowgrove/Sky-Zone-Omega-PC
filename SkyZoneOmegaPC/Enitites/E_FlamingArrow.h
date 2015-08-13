#pragma once

#include <SDL.h>
#include "E_Arrow.h"
#include "../Core/C_Vec2.h"
#include "../ParticleSystem/PS_ParticleEffect.h"

/**
@brief Contains the data and functions for the FlamingArrow.
@author Jamie Slowgrove
*/
class E_FlamingArrow : public E_Arrow
{
public:
	/**
	@brief Constructs the FlamingArrow object.
	@param sprite A pointer to the objects Texture.
	@param fireSprite A pointer to the particles Texture.
	@param pos The position of the FlamingArrow.
	@param dimensions The dimensions of the FlamingArrow.
	@param screenDimensions The dimensions of the screen.
	@param minTint The minimum tint for the fire particles.
	@param maxTint The maximum tint for the fire particles.
	*/
	E_FlamingArrow(C_Texture* sprite, C_Texture* fireSprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions,
		SDL_Colour minTint, SDL_Colour maxTint);

	/**
	@brief Destructs the FlamingArrow object.
	*/
	~E_FlamingArrow();

	/**
	@brief A function that updates the FlamingArrow.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function that draws the FlammingArrow to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	@brief Returns the value of damage.
	@returns damage The amount of damage the arrow does.
	*/
	int getDamage();

private:
	///The screen dimensions.
	C_Vec2 screenDimensions;
	///The amount of damage the arrow does.
	int damage;
	///The fire particle effect.
	PS_ParticleEffect* fireEffect;
};