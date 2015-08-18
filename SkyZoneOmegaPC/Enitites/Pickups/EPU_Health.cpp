#include "EPU_Health.h"

EPU_Health::EPU_Health(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: EPU_Pickup(sprite, pos, dimensions, screenDimensions, velocities)
{
}

EPU_Health::~EPU_Health()
{
}

void EPU_Health::draw(SDL_Renderer* renderer)
{
	sprite->pushSpriteToScreen(renderer, pos, dimensions, C_Vec2(), C_Vec2(300, 299));
}