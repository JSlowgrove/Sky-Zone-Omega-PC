#include "E_Archer.h"

E_Archer::E_Archer(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: E_VelocityAnimated(sprite, pos, dimensions, C_Vec2(-350.0f, 0.0f), 5, C_Vec2(1, 1), 0.075f), 
	dead(false), coinSpawn(false), deathParticles(false)
{
}

E_Archer::~E_Archer()
{
}

void E_Archer::update(float dt)
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

void E_Archer::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_Archer::getDeadStatus()
{
	return dead;
}

void E_Archer::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool E_Archer::getDeathParticles()
{
	return deathParticles;
}

void E_Archer::setCoinSpawn(bool coinSpawn)
{
	this->coinSpawn = coinSpawn;
}

bool E_Archer::getCoinSpawn()
{
	return coinSpawn;
}