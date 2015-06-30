#include "E_Velocity.h"

E_Velocity::E_Velocity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities)
	: E_Entity(sprite, pos, dimensions), velocities(velocities)
{
}

E_Velocity::~E_Velocity()
{
}

void E_Velocity::updatePosWithVelocities(float dt)
{
	//update the position with the velocity
	pos += (velocities * dt);
}

void E_Velocity::setVelocities(C_Vec2 velocities)
{
	this->velocities = velocities;
}

C_Vec2 E_Velocity::getVelocities()
{
	return velocities;
}