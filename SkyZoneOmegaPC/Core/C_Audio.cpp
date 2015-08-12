#include "C_Audio.h"

C_Audio::C_Audio(std::string file)
{
	//Load sound from file
	audio = Mix_LoadWAV(file.c_str());
	if (audio == NULL)
	{
		//Failed loading file
		C_Utilities::logE("Failed to load " + file + ", Error is: " + std::string(Mix_GetError()));
	}
}

C_Audio::~C_Audio()
{
	//Free the sound effect
	Mix_FreeChunk(audio);
	audio = NULL;
	//Delete the pointers
	delete audio;
}

void C_Audio::playEffect()
{
	//Play the sound
	Mix_PlayChannel(-1, audio, 0);
}