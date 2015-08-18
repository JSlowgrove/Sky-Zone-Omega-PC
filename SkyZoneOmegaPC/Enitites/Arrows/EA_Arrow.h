#pragma once

#include <SDL.h>
#include "../Base/EB_Velocity.h"
#include "../../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Arrow.
@author Jamie Slowgrove
*/
class EA_Arrow : public EB_Velocity
{
public:
	/**
	@brief Constructs the Arrow object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Arrow.
	@param dimensions The dimensions of the Arrow.
	@param velocity The velocity of the Arrow.
	*/
	EA_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocity);

	/**
	@brief Destructs the Arrow object.
	*/
	~EA_Arrow();

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

	/**
	@brief Sets the value of deathParticles.
	@param deathParticles The new value of deathParticles.
	*/
	void setDeathParticles(bool deathParticles);

	/**
	@brief Returns the value of deathParticles.
	@returns The value of deathParticles.
	*/
	bool getDeathParticles();

protected:
	///A boolean for if the Arrow is dead and to be deleted.
	bool dead;
	///A boolean for if the Arrow should spawn particles upon death.
	bool deathParticles;
};