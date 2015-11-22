#include "EE_StormCloud.h"

EE_StormCloud::EE_StormCloud(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EB_VelocityAnimated(sprite, pos, dimensions, C_Vec2(-500.0f, 0.0f), 3, C_Vec2(562, 401), 0.075f, "EE_StormCloud", universalSpeed),
	dead(false), deathParticles(false), cloudDim(C_Vec2(562.0f, 298.0f))
{
	//Initialise the sprite position
	int spriteYindex = rand() % 4;
	spriteIndex = C_Vec2(0, spriteYindex);

	//Work out the percentage of the cloud height in the sprite
	float cloudPercent = (cloudDim.y / 401.0f) * 100.0f;
	//Work out 1% of the sprite height
	float onePercent = dimensions.y * 0.01f;
	//Work out the cloud height
	float cloudHeight = cloudPercent * onePercent;

	//Scale the cloud dimensions
	cloudDim = C_Vec2(dimensions.x, cloudHeight);
}

EE_StormCloud::~EE_StormCloud()
{
}

void EE_StormCloud::update(float dt)
{
	//Update the animation
	animate(dt);

	//update the position
	updatePosWithVelocities(dt);

	//check if the cloud has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the cloud to dead
		dead = true;
	}
}

void EE_StormCloud::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool EE_StormCloud::getDeadStatus()
{
	return dead;
}

void EE_StormCloud::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool EE_StormCloud::getDeathParticles()
{
	return deathParticles;
}

C_Vec2 EE_StormCloud::getCloudDim()
{
	return cloudDim;
}

void EE_StormCloud::animate(float dt)
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
			animationTimer.resetTimerLength((1 / *universalSpeed) * 0.5f);
		}
		else if (spriteIndex.x > 0.0f)
		{
			//set the length of the next animation frame
			animationTimer.resetTimerLength((1 / *universalSpeed) * 0.075f);
		}
	}
}