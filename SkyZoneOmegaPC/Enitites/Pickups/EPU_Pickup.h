#pragma once

#include <SDL.h>
#include "../Base/EB_Velocity.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Pickup object.
@author Jamie Slowgrove
*/
class EPU_Pickup : public EB_Velocity
{
public:
	/**
	@brief Constructs the Pickup object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Pickup.
	@param dimensions The dimensions of the Pickup.
	@param screenDimensions The dimensions of the screen.
	@param velocities The velocities of the Pickup.
	*/
	EPU_Pickup(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities);

	/**
	@brief Destructs the Pickup object.
	*/
	~EPU_Pickup();

	/**
	@brief A function that updates the Pickup.
	@param dt The delta time.
	*/
	void update(float dt);

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

protected:
	///A boolean for if the Pickup is dead and to be deleted.
	bool dead;
};