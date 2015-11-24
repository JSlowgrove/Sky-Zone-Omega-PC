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
@brief A State that contains and runs the End Game Menu.
@author Jamie Slowgrove
*/
class SM_EndGame : public S_State
{
public:
	/**
	@brief Constructs the State object.
	@param stateManager A pointer to the StateManager.
	@param renderer A pointer to the renderer.
	@param dimensions The screen dimensions.
	@param backgroundMusic The background music of the State.
	@param score The most score from the last game.
	*/
	SM_EndGame(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic, int score);

	/**
	@brief Destructs the State object.
	*/
	~SM_EndGame();

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
	///A pointer for the universal speed of the menu.
	float* universalSpeed;
	///A std::vector of the loaded scores
	std::vector<std::string> scores;
	///The retry Button
	UI_Button* retryButton;
	///The Exit Button
	UI_Button* exitButton;
	///The Game Over Image
	C_Texture* gameOver;
	///The Coin Image.
	C_Texture* coin;
	///The Score text
	C_Text* scoreText;
	///The dimensions of the coin image
	C_Vec2 coinDim;
	//The Y position of the Buttons
	float buttonYPos[1];
	//A boolean for if the scores file needs to be updated.
	bool updateScores;

	/**
	@brief A function to load in the scores.
	*/
	void loadScores();

	/**
	@brief A function to compare the scores.
	@param score The new score to compare to the old scores.
	*/
	void compareScores(int score);

	/**
	@brief A function to write out the scores.
	*/
	void writeScores();
};