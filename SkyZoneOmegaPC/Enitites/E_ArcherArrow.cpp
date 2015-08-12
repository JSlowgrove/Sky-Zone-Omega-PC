#include "E_ArcherArrow.h"

E_ArcherArrow::E_ArcherArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_Arrow(sprite, pos, dimensions, C_Vec2(-1500.0f, 0.0f))
{
}

E_ArcherArrow::~E_ArcherArrow()
{
}

void E_ArcherArrow::update(float dt)
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