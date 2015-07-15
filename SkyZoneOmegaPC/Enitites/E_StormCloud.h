#pragma once

#include <SDL.h>
#include "E_VelocityAnimated.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Timer.h"

/**
@brief Contains the data and functions for the Storm Cloud.
@author Jamie Slowgrove
*/
class E_StormCloud : public E_VelocityAnimated
{
public:
	/**
	@brief Constructs the StormCloud object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the StormCloud.
	@param dimensions The dimensions of the StormCloud.
	*/
	E_StormCloud(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

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
	@brief Returns the value of dead.
	@returns The value of dead.
	*/
	bool getDeadStatus();

private:
	///A boolean for if the StormCloud is dead and to be deleted.
	bool dead;
	
	/**
	@brief Animates the sprite of the storm cloud.
	@param dt The delta time.
	*/
	void animate(float dt);
};