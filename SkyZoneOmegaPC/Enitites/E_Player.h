#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the player.
@author Jamie Slowgrove
*/
class E_Player : public E_Velocity
{
public:
	/**
	@brief Constructs the Player object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Player.
	@param dimensions The dimensions of the Player.
	@param screenDimensions The dimensions of the screen.
	*/
	E_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions);

	/**
	@brief Destructs the Player object.
	*/
	~E_Player();

	/**
	@brief A function that updates the Player.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function that handles the Player input.
	*/
	void input(SDL_Event& incomingEvent);

private:
	///The user commands for the Player.
	bool up, down, left, right;
	///The screen Dimensions
	C_Vec2 screenDimensions;
};