#include "EE_Archer.h"

EE_Archer::EE_Archer(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EB_VelocityAnimated(sprite, pos, dimensions, C_Vec2(-350.0f, 0.0f), 5, C_Vec2(290, 325), 0.075f, "EE_Archer", universalSpeed),
	dead(false), coinSpawn(false), deathParticles(false), fireArrow(false), health(3)
{
}

EE_Archer::~EE_Archer()
{
}

void EE_Archer::update(float dt)
{
	//Update the animation
	animate(dt);

	//update the position
	updatePosWithVelocities(dt);

	//check if the archer has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the archer to dead
		dead = true;
	}
}

void EE_Archer::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool EE_Archer::getDeadStatus()
{
	return dead;
}

void EE_Archer::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool EE_Archer::getDeathParticles()
{
	return deathParticles;
}

void EE_Archer::setCoinSpawn(bool coinSpawn)
{
	this->coinSpawn = coinSpawn;
}

bool EE_Archer::getCoinSpawn()
{
	return coinSpawn;
}

void EE_Archer::setFireArrow(bool fireArrow)
{
	this->fireArrow = fireArrow;
}

bool EE_Archer::getFireArrow()
{
	return fireArrow;
}

void EE_Archer::decreaseHealth(int damage)
{
	health -= damage;

	//if the archer has no health left set as dead
	if (health <= 0)
	{
		setDeadStatus(true);
	}
}

void EE_Archer::animate(float dt)
{
	//set the length of the timer length depending on the universal speed
	animationTimer.setTimerLength((1 / *universalSpeed) * 0.075f);

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