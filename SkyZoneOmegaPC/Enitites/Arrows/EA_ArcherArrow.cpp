#include "EA_ArcherArrow.h"

EA_ArcherArrow::EA_ArcherArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EA_Arrow(sprite, pos, dimensions, C_Vec2(-1500.0f, 0.0f), "EA_ArcherArrow", 1, universalSpeed)
{
}

EA_ArcherArrow::~EA_ArcherArrow()
{
}

void EA_ArcherArrow::update(float dt)
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