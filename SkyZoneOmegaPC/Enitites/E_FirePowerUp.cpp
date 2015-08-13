#include "E_FirePowerUp.h"

E_FirePowerUp::E_FirePowerUp(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, C_Vec2 velocities)
	: E_Pickup(sprite, pos, dimensions, screenDimensions, velocities)
{
}

E_FirePowerUp::~E_FirePowerUp()
{
}