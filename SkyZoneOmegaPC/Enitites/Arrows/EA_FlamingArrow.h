#pragma once

#include <SDL.h>
#include "EA_Arrow.h"
#include "../../Core/C_Vec2.h"
#include "../../ParticleSystem/PS_ParticleEffect.h"

/**
@brief Contains the data and functions for the FlamingArrow.
@author Jamie Slowgrove
*/
class EA_FlamingArrow : public EA_Arrow
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
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EA_FlamingArrow(C_Texture* sprite, C_Texture* fireSprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions,
		SDL_Colour minTint, SDL_Colour maxTint, float* universalSpeed);

	/**
	@brief Destructs the FlamingArrow object.
	*/
	~EA_FlamingArrow();

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

private:
	///The screen dimensions.
	C_Vec2 screenDimensions;
	///The fire particle effect.
	PS_ParticleEffect* fireEffect;
};