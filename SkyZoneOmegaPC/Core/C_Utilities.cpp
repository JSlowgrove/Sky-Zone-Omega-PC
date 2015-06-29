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
}