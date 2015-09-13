#pragma once

#include <SDL.h>
#include "../Base/EB_VelocityAnimated.h"
#include "../../Core/C_Vec2.h"
#include "../../Core/C_Timer.h"

/**
@brief Contains the data and functions for the Storm Cloud.
@author Jamie Slowgrove
*/
class EE_StormCloud : public EB_VelocityAnimated
{
public:
	/**
	@brief Constructs the StormCloud object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the StormCloud.
	@param dimensions The dimensions of the StormCloud.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EE_StormCloud(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed);

	/**
	@brief Destructs the StormCloud object.
	*/
	~EE_StormCloud();

	/**
	@brief A function that updates the StormCloud.
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

private:
	///A boolean for if the StormCloud is dead and to be deleted.
	bool dead;
	///A boolean for if the StormCloud should spawn particles upon death.
	bool deathParticles;
	
	/**
	@brief Animates the sprite of the storm cloud.
	@param dt The delta time.
	*/
	void animate(float dt);
};