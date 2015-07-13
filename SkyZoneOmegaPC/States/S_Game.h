#pragma once

#include <SDL.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "S_State.h"
#include "S_StateManager.h"
#include "../Core/C_Texture.h"
#include "../Core/C_Audio.h"
#include "../Core/C_Text.h"
#include "../BackgroundSystem/B_BackgroundManager.h"
#include "../Enitites/E_Player.h"
#include "../Enitites/E_StyphBird.h"
#include "../Enitites/E_Coin.h"
#include "../Enitites/E_StormCloud.h"

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
	///The mouse position
	C_Vec2 mousePos;
	///The Background.
	B_BackgroundManager* background;
	///The Player.
	E_Player* player;
	///The Player texture.
	C_Texture* playerSprite;
	///The StyphBird texture
	C_Texture* styphBirdSprite;
	///The vector array of StyphBirds
	std::vector<E_StyphBird*> styphBirds;
	///The Coin texture
	C_Texture* coinSprite;
	///The vector array of Coins
	std::vector<E_Coin*> coins;
	///The Storm Cloud texture
	C_Texture* stormCloudSprite;
	///The vector array of Storm Clouds
	std::vector<E_StormCloud*> stormClouds;

	/**
	@brief A function that deletes all of the entities flaged as dead.
	*/
	void removeDeadEntites();
};