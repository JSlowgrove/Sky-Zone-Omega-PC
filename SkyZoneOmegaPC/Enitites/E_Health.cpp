#include "E_Health.h"

E_Health::E_Health(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: E_Velocity(sprite, pos, dimensions, velocities), dead(false)
{
}

E_Health::~E_Health()
{
}

void E_Health::update(float dt)
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

void E_Health::draw(SDL_Renderer* renderer)
{
	sprite->pushSpriteToScreen(renderer, pos, dimensions, C_Vec2(), C_Vec2(300, 299));
}

void E_Health::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_Health::getDeadStatus()
{
	return dead;
}