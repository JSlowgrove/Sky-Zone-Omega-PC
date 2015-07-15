#pragma once

#include <vector>
#include "E_Player.h"
#include "E_StyphBird.h"
#include "E_Coin.h"
#include "E_StormCloud.h"

/**
@brief A class that manages all of the entities in the game with the exception of the player.
@author Jamie Slowgrove
*/
class E_EntityManager
{
public:
	/**
	@brief Constructs the Entity Manager.
	@param dimensions The screen dimensions.
	@param player A pointer to the player.
	@param renderer A pointer to the renderer.
	*/
	E_EntityManager(C_Vec2 dimensions, E_Player* player, SDL_Renderer* renderer);

	/**
	@brief Destructs the Entity Manager.
	*/
	~E_EntityManager();

	/**
	@brief Handles the input THIS IS TMP FOR DEBUGGING.
	@param incomingEvent A reference to the incoming SDL event.
	*/
	void input(SDL_Event& incomingEvent);

	/**
	@brief A function to update the Entities.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function to draw the Entities to the screen.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

private:
	///The screen dimensions
	C_Vec2 dimensions;
	///A pointer to the Player.
	E_Player* player;
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
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeDeadEntites();
};