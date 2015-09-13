#pragma once

#include "../Enitites/E_EntityManager.h"
#include "../Core/C_Timer.h"

/**
@brief A class that manages the spawning of the entities in the game.
@author Jamie Slowgrove
*/
class G_SpawnManager
{
public:
	/**
	@brief Constructs the SpawnManager.
	@param screenDimensions The screen dimensions.
	@param player A pointer to the Player.
	@param entityManager A pointer to the EntityManager.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	G_SpawnManager(C_Vec2 screenDimensions, EP_Player* player, E_EntityManager* entityManager, float* universalSpeed);

	/**
	@brief Destructs the SpawnManager.
	*/
	~G_SpawnManager();

	/**
	@brief A function to update the SpawnManager.
	@param dt The delta time.
	*/
	void update(float dt);

private:
	///The screen dimensions
	C_Vec2 screenDimensions;
	///A pointer to the Player.
	EP_Player* player;
	///A pointer to the EntityManager.
	E_EntityManager* entityManager;
	///A timer for the entity spawner.
	C_Timer spawnTimer;
	///A pointer for the universal speed of the game.
	float* universalSpeed;

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
	@brief A function to get the ID of the entity type.
	@param entityType The type of the new Entity to spawn.
	@param The ID of the entity type.
	*/
	std::string getEntityID(int entityType);

	/**
	@brief A function to spawn a new Entity.
	@param spawnY The generated y position for the Entity to spawn at.
	@param entityToSpawn The type of the new Entity to spawn.
	*/
	void spawnEntity(float spawnY, int entityToSpawn);
};