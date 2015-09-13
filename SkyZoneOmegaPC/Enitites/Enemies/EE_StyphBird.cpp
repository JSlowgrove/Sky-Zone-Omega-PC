#include "EE_StyphBird.h"

EE_StyphBird::EE_StyphBird(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EB_Velocity(sprite, pos, dimensions, C_Vec2(-1500.0f, 0.0f), "EE_StyphBird", universalSpeed), dead(false), 
	coinSpawn(false), deathParticles(false)
{
}

EE_StyphBird::~EE_StyphBird()
{
}

void EE_StyphBird::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//check if the bird has gone off the screen
	if (pos.x < -dimensions.x)
	{
		//set the bird to dead
		dead = true;
	}
}

void EE_StyphBird::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool EE_StyphBird::getDeadStatus()
{
	return dead;
}

void EE_StyphBird::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool EE_StyphBird::getDeathParticles()
{
	return deathParticles;
}

void EE_StyphBird::setCoinSpawn(bool coinSpawn)
{
	this->coinSpawn = coinSpawn;
}

bool EE_StyphBird::getCoinSpawn()
{
	return coinSpawn;
}