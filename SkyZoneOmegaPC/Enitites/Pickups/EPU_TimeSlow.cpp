#include "EPU_TimeSlow.h"

EPU_TimeSlow::EPU_TimeSlow(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions, 
	C_Vec2 velocities, float* universalSpeed)
	: EPU_Pickup(sprite, pos, dimensions, screenDimensions, velocities, "EPU_TimeSlow", universalSpeed)
{
}

EPU_TimeSlow::~EPU_TimeSlow()
{
}