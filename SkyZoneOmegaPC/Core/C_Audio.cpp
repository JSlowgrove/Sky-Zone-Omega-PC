#include "C_Audio.h"

C_Audio::C_Audio(std::string file, bool music)
{
	//If it's a music file
	if (music)
	{
		//Load music from file
		audio = Mix_LoadMUS(file.c_str());
		if (audio == NULL)
		{
			//Failed loading file
			C_Utilities::logE("Failed to load " + file + ", Error is: " + std::string(Mix_GetError()));
		}
		//Set sound to null
		sound = NULL;
	}
	//If it's a sound effect file
	else
	{
		//Load sound from file
		sound = Mix_LoadWAV(file.c_str());
		if (sound == NULL)
		{
			//Failed loading file
			C_Utilities::logE("Failed to load " + file + ", Error is: " + std::string(Mix_GetError()));
		}
		//Set audio to null
		audio = NULL;
	}
}

C_Audio::~C_Audio()
{
	//Free the audio
	Mix_FreeMusic(audio);
	audio = NULL;
	//Free the sound effect
	Mix_FreeChunk(sound);
	sound = NULL;
	//Delete the pointers
	delete sound;
}

void C_Audio::startAudio()
{
	//If there is no audio playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the audio
		Mix_PlayMusic(audio, -1);
	}
}

void C_Audio::playEffect()
{
	//Play the sound
	Mix_PlayChannel(-1, sound, 0);
}

void C_Audio::stopAudio()
{
	//Stops the music
	Mix_HaltMusic();
}