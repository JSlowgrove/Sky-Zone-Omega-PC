#pragma once

#include <vector>
#include "../Enitites/E_EntityManager.h"
#include "../Enitites/Player/EP_Player.h"
#include "../Enitites/Base/EB_Entity.h"

/**
@brief Contains the data and functions for the Gameplay.
@author Jamie Slowgrove
*/
class G_Gameplay
{
public:
	/**
	@brief Constructs the Gameplay object.
	@param player A pointer to the Player.
	@param entityManager A pointer to the EntityManager.
	*/
	G_Gameplay(EP_Player* player, E_EntityManager* entityManager);

	/**
	@brief Destructs the Gameplay object.
	*/
	~G_Gameplay();

	/**
	@brief A function to update the Gameplay.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function that handles all of the collision detection between the player and the entities.
	*/
	void entityCollisionDetection();

private:
	///A pointer to the Player.
	EP_Player* player;
	///A pointer to the EntityManager.
	E_EntityManager* entityManager;

	/**
	@brief A function that handles all of the collision detection between the Player and the StormClouds.
	@param stormCloud A pointer to the StormCloud.
	*/
	void playerStormCloudCollisionDetection(EB_Entity* stormCloud);
};