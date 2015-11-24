#pragma once

#include <SDL.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../S_State.h"
#include "../S_StateManager.h"
#include "../../Core/C_Texture.h"
#include "../../Core/C_Audio.h"
#include "../../Core/C_Music.h"
#include "../../Core/C_Text.h"
#include "../../UI/UI_Button.h"
#include "SM_MainMenu.h"

/**
@brief A State that contains and runs the Scores Menu.
@author Jamie Slowgrove
*/
class SM_Scores : public S_State
{
public:
	/**
	@brief Constructs the State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	@param backgroundMusic The background music of the State.
	*/
	SM_Scores(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic);

	/**
	@brief Destructs the State object.
	*/
	~SM_Scores();

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
	///The Button Background Image.
	C_Texture* buttonBackground;
	///The Scores Background Image.
	C_Texture* scoresBackground;
	///A pointer for the universal speed of the menu.
	float* universalSpeed;
	///A std::vector of the loaded scores
	std::vector<std::string> scores;
	//The std::vector of Scores Text
	std::vector<C_Text*> scoresText;
	///The Exit Button
	UI_Button* exitButton;
	///The Coin Image.
	C_Texture* coin;
	///The dimensions of the coin image
	C_Vec2 coinDim;
	//The Y position of the Button
	float buttonYPos;

	/**
	@brief A function to load in the scores.
	*/
	void loadScores();
};