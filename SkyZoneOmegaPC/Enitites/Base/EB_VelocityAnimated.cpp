#include "EB_VelocityAnimated.h"

EB_VelocityAnimated::EB_VelocityAnimated(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities,
	int animationFrames, C_Vec2 spriteDimensions, float animationLength, std::string iD)
	: EB_Animated(sprite, pos, dimensions, animationFrames, spriteDimensions, animationLength, iD), velocities(velocities)
{
}

EB_VelocityAnimated::~EB_VelocityAnimated()
{
}

void EB_VelocityAnimated::updatePosWithVelocities(float dt)
{
	//update the position with the velocity
	pos += (velocities * dt);
}

void EB_VelocityAnimated::setVelocities(C_Vec2 velocities)
{
	this->velocities = velocities;
}

C_Vec2 EB_VelocityAnimated::getVelocities()
{
	return velocities;
}