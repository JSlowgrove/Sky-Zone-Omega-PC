#pragma once

#include <SDL.h>
#include <iostream>
#include "S_State.h"
#include "S_StateManager.h"
#include "../Core/C_Timer.h"
#include "../Core/C_Texture.h"
#include "../Core/C_Audio.h"
#include "../Core/C_Music.h"
#include "Menus//SM_MainMenu.h"

/**
@brief A State that contains and runs the splash screen.
@author Jamie Slowgrove
*/
class S_Splash : public S_State
{
public:
	/**
	@brief Constructs the State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	@param backgroundMusic The background music of the State.
	*/
	S_Splash(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic);

	/**
	@brief Destructs the State object.
	*/
	~S_Splash();

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
	///A pointer for the universal speed of the menu.
	float* universalSpeed;
	///The splash image
	C_Texture* splash;
	///The timer keeping the splash screen open
	C_Timer* splashTimer;
};