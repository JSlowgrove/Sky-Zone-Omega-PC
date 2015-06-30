#include "B_Background.h"

B_Background::B_Background(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocities)
	: E_Velocity(sprite, pos, dimensions, velocities)
{
}

B_Background::~B_Background()
{
}

void B_Background::update(float dt)
{
	//update the position of the background
	updatePosWithVelocities(dt);

	//Test if the background is off the screen
	if (pos.x <= -dimensions.x)
	{
		//Reset the background position
		pos.x += (dimensions.x * 2.0f);
	}
}