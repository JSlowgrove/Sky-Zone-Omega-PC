#pragma once

#include "EB_Animated.h"
#include "../../Core/C_Vec2.h"

/**
@brief An Entity that contains velocities and uses a spritesheet for animation.
@author Jamie Slowgrove
*/
class EB_VelocityAnimated : public EB_Animated
{
public:
	/**
	@brief Constructs the Velocity Animated Entity.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	@param velocity The velocities of the Entity.
	@param animationFrames The number of animation frames in the spritesheet.
	@param spriteDimensions The dimensions of the sprite.
	@param animationLength The length of each animation frame.
	@param iD The ID of the Entity type.
	*/
	EB_VelocityAnimated(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities,
		int animationFrames, C_Vec2 spriteDimensions, float animationLength, std::string iD);

	/**
	@brief Destructs the Velocity Animated Entity object.
	*/
	~EB_VelocityAnimated();

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