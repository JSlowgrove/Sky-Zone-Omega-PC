#include "C_Music.h"

C_Music::C_Music(std::string file)
{
	//Load music from file
	music = Mix_LoadMUS(file.c_str());
	if (music == NULL)
	{
		//Failed loading file
		C_Utilities::logE("Failed to load " + file + ", Error is: " + std::string(Mix_GetError()));
	}
}

C_Music::~C_Music()
{
	//Free the audio
	Mix_FreeMusic(music);
	music = NULL;
	//Delete the pointers
	delete music;
}

void C_Music::startMusic()
{
	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music, -1);
	}
}

void C_Music::stopMusic()
{
	//Stops the music
	Mix_HaltMusic();
}

void C_Music::muteMusic()
{
	//Mutes the music
	Mix_VolumeMusic(0);
}

void C_Music::unmuteMusic()
{
	//Unmutes the music
	Mix_VolumeMusic(MIX_MAX_VOLUME);
}