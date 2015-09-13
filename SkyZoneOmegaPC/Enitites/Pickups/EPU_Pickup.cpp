#include "EPU_Pickup.h"

EPU_Pickup::EPU_Pickup(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities, 
	std::string iD, float* universalSpeed)
	: EB_Velocity(sprite, pos, dimensions, velocities, iD, universalSpeed), dead(false)
{
}

EPU_Pickup::~EPU_Pickup()
{
}

void EPU_Pickup::update(float dt)
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

void EPU_Pickup::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool EPU_Pickup::getDeadStatus()
{
	return dead;
}