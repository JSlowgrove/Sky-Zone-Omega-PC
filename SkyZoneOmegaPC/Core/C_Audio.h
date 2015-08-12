#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <string>
#include "C_Utilities.h"

/**
@brief Handles audio using SDL_Mixer.
@author Jamie Slowgrove
*/
class C_Audio
{
public:
	/**
	@brief Constructs the Audio object.
	@param file The file to be loaded.
	*/
	C_Audio(std::string file);

	/**
	@brief Destructs the Audio object.
	*/
	~C_Audio();

	/**
	@brief Plays the sound effect.
	*/
	void playEffect();

private:
	///Variable for the audio.
	Mix_Chunk* audio;
};