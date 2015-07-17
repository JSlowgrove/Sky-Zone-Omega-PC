#include "E_StormCloud.h"

E_StormCloud::E_StormCloud(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_VelocityAnimated(sprite, pos, dimensions, C_Vec2(-500.0f, 0.0f), 3, C_Vec2(562, 500), 0.075f), dead(false), deathParticles(false)
{
	//Initialise the sprite position
	int spriteYindex = rand() % 4;
	spriteIndex = C_Vec2(0, spriteYindex);
}

E_StormCloud::~E_StormCloud()
{
}

void E_StormCloud::update(float dt)
{
	//Update the animation
	animate(dt);

	//update the position
	updatePosWithVelocities(dt);

	//check if the cloud has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the bird to dead
		dead = true;
	}
}

void E_StormCloud::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_StormCloud::getDeadStatus()
{
	return dead;
}

void E_StormCloud::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool E_StormCloud::getDeathParticles()
{
	return deathParticles;
}

void E_StormCloud::animate(float dt)
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
			//set the length of the next animation frame
			animationTimer.setTimerLength(0.5f);
		}
		else if (spriteIndex.x > 0.0f)
		{
			//set the length of the next animation frame
			animationTimer.setTimerLength(0.075f);
		}
	}
}