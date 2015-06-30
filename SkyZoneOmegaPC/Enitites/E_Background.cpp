#include "E_Background.h"

E_Background::E_Background(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float velocity)
	: E_Entity(sprite, pos, dimensions), velocity(velocity)
{
}

E_Background::~E_Background()
{
}

void E_Background::update(float dt)
{
	//update the position of the background
	pos.x += velocity * dt;

	//Test if the background is off the screen
	if (pos.x <= -dimensions.x)
	{
		//Reset the background position
		pos.x += (dimensions.x * 2.0f);
	}
}

void E_Background::setVelocity(float velocity)
{
	this->velocity = velocity;
}