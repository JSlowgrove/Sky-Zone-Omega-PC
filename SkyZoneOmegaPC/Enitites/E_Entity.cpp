#include "E_Entity.h"

E_Entity::E_Entity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions)
	: sprite(sprite), pos(pos), dimensions(dimensions)
{
}

E_Entity::~E_Entity()
{
}

void E_Entity::draw(SDL_Renderer* renderer)
{
	//Push the texture to the screen
	sprite->pushToScreen(renderer, pos, dimensions);
}

void E_Entity::setPosition(C_Vec2 pos)
{
	this->pos = pos;
}

void E_Entity::setX(float x)
{
	pos = C_Vec2(x, pos.y);
}

void E_Entity::setY(float y)
{
	pos = C_Vec2(pos.x, y);
}

void E_Entity::setDimensions(C_Vec2 dimensions)
{
	this->dimensions = dimensions;
}

void E_Entity::setWidth(float width)
{
	dimensions = C_Vec2(width, dimensions.y);
}

void E_Entity::setHeight(float height)
{
	dimensions = C_Vec2(dimensions.x, height);
}

C_Vec2 E_Entity::getPosition()
{
	return pos;
}

C_Vec2 E_Entity::getDimensions()
{
	return dimensions;
}