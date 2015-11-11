#pragma once

#include <SDL.h>
#include <iostream>
#include "../S_State.h"
#include "../S_StateManager.h"
#include "../../Core/C_Texture.h"
#include "../../Core/C_Audio.h"
#include "../../Core/C_Music.h"
#include "../../Core/C_Text.h"

/**
@brief A State that contains and runs the Help Menu.
@author Jamie Slowgrove
*/
class SM_Help : public S_State
{
public:
	/**
	@brief Constructs the State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	*/
	SM_Help(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions);

	/**
	@brief Destructs the State object.
	*/
	~SM_Help();

	/**
	@brief Handles the State input.
	@returns If false then quit the State.
	*/
	bool input();

	/**
	@brief A function to update the State.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw the State to the screen.
	*/
	void draw();

private:
	///The background music.
	C_Music* backgroundMusic;
};