#pragma once

#include <SDL.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "S_State.h"
#include "S_StateManager.h"
#include "../Core/C_Texture.h"
#include "../Core/C_Audio.h"
#include "../Core/C_Music.h"
#include "../Core/C_Text.h"
#include "../BackgroundSystem/B_BackgroundManager.h"
#include "../Enitites/Player/EP_Player.h"
#include "../Enitites/E_EntityManager.h"
#include "../Gameplay/G_Gameplay.h"
#include "Menus/SM_MainMenu.h"
#include "Menus/SM_EndGame.h"
#include "Menus/SM_Help.h"
#include "../UI/UI_Button.h"

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
	@param backgroundMusic The background music of the State.
	*/
	S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic);

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
	///The mouse position.
	C_Vec2 mousePos;
	///The background music.
	C_Music* backgroundMusic;
	///The Background.
	B_BackgroundManager* background;
	///The Player.
	EP_Player* player;
	///The Player textures.
	C_Texture* playerSprite;
	C_Texture* playerArcherSprite;
	///The EntityManager.
	E_EntityManager* entityManager;
	///The Gameplay.
	G_Gameplay* gameplay;
	///The texture for the scoreScroll.
	C_Texture* scoreScroll;
	///The texture for the healthScroll.
	C_Texture* healthScroll;
	///The number of coins text to be displayed.
	C_Text* numOfCoins;
	///The Fire Effect texture.
	C_Texture* fireSprite;
	///The min tint colour for use with the fire effect.
	SDL_Colour minFireTint;
	///The max tint colour for use with the fire effect.
	SDL_Colour maxFireTint;
	///A pointer for the universal speed of the game.
	float* universalSpeed;
	///The fire arrow button.
	UI_Button* fireArrowButton;
	///The Help button.
	UI_Button* helpButton;
	///The help button spritesheet
	C_Texture* helpButtonSpritesheet;
	///The fire arrow button spritesheet
	C_Texture* fireArrowButtonSpritesheet;

	/**
	@brief A function to reset the Game.
	*/
	void resetGame();
};