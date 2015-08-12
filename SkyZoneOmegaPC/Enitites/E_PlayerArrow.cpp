#include "E_PlayerArrow.h"

E_PlayerArrow::E_PlayerArrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions)
	: E_Arrow(sprite, pos, dimensions, C_Vec2(1500.0f, 0.0f)), screenDimensions(screenDimensions), damage(1)
{
}

E_PlayerArrow::~E_PlayerArrow()
{
}

void E_PlayerArrow::update(float dt)
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

int E_PlayerArrow::getDamage()
{
	return damage;
}