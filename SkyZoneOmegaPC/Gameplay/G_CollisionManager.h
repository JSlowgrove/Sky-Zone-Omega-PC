#pragma once

#include <vector>
#include "../Enitites/E_EntityManager.h"
#include "../Enitites/Player/EP_Player.h"

/**
@brief Contains the data and functions for the CollisionManager.
@author Jamie Slowgrove
*/
class G_CollisionManager
{
public:
	/**
	@brief Constructs the CollisionManager.
	@param player A pointer to the Player.
	@param entityManager A pointer to the EntityManager.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	G_CollisionManager(EP_Player* player, E_EntityManager* entityManager, float* universalSpeed);

	/**
	@brief Destructs the G_CollisionManager.
	*/
	~G_CollisionManager();

	/**
	@brief A function that handles all of the collision detection between the player and the entities.
	*/
	void entityCollisionDetection();

private:
	///A pointer to the Player.
	EP_Player* player;
	///A pointer to the EntityManager.
	E_EntityManager* entityManager;
	///A pointer for the universal speed of the game.
	float* universalSpeed;

	/**
	@brief A function that handles all of the collision detection between the Player and a StymphBird.
	@param styphBird A pointer to the StyphBird.
	*/
	void playerStyphBirdCollisionDetection(EE_StyphBird* styphBird);

	/**
	@brief A function that handles all of the collision detection between the Player and a StormCloud.
	@param stormCloud A pointer to the StormCloud.
	*/
	void playerStormCloudCollisionDetection(EE_StormCloud* stormCloud);

	/**
	@brief A function that handles all of the collision detection between the Player and an Arrow.
	@param arrow A pointer to the Arrow.
	*/
	void playerArrowCollisionDetection(EA_Arrow* arrow);

	/**
	@brief A function that handles all of the collision detection between the Player and a Coin.
	@param coin A pointer to the Coin.
	*/
	void playerCoinCollisionDetection(EPU_Coin* coin);

	/**
	@brief A function that handles all of the collision detection between the Player and a Health pickup.
	@param helath A pointer to the Health.
	*/
	void playerHealthCollisionDetection(EPU_Health* health);

	/**
	@brief A function that handles all of the collision detection between the Player and a Flaming pickup.
	@param flaming A pointer to the Flaming.
	*/
	void playerFlamingCollisionDetection(EPU_Flaming* flaming);

	/**
	@brief A function that handles all of the collision detection between the Player and a CoinAll pickup.
	@param coinAll A pointer to the CoinAll.
	*/
	void playerCoinAllCollisionDetection(EPU_CoinAll* coinAll);

	/**
	@brief A function that handles all of the collision detection between the Player and a KillAll pickup.
	@param killAll A pointer to the KillAll.
	*/
	void playerKillAllCollisionDetection(EPU_KillAll* killAll);

	/**
	@brief A function that handles all of the collision detection between the Player and a Shield pickup.
	@param shield A pointer to the Shield.
	*/
	void playerShieldCollisionDetection(EPU_Shield* shield);

	/**
	@brief A function that handles all of the collision detection between the Player and a TimeSlow pickup.
	@param shield A pointer to the TimeSlow.
	*/
	void playerTimeSlowCollisionDetection(EPU_TimeSlow* timeSlow);

	/**
	@brief A function that handles all of the collision detection between an Arrow and a StyphBird.
	@param arrow A pointer to the Arrow.
	@param styphBird A pointer to the StyphBird.
	*/
	void arrowStyphBirdCollisionDetection(EA_Arrow* arrow, EE_StyphBird* styphBird);

	/**
	@brief A function that handles all of the collision detection between an Arrow and an Archer.
	@param arrow A pointer to the Arrow.
	@param archer A pointer to the Archer.
	*/
	void arrowArcherCollisionDetection(EA_Arrow* arrow, EE_Archer* archer);
};