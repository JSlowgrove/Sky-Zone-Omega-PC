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
	@brief Gets the pointer to the wanted texture.
	@param iD The ID of the texture to return.
	@returns The pointer to the wanted texture.
	*/
	C_Texture* getTexture(std::string iD);

	/**
	@brief Gets the dimensions of the wanted entity.
	@param iD The ID of the dimensions to return.
	@returns The dimensions of the wanted entity.
	*/
	C_Vec2 getEntityDimensions(std::string iD);

	/**
	@brief Gets the vector array of StyphBird pointers.
	@returns The vector array of StyphBird pointers
	*/
	std::vector<EE_StyphBird*> getStyphBirds();

	/**
	@brief Gets the vector array of StormCloud pointers.
	@returns The vector array of StormCloud pointers
	*/
	std::vector<EE_StormCloud*> getStormClouds();

	/**
	@brief Gets the vector array of Archer pointers.
	@returns The vector array of Archer pointers
	*/
	std::vector<EE_Archer*> getArchers();

	/**
	@brief Gets the vector array of Coin pointers.
	@returns The vector array of Coin pointers
	*/
	std::vector<EPU_Coin*> getCoins();

	/**
	@brief Gets the vector array of Health pointers.
	@returns The vector array of Health pointers
	*/
	std::vector<EPU_Health*> getHealthPickups();

	/**
	@brief Gets the vector array of Flaming pointers.
	@returns The vector array of Flaming pointers
	*/
	std::vector<EPU_Flaming*> getFlamingPickups();

	/**
	@brief Gets the vector array of KillAll pointers.
	@returns The vector array of KillAll pointers
	*/
	std::vector<EPU_KillAll*> getKillAllPickups();

	/**
	@brief Gets the vector array of CoinAll pointers.
	@returns The vector array of CoinAll pointers
	*/
	std::vector<EPU_CoinAll*> getCoinAllPickups();

	/**
	@brief Gets the vector array of Shield pointers.
	@returns The vector array of Shield pointers
	*/
	std::vector<EPU_Shield*> getShieldPickups();

	/**
	@brief Gets the vector array of PlayerArrow pointers.
	@returns The vector array of PlayerArrow pointers
	*/
	std::vector<EA_PlayerArrow*> getPlayerArrows();

	/**
	@brief Gets the vector array of FlamingArrow pointers.
	@returns The vector array of FlamingArrow pointers
	*/
	std::vector<EA_FlamingArrow*> getFlamingArrows();

	/**
	@brief Gets the vector array of ArcherArrow pointers.
	@returns The vector array of ArcherArrow pointers
	*/
	std::vector<EA_ArcherArrow*> getArcherArrows();

	/**
	@brief Plays the coin collect sound.
	*/
	void playCoinCollectSound();

	/**
	@brief Spawn a new StyphBird.
	@param spawnPos The position to spawn at.
	*/
	void spawnStyphBird(C_Vec2 spawnPos);

	/**
	@brief Spawn a new StormCloud.
	@param spawnPos The position to spawn at.
	*/
	void spawnStormCloud(C_Vec2 spawnPos);

	/**
	@brief Spawn a new Archer.
	@param spawnPos The position to spawn at.
	*/
	void spawnArcher(C_Vec2 spawnPos);

	/**
	@brief Spawn a new Coin.
	@param spawnPos The position to spawn at.
	*/
	void spawnCoin(C_Vec2 spawnPos);

	/**
	@brief Spawn a new Health pickup.
	@param spawnPos The position to spawn at.
	*/
	void spawnHealth(C_Vec2 spawnPos);

	/**
	@brief Spawn a new Flaming pickup.
	@param spawnPos The position to spawn at.
	*/
	void spawnFlaming(C_Vec2 spawnPos);

	/**
	@brief Spawn a new CoinAll pickup.
	@param spawnPos The position to spawn at.
	*/
	void spawnCoinAll(C_Vec2 spawnPos);

	/**
	@brief Spawn a new KillAll pickup.
	@param spawnPos The position to spawn at.
	*/
	void spawnKillAll(C_Vec2 spawnPos);

	/**
	@brief Spawn a new Shield pickup.
	@param spawnPos The position to spawn at.
	*/
	void spawnShield(C_Vec2 spawnPos);

private:
	///The screen dimensions
	C_Vec2 screenDimensions;
	///A pointer to the renderer.
	SDL_Renderer* renderer;
	///A pointer to the Player.
	EP_Player* player;
	///An unordered map of the sprite textures.
	std::unordered_map<std::string, C_Texture*> textures;
	///An unordered map of the entity dimensions.
	std::unordered_map<std::string, C_Vec2> entityDimensions;

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
};