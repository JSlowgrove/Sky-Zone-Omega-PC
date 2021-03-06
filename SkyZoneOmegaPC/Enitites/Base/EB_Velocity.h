#pragma once

#include "EB_Entity.h"
#include "../../Core/C_Vec2.h"

/**
@brief An Entity that contains velocities.
@author Jamie Slowgrove
*/
class EB_Velocity : public EB_Entity
{
public:
	/**
	@brief Constructs the Velocity Entity.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	@param velocity The velocities of the Entity.
	@param iD The ID of the Entity type.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EB_Velocity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities, std::string iD, float* universalSpee);

	/**
	@brief Destructs the Velocity Entity object.
	*/
	~EB_Velocity();

	/**
	@brief A pure virtual function that updates the Entity.
	@param dt The delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	@brief Updates the position of the Entity using the velocities.
	@param dt The delta time.
	*/
	void updatePosWithVelocities(float dt);

	/**
	@brief Sets the velocities of the Entity.
	@param velocities The inputed velocity.
	*/
	void setVelocities(C_Vec2 velocity);

	/**
	@brief Gets the velocities of the Entity.
	@returns The velocities of the Entity.
	*/
	C_Vec2 getVelocities();

protected:
	///The velocities of the Entity.
	C_Vec2 velocities;
};