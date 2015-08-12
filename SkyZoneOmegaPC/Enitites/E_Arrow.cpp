#include "E_Arrow.h"

E_Arrow::E_Arrow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 velocity)
	: E_Velocity(sprite, pos, dimensions, velocity), dead(false), deathParticles(false)
{
}

E_Arrow::~E_Arrow()
{
}

void E_Arrow::setDeadStatus(bool dead)
{
	this->dead = dead;
}

bool E_Arrow::getDeadStatus()
{
	return dead;
}

void E_Arrow::setDeathParticles(bool deathParticles)
{
	this->deathParticles = deathParticles;
}

bool E_Arrow::getDeathParticles()
{
	return deathParticles;
}