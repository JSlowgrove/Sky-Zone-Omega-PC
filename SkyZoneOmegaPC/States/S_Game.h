#pragma once

#include <SDL.h>
#include <iostream>
#include "S_State.h"
#include "S_StateManager.h"
#include "../Core/C_Texture.h"
#include "../Core/C_Audio.h"
#include "../Core/C_Text.h"
#include "../Enitites/E_Background.h"

/**
@brief A State that contains and runs the Game.
@author Jamie Slowgrove
*/
class S_Game : public S_State
{
public:
	/**
	@brief Constructs the Game State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	*/
	S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions);

	/**
	@brief Destructs the Game State object.
	*/
	~S_Game();

	/**
	@brief Handles the Game State input.
	@returns If false then quit the Game State.
	*/
	bool input();

	/**
	@brief A function to update the Game State.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw the Game State to the screen.
	*/
	void draw();
	
private:
	///The Background images.
	C_Texture* background[3];
	///The bottom background layer backgrounds.
	E_Background* bottomBackgroundLayer;
	///The middle background layer backgrounds.
	E_Background* middleBackgroundLayer[2];
	///The top background layer backgrounds.
	E_Background* topBackgroundLayer[2];
};