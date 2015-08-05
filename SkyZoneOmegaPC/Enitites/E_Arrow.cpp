#include "E_Arrow.h"

E_Arrow::E_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_Velocity(sprite, pos, dimensions, C_Vec2(1500.0f, 0.0f)), dead(false)
{
}

E_Arrow::~E_Arrow()
{
}

void E_Arrow::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the arrow has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the arrow to dead
		dead = true;
	}
}

void E_Arrow::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_Arrow::getDeadStatus()
{
	return dead;
}