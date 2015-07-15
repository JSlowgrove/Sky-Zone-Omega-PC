#include "E_Coin.h"

E_Coin::E_Coin(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: E_Velocity(sprite, pos, dimensions, velocities), dead(false)
{
}

E_Coin::~E_Coin()
{
}

void E_Coin::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the coin has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the bird to dead
		dead = true;
	}
}

bool E_Coin::getDeadStatus()
{
	return dead;
}