#pragma once

#include <vector>
#include "E_Player.h"
#include "E_StyphBird.h"
#include "E_Coin.h"
#include "E_StormCloud.h"
#include "../ParticleSystem/PS_ParticleEffect.h"

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
	*/
	void draw();

private:
	///The screen dimensions
	C_Vec2 dimensions;
	///A pointer to the renderer.
	SDL_Renderer* renderer;

	///A pointer to the Player.
	E_Player* player;

	///The StyphBird texture
	C_Texture* styphBirdSprite;
	///The dimensions of the StyphBirds.
	C_Vec2 styphBirdDimensions;
	///The vector array of StyphBirds
	std::vector<E_StyphBird*> styphBirds;

	///The Coin texture.
	C_Texture* coinSprite;
	///The dimensions of the coins.
	C_Vec2 coinDimensions;
	///The vector array of Coins.
	std::vector<E_Coin*> coins;

	///The Storm Cloud texture
	C_Texture* stormCloudSprite;
	///The dimensions of the storm clouds.
	C_Vec2 stormCloudsDimensions;
	///The vector array of Storm Clouds.
	std::vector<E_StormCloud*> stormClouds;

	///The texture for use with the death sprites.
	C_Texture* deathEffectTexture;
	///The vector array of particle effects for use with entity death.
	std::vector<PS_ParticleEffect*> deathEffects;

	/**
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeDeadEntites();
	
	/**
	@brief A function that creates the particle effects for if the entities are killed.
	@param entityPos The position of the entity.
	@param entityVelocity The Velocity of the entity.
	@param coinSpawn A boolean for if the entity should spawn coins.
	@param maxCoins The max number of coins to spawn.
	*/
	void createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, bool coinSpawn, int maxCoins);
	
	/**
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeCompletedEffects();
};