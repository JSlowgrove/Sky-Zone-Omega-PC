#include "E_Health.h"

E_Health::E_Health(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: E_Pickup(sprite, pos, dimensions, screenDimensions, velocities)
{
}

E_Health::~E_Health()
{
}

void E_Health::draw(SDL_Renderer* renderer)
{
	sprite->pushSpriteToScreen(renderer, pos, dimensions, C_Vec2(), C_Vec2(300, 299));
}