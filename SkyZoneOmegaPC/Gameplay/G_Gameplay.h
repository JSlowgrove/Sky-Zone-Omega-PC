#pragma once

#include <vector>
#include "../Enitites/E_EntityManager.h"
#include "../Enitites/Player/EP_Player.h"
#include "G_CollisionManager.h"

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

private:
	///A pointer to the Player.
	EP_Player* player;
	///A pointer to the EntityManager.
	E_EntityManager* entityManager;
	///A pointer to the CollisionManager.
	G_CollisionManager* collisionManager;
};