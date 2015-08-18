#include "EB_Entity.h"

EB_Entity::EB_Entity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: sprite(sprite), pos(pos), dimensions(dimensions)
{
}

EB_Entity::~EB_Entity()
{
}

void EB_Entity::draw(SDL_Renderer* renderer)
{
	//Push the texture to the screen
	sprite->pushToScreen(renderer, pos, dimensions);
}

void EB_Entity::setPosition(C_Vec2 pos)
{
	this->pos = pos;
}

void EB_Entity::setX(float x)
{
	pos = C_Vec2(x, pos.y);
}

void EB_Entity::setY(float y)
{
	pos = C_Vec2(pos.x, y);
}

void EB_Entity::setDimensions(C_Vec2 dimensions)
{
	this->dimensions = dimensions;
}

void EB_Entity::setWidth(float width)
{
	dimensions = C_Vec2(width, dimensions.y);
}

void EB_Entity::setHeight(float height)
{
	dimensions = C_Vec2(dimensions.x, height);
}

C_Vec2 EB_Entity::getPosition()
{
	return pos;
}

C_Vec2 EB_Entity::getDimensions()
{
	return dimensions;
}