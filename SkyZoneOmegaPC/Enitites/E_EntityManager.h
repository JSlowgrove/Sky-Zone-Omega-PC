#pragma once

#include <vector>
#include <unordered_map>
#include "Player/EP_Player.h"
#include "Enemies/EE_StyphBird.h"
#include "Enemies/EE_StormCloud.h"
#include "Enemies/EE_Archer.h"
#include "Pickups/EPU_Coin.h"
#include "Pickups/EPU_Health.h"
#include "Pickups/EPU_Flaming.h"
#include "Pickups/EPU_CoinAll.h"
#include "Pickups/EPU_KillAll.h"
#include "Pickups/EPU_Shield.h"
#include "Arrows/EA_PlayerArrow.h"
#include "Arrows/EA_FlamingArrow.h"
#include "Arrows/EA_ArcherArrow.h"
#include "../Core/C_Audio.h"
#include "../Core/C_Timer.h"
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
	@param fireSprite A pointer to the particles Texture.
	@param minTint The minimum tint for the fire particles.
	@param maxTint The maximum tint for the fire particles.
	*/
	E_EntityManager(C_Vec2 dimensions, EP_Player* player, SDL_Renderer* renderer, C_Texture* fireSprite, 
		SDL_Colour minFireTint, SDL_Colour maxFireTint);

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
	EP_Player* player;
	///The dimensions of the spawn-able entities.
	C_Vec2 entityDimensions[9];
	///The dimensions of the Arrows.
	C_Vec2 arrowDimensions;
	///A timer for the entity spawner.
	C_Timer spawnTimer;
	///An unordered map of the sprite textures.
	std::unordered_map<std::string, C_Texture*> textures;

	//Enemies

	///The vector array of StyphBirds
	std::vector<EE_StyphBird*> styphBirds;
	///The vector array of Storm Clouds.
	std::vector<EE_StormCloud*> stormClouds;
	///The vector array of Archers.
	std::vector<EE_Archer*> archers;

	//Pickups

	///The vector array of Coins.
	std::vector<EPU_Coin*> coins;
	///The vector array of Health.
	std::vector<EPU_Health*> healthPickups;
	///The vector array of Flaming power ups.
	std::vector<EPU_Flaming*> flamingPickups;
	///The vector array of killAll power ups.
	std::vector<EPU_KillAll*> killAllPickups;
	///The vector array of coinAll power ups.
	std::vector<EPU_CoinAll*> coinAllPickups;
	///The vector array of shield.
	std::vector<EPU_Shield*> shieldPickups;

	//Arrows

	///The vector array of Player Arrows.
	std::vector<EA_PlayerArrow*> playerArrows;
	///The vector array of Flaming Arrows.
	std::vector<EA_FlamingArrow*> flamingArrows;
	///The vector array of Archer Arrows.
	std::vector<EA_ArcherArrow*> archerArrows;

	//Particle Effects

	///An unordered map of min tint colours for use with the particle effects.
	std::unordered_map<std::string, SDL_Colour> minColourTints;
	///An unordered map of max tint colours for use with the particle effects.
	std::unordered_map<std::string, SDL_Colour> maxColourTints;
	///The vector array of particle effects for use with entity death.
	std::vector<PS_ParticleEffect*> deathEffects;

	//Audio

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
	@param deadEntityDimensions The dimensions of the Entity.
	@param coinSpawn A boolean for if the entity should spawn coins.
	@param maxCoins The max number of coins to spawn.
	@param entityType The name of the type of entity that is killed.
	*/
	void createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, C_Vec2 deadEntityDimensions,
		bool coinSpawn, int maxCoins, std::string entityType);
	
	/**
	@brief A function that deletes all of the entities flagged as dead.
	*/
	void removeCompletedEffects();

	/**
	@brief A function that handles all of the collision detection between the player and the entities.
	*/
	void entityCollisionDetection();

	/**
	@brief A function to spawn a new wave of Entities.
	*/
	void spawnEntityWave();

	/**
	@brief A function to pick a new Entity type.
	@returns The type of the new Entity to spawn.
	*/
	int pickEntity();

	/**
	@brief A function to spawn a new Entity.
	@param spawnY The generated y position for the Entity to spawn at.
	@param entityToSpawn The type of the new Entity to spawn.
	*/
	void spawnEntity(float spawnY, int entityToSpawn);
};