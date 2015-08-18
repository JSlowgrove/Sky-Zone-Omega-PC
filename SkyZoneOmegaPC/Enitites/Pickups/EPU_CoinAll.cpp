#include "EPU_CoinAll.h"

EPU_CoinAll::EPU_CoinAll(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: EPU_Pickup(sprite, pos, dimensions, screenDimensions, velocities, "EPU_CoinAll")
{
}

EPU_CoinAll::~EPU_CoinAll()
{
}