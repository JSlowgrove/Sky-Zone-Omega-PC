#pragma once

#include <vector>
#include <unordered_map>
#include "E_Player.h"
#include "E_StyphBird.h"
#include "E_Coin.h"
#include "E_StormCloud.h"
#include "E_Health.h"
#include "E_PlayerArrow.h"
#include "E_ArcherArrow.h"
#include "E_Archer.h"
#include "../Core/C_Audio.h"
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

	/**
	@brief Gets the pointer to the coin texture.
	@returns The pointer to the coin texture.
	*/
	C_Texture* getCoinTexture();

	/**
	@brief Gets the pointer to the Health texture.
	@returns The pointer to the Health texture.
	*/
	C_Texture* getHealthTexture();

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

	///The Health texture.
	C_Texture* healthSprite;
	///The dimensions of the Health.
	C_Vec2 healthDimensions;
	///The vector array of Health.
	std::vector<E_Health*> health;

	///The Storm Cloud texture
	C_Texture* stormCloudSprite;
	///The dimensions of the storm clouds.
	C_Vec2 stormCloudsDimensions;
	///The vector array of Storm Clouds.
	std::vector<E_StormCloud*> stormClouds;

	///The Player Arrow texture.
	C_Texture* playerArrowSprite;
	///The Archer Arrow texture.
	C_Texture* archerArrowSprite;
	///The dimensions of the Arrows.
	C_Vec2 arrowDimensions;
	///The vector array of Player Arrows.
	std::vector<E_PlayerArrow*> playerArrows;
	///The vector array of Archer Arrows.
	std::vector<E_ArcherArrow*> archerArrows;

	///The Archer texture
	C_Texture* archerSprite;
	///The dimensions of the Archer.
	C_Vec2 archerDimensions;
	///The vector array of Archers.
	std::vector<E_Archer*> archers;

	///An unordered map of textures for use with the death particle effects.
	std::unordered_map<std::string, C_Texture*> deathEffectTextures;
	///The vector array of particle effects for use with entity death.
	std::vector<PS_ParticleEffect*> deathEffects;

	///The array of hit audio.
	C_Audio* healthLossSounds[3];

	///The health collect sound effect.
	C_Audio* healthCollectSound;

	///The coin collect sound effect.
	C_Audio* coinCollectSound;

	/**
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeDeadEntites();
	
	/**
	@brief A function that creates the particle effects for if the entities are killed.
	@param entityPos The position of the entity.
	@param entityVelocity The Velocity of the entity.
	@param entityDimensions The dimensions of the Entity.
	@param coinSpawn A boolean for if the entity should spawn coins.
	@param maxCoins The max number of coins to spawn.
	@param entityType The name of the type of entity that is killed.
	*/
	void createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, C_Vec2 entityDimensions, 
		bool coinSpawn, int maxCoins, std::string entityType);
	
	/**
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeCompletedEffects();

	/**
	@brief A function that handles all of the collision detection between the player and the entities.
	*/
	void entityCollisionDetection();
};