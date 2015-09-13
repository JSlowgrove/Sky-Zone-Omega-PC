#pragma once

#include <vector>
#include "../Enitites/E_EntityManager.h"
#include "../Enitites/Player/EP_Player.h"
#include "G_CollisionManager.h"
#include "G_SpawnManager.h"

/**
@brief Contains the data and functions for the Gameplay.
@author Jamie Slowgrove
*/
class G_Gameplay
{
public:
	/**
	@brief Constructs the Gameplay object.
	@param screenDimensions The screen dimensions.
	@param player A pointer to the Player.
	@param entityManager A pointer to the EntityManager.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	G_Gameplay(C_Vec2 screenDimensions, EP_Player* player, E_EntityManager* entityManager, float* universalSpeed);

	/**
	@brief Destructs the Gameplay object.
	*/
	~G_Gameplay();

	/**
	@brief A function to update the Gameplay.
	@param dt The delta time.
	*/
	void update(float dt);

private:
	///The screen dimensions.
	C_Vec2 screenDimensions;
	///A pointer to the Player.
	EP_Player* player;
	///A pointer to the EntityManager.
	E_EntityManager* entityManager;
	///A pointer to the CollisionManager.
	G_CollisionManager* collisionManager;
	///A pointer to the SpawnManager
	G_SpawnManager* spawnManager;
	///A pointer for the universal speed of the game.
	float* universalSpeed;
};