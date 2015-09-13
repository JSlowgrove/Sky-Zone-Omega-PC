#include "EA_PlayerArrow.h"

EA_PlayerArrow::EA_PlayerArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, float* universalSpeed)
	: EA_Arrow(sprite, pos, dimensions, C_Vec2(1500.0f, 0.0f), "EA_PlayerArrow", 1, universalSpeed), screenDimensions(screenDimensions)
{
}

EA_PlayerArrow::~EA_PlayerArrow()
{
}

void EA_PlayerArrow::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the arrow has gone off the screen
	if (pos.x > screenDimensions.x)
	{
		//set the arrow to dead
		dead = true;
	}
}