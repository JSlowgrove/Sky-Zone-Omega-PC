#include "E_StyphBird.h"

E_StyphBird::E_StyphBird(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_Velocity(sprite, pos, dimensions, C_Vec2(-1500.0f, 0.0f)), dead(false)
{
}

E_StyphBird::~E_StyphBird()
{
}

void E_StyphBird::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the bird has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the bird to dead
		dead = true;
	}
}

bool E_StyphBird::getDeadStatus()
{
	return dead;
}