#include "EP_PlayerArcher.h"

EP_PlayerArcher::EP_PlayerArcher(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: EB_Animated(sprite, pos, dimensions, 6, C_Vec2(1, 1), 0.075f), fireArrow(false), firing(false)
{
}

EP_PlayerArcher::~EP_PlayerArcher()
{
}

void EP_PlayerArcher::update(float dt)
{
	//Update the animation
	animate(dt);
}

void EP_PlayerArcher::setFireArrow(bool fireArrow)
{
	this->fireArrow = fireArrow;
}

bool EP_PlayerArcher::getFireArrow()
{
	return fireArrow;
}

void EP_PlayerArcher::setFiring(bool firing)
{
	this->firing = firing;
}

bool EP_PlayerArcher::getFiring()
{
	return firing;
}

void EP_PlayerArcher::animate(float dt)
{
	// If the archer if firing an arrow
	if (firing)
	{
		//Update the animation
		animationTimer.upadateTimer(dt);

		//check if the timer has finished
		if (animationTimer.checkTimer())
		{
			//change the current sprite of animation
			spriteIndex.x++;
			if (spriteIndex.x > (float)(animationFrames - 1))
			{
				spriteIndex.x = 0.0f;
				firing = false;
			}
			//Check if an arrow should be fired
			if (spriteIndex.x == 3.0f)
			{
				fireArrow = true;
			}
			//reset the timer
			animationTimer.resetTimer();
		}
	}
}