#pragma once

#include <SDL.h>
#include <iostream>
#include "../Core/C_Texture.h"
#include "B_Background.h"

/**
@brief Contains the functions to manage the background objects.
@author Jamie Slowgrove
*/
class B_BackgroundManager
{
public:
	/**
	@brief Constructs the Background Manager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	B_BackgroundManager(SDL_Renderer* renderer, C_Vec2 dimensions, float* universalSpeed);

	/**
	@brief Destructs the Background Manager.
	*/
	~B_BackgroundManager();

	/**
	@brief A function to update the Backgrounds.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw the Backgrounds to the screen.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

private:
	///The Background images.
	C_Texture* background[3];
	///The bottom background layer backgrounds.
	B_Background* bottomBackgroundLayer;
	///The middle background layer backgrounds.
	B_Background* middleBackgroundLayer[2];
	///The top background layer backgrounds.
	B_Background* topBackgroundLayer[2];
	///A pointer for the universal speed of the game.
	float* universalSpeed;
};