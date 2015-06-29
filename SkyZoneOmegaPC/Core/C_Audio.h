#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include "C_Utilities.h"

/**
@brief Handles music and sound effect using SDL_Mixer.
@author Jamie Slowgrove
*/
class C_Audio
{
public:
	/**
	@brief Constructs the Audio object.
	@param file The file to be loaded.
	@param music True for music file. False for sound file.
	*/
	C_Audio(std::string file, bool music);

	/**
	@brief Destructs the Audio object.
	*/
	~C_Audio();

	/**
	@brief Starts the Audio playing, also checks if not playing and starts again.
	*/
	void startAudio();

	/**
	@brief Plays the sound effect.
	*/
	void playEffect();

	/**
	@brief Stops the Audio playing.
	*/
	void stopAudio();

private:
	///Variable for use if it's a Music audio type.
	Mix_Music* audio;
	///Variable for use if it's a Sound effect type.
	Mix_Chunk* sound;
};