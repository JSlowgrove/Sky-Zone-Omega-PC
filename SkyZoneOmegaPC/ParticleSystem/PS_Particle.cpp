#include "PS_Particle.h"

PS_Particle::PS_Particle(C_Texture* texture, float scaleValue, C_Vec2 direction, float moveSpeed, C_Vec2 pos)
	: texture(texture), scaleValue(scaleValue), direction(direction), moveSpeed(moveSpeed), pos(pos)
{
}

PS_Particle::~PS_Particle()
{
}

void PS_Particle::update(float dt)
{
	//Update the position of the particle
	move(direction * moveSpeed * dt);
}

void PS_Particle::draw(SDL_Renderer* renderer)
{
	//Draw the texture to the screen
	texture->pushToScreen(renderer, pos, C_Vec2(scaleValue, scaleValue));
}

void PS_Particle::move(C_Vec2 movement)
{
	//Move the particle
	pos += movement;
}

void PS_Particle::setPosition(C_Vec2 pos)
{
	this->pos = pos;
}

void PS_Particle::setScale(float scaleValue)
{
	this->scaleValue = scaleValue;
}

void PS_Particle::setMoveSpeed(float moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void PS_Particle::setDirection(C_Vec2 direction)
{
	this->direction = direction;
}

float PS_Particle::getMoveSpeed()
{
	return moveSpeed;
}

C_Vec2 PS_Particle::getPosition()
{
	return pos;
}

C_Vec2 PS_Particle::getDirection()
{
	return direction;
}

float PS_Particle::getScale()
{
	return scaleValue;
}