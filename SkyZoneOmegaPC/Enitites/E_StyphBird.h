#pragma once

#include <SDL.h>
#include "E_Velocity.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains the data and functions for the Stymphalian Bird.
@author Jamie Slowgrove
*/
class E_StyphBird : public E_Velocity
{
public:
	/**
	@brief Constructs the StyphBird object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the StyphBird.
	@param dimensions The dimensions of the StyphBird.
	*/
	E_StyphBird(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

	/**
	@brief Destructs the StyphBird object.
	*/
	~E_StyphBird();

	/**
	@brief A function that updates the StyphBird.
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

	/**
	@brief Sets the value of the coinSpawn boolean.
	@param coinSpawn The new value of coinSpawn.
	*/
	void setCoinSpawn(bool coinSpawn);

	/**
	@brief Gets the value of the coinSpawn boolean.
	@returns The value of coinSpawn.
	*/
	bool getCoinSpawn();

private:
	///A boolean for if the StyphBird is dead and to be deleted.
	bool dead;
	///A boolean for if the StyphBird should turn into coins on death.
	bool coinSpawn;
	///A boolean for if the StyphBird should spawn particles upon death.
	bool deathParticles;
};