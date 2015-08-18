#include "EB_Velocity.h"

EB_Velocity::EB_Velocity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities, std::string iD)
	: EB_Entity(sprite, pos, dimensions, iD), velocities(velocities)
{
}

EB_Velocity::~EB_Velocity()
{
}

void EB_Velocity::updatePosWithVelocities(float dt)
{
	//update the position with the velocity
	pos += (velocities * dt);
}

void EB_Velocity::setVelocities(C_Vec2 velocities)
{
	this->velocities = velocities;
}

C_Vec2 EB_Velocity::getVelocities()
{
	return velocities;
}