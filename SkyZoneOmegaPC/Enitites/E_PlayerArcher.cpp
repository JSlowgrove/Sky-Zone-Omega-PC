#include "E_PlayerArcher.h"

E_PlayerArcher::E_PlayerArcher(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_Animated(sprite, pos, dimensions, 6, C_Vec2(1, 1), 0.075f), fireArrow(false), firing(false)
{
}

E_PlayerArcher::~E_PlayerArcher()
{
}

void E_PlayerArcher::update(float dt)
{
	//Update the animation
	animate(dt);
}

void E_PlayerArcher::setFireArrow(bool fireArrow)
{
	this->fireArrow = fireArrow;
}

bool E_PlayerArcher::getFireArrow()
{
	return fireArrow;
}

void E_PlayerArcher::setFiring(bool firing)
{
	this->firing = firing;
}

bool E_PlayerArcher::getFiring()
{
	return firing;
}

void E_PlayerArcher::animate(float dt)
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