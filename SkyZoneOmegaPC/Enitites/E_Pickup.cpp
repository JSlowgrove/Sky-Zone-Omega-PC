#include "E_Pickup.h"

E_Pickup::E_Pickup(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: E_Velocity(sprite, pos, dimensions, velocities), dead(false)
{
}

E_Pickup::~E_Pickup()
{
}

void E_Pickup::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the pickup has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the bird to dead
		dead = true;
	}
}

void E_Pickup::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_Pickup::getDeadStatus()
{
	return dead;
}