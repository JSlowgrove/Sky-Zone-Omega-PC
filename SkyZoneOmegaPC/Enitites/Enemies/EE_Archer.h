#pragma once

#include <SDL.h>
#include "..//Base/EB_VelocityAnimated.h"
#include "../../Core/C_Vec2.h"
#include "../../Core/C_Timer.h"

/**
@brief Contains the data and functions for the Archer.
@author Jamie Slowgrove
*/
class EE_Archer : public EB_VelocityAnimated
{
public:
	/**
	@brief Constructs the Archer object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Archer.
	@param dimensions The dimensions of the Archer.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EE_Archer(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed);

	/**
	@brief Destructs the Archer object.
	*/
	~EE_Archer();

	/**
	@brief A function that updates the Archer.
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

	/**
	@brief Sets the value of the fireArrow boolean.
	@param coinSpawn The new value of fireArrow.
	*/
	void setFireArrow(bool fireArrow);

	/**
	@brief Gets the value of the fireArrow boolean.
	@returns The value of fireArrow.
	*/
	bool getFireArrow();

	/**
	@brief Decreases the health of the Archer.
	@brief damage The amount the health should decrease by.
	*/
	void decreaseHealth(int damage);

private:
	///A boolean for if the Archer is dead and to be deleted.
	bool dead;
	///A boolean for if the Archer should turn into coins on death.
	bool coinSpawn;
	///A boolean for if the Archer should spawn particles upon death.
	bool deathParticles;
	///A boolean for if the Archer should fire an arrow.
	bool fireArrow;
	///The health of the Archer.
	int health;

	/**
	@brief Animates the sprite of the Archer.
	@param dt The delta time.
	*/
	void animate(float dt);
};