#include "E_VelocityAnimated.h"

E_VelocityAnimated::E_VelocityAnimated(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities,
	int animationFrames, C_Vec2 spriteDimensions, float animationLength)
	: E_Animated(sprite, pos, dimensions, animationFrames, spriteDimensions, animationLength), velocities(velocities)
{
}

E_VelocityAnimated::~E_VelocityAnimated()
{
}

void E_VelocityAnimated::updatePosWithVelocities(float dt)
{
	//update the position with the velocity
	pos += (velocities * dt);
}

void E_VelocityAnimated::setVelocities(C_Vec2 velocities)
{
	this->velocities = velocities;
}

C_Vec2 E_VelocityAnimated::getVelocities()
{
	return velocities;
}