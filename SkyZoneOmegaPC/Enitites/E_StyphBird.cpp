#include "E_StyphBird.h"

E_StyphBird::E_StyphBird(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_Velocity(sprite, pos, dimensions, C_Vec2(-1500.0f, 0.0f)), dead(false), coinSpawn(false), deathParticles(false)
{
}

E_StyphBird::~E_StyphBird()
{
}

void E_StyphBird::update(float dt)
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

void E_StyphBird::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_StyphBird::getDeadStatus()
{
	return dead;
}

void E_StyphBird::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool E_StyphBird::getDeathParticles()
{
	return deathParticles;
}

void E_StyphBird::setCoinSpawn(bool coinSpawn)
{
	this->coinSpawn = coinSpawn;
}

bool E_StyphBird::getCoinSpawn()
{
	return coinSpawn;
}