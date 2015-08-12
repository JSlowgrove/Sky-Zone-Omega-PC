#include "C_Utilities.h"

namespace C_Utilities
{
	float getPI()
	{
		return PI;
	}

	float convertDegreeToRadian(float angle)
	{
		return (angle * PI / 180.0f);
	}

	float convertRadianToDegree(float angle)
	{
		return (angle * 180.0f / PI);
	}

	void logI(std::string message)
	{
		SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, message.c_str());
	}

	void logE(std::string message)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, message.c_str());
	}

	bool rectRectIntersect(C_Vec2 PosBoxA, C_Vec2 DimBoxA, C_Vec2 PosBoxB, C_Vec2 DimBoxB)
	{
		if (PosBoxA.x <= (PosBoxB.x + DimBoxB.x)
			&& PosBoxA.y <= (PosBoxB.y + DimBoxB.y)
			&& PosBoxB.x <= (PosBoxA.x + DimBoxA.x)
			&& PosBoxB.y <= (PosBoxA.y + DimBoxA.y))
		{
			return true;
		}
		return false;
	}
}