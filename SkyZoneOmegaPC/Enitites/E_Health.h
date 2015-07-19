#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Health pickup.
@author Jamie Slowgrove
*/
class E_Health : public E_Velocity
{
public:
	/**
	@brief Constructs the Health object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Health.
	@param dimensions The dimensions of the Health.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Health.
	*/
	E_Health(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the Health object.
	*/
	~E_Health();

	/**
	@brief A function that updates the Health.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Draws the health to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	@brief Sets the value of dead.
	@param dead The new value of dead.
	*/
	void setDeadStatus(bool dead);

	/**
	@brief Returns the value of dead.
	@returns The value of dead.
	*/
	bool getDeadStatus();

private:
	///A boolean for if the Health is dead and to be deleted.
	bool dead;
};