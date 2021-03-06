#include "EA_Arrow.h"

EA_Arrow::EA_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocity, std::string iD, int damage, float* universalSpeed)
	: EB_Velocity(sprite, pos, dimensions, velocity, iD, universalSpeed), dead(false), deathParticles(false), damage(damage)
{
}

EA_Arrow::~EA_Arrow()
{
}

void EA_Arrow::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool EA_Arrow::getDeadStatus()
{
	return dead;
}

void EA_Arrow::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool EA_Arrow::getDeathParticles()
{
	return deathParticles;
}

int EA_Arrow::getDamage()
{
	return damage;
}