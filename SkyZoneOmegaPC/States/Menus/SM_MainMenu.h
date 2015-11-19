#pragma once

#include <SDL.h>
#include <iostream>
#include "../S_State.h"
#include "../S_StateManager.h"
#include "../../Core/C_Texture.h"
#include "../../Core/C_Audio.h"
#include "../../Core/C_Music.h"
#include "../../Core/C_Text.h"
#include "../../UI/UI_Button.h"
#include "../Menus/SM_Credits.h"
#include "../Menus/SM_Scores.h"
#include "../S_Game.h"

/**
@brief A State that contains and runs the Main Menu.
@author Jamie Slowgrove
*/
class SM_MainMenu : public S_State
{
public:
	/**
	@brief Constructs the State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	@param backgroundMusic The background music of the State.
	*/
	SM_MainMenu(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic);

	/**
	@brief Destructs the State object.
	*/
	~SM_MainMenu();

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
	///The Background Image.
	C_Texture* background;
	///The Coin Image.
	C_Texture* coin;
	///The Logo Image.
	C_Texture* logo;
	///The buttons y positions
	float buttonYpos[4];
	///The Credits button
	UI_Button* creditsButton;
	///The Scores Button
	UI_Button* scoresButton;
	///The Play Button;
	UI_Button* playButton;
	///The Exit Button
	UI_Button* exitButton;
	///The dimensions of the coin image
	C_Vec2 coinDim;
	///The dimensions of the logo image
	C_Vec2 logoDim;
	///A pointer for the universal speed of the menu.
	float* universalSpeed;
};