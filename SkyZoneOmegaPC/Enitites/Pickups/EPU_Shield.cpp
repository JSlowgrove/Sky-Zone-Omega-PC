#include "EPU_Shield.h"

EPU_Shield::EPU_Shield(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, 
	C_Vec2 velocities, float* universalSpeed)
	: EPU_Pickup(sprite, pos, dimensions, screenDimensions, velocities, "EPU_Shield", universalSpeed)
{
}

EPU_Shield::~EPU_Shield()
{
}