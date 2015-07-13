#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Timer.h"

/**
@brief Contains the data and functions for the Storm Cloud.
@author Jamie Slowgrove
*/
class E_StormCloud : public E_Velocity
{
public:
	/**
	@brief Constructs the StormCloud object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the StormCloud.
	@param dimensions The dimensions of the StormCloud.
	@param screenDimensions The dimensions of the screen.
	*/
	E_StormCloud(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions);

	/**
	@brief Destructs the StormCloud object.
	*/
	~E_StormCloud();

	/**
	@brief A function that updates the StormCloud.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Draws the StormCloud to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	@brief Returns the value of dead.
	@returns The value of dead.
	*/
	bool getDeadStatus();

private:
	///A boolean for if the StormCloud is dead and to be deleted.
	bool dead;
	///The dimensions of the sprite in the spritesheet.
	C_Vec2 spriteDimensions;
	///The index of the current sprite in the spritesheet.
	C_Vec2 spriteIndex;
	///The animation timer.
	C_Timer animationTimer;

	/**
	@brief Animates the sprite of the storm cloud.
	@param dt The delta time.
	*/
	void animate(float dt);
};