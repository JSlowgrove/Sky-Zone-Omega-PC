#include "G_CollisionManager.h"

G_CollisionManager::G_CollisionManager(EP_Player* player, E_EntityManager* entityManager) : player(player), entityManager(entityManager)
{
}

G_CollisionManager::~G_CollisionManager()
{
}

void G_CollisionManager::entityCollisionDetection()
{
	//Collision for the StyphBirds
	for (auto styphBird : entityManager->getStyphBirds())
	{
		//Collision between the player and StyphBirds
		playerStyphBirdCollisionDetection(styphBird);

		//Collision between the arrows and StyphBirds
		for (auto arrow : entityManager->getPlayerArrows())
		{
			arrowStyphBirdCollisionDetection(arrow, styphBird);
		}
		for (auto arrow : entityManager->getFlamingArrows())
		{
			arrowStyphBirdCollisionDetection(arrow, styphBird);
		}
	}

	//Collision for the storm clouds
	for (auto stormCloud : entityManager->getStormClouds())
	{
		playerStormCloudCollisionDetection(stormCloud);
	}

	//Collision between the player and the archer arrows
	for (auto arrow : entityManager->getArcherArrows())
	{
		playerArrowCollisionDetection(arrow);
	}

	//Collision between the arrows and archers
	for (auto archer : entityManager->getArchers())
	{
		//Collision between the arrows and archers
		for (auto arrow : entityManager->getPlayerArrows())
		{
			arrowArcherCollisionDetection(arrow, archer);
		}
		for (auto arrow : entityManager->getFlamingArrows())
		{
			arrowArcherCollisionDetection(arrow, archer);
		}
	}

	//Collision between the player and the coins
	for (auto coin : entityManager->getCoins())
	{
		playerCoinCollisionDetection(coin);
	}

	//Collision between the player and the health
	for (auto health : entityManager->getHealthPickups())
	{
		playerHealthCollisionDetection(health);
	}

	//Collision between the player and the flaming pick ups
	for (auto flaming : entityManager->getFlamingPickups())
	{
		playerFlamingCollisionDetection(flaming);
	}

	//Collision between the player and the kill all pick ups
	for (auto killAll : entityManager->getKillAllPickups())
	{
		playerKillAllCollisionDetection(killAll);
	}

	//Collision for the player and the coin all pick ups
	for (auto coinAll : entityManager->getCoinAllPickups())
	{
		playerCoinAllCollisionDetection(coinAll);
	}

	//Collision for the player and the shields
	for (auto shield : entityManager->getShieldPickups())
	{
		playerShieldCollisionDetection(shield);
	}
}

void G_CollisionManager::playerStyphBirdCollisionDetection(EE_StyphBird* styphBird)
{
	//Collision between the player and StyphBird
	if (player->entityCollisionTest(styphBird->getPosition(), styphBird->getDimensions()))
	{
		styphBird->setDeathParticles(true);
		styphBird->setDeadStatus(true);
		player->decreaseHealth();
		entityManager->playHealthLostSound();
	}
}

void G_CollisionManager::playerStormCloudCollisionDetection(EE_StormCloud* stormCloud)
{
	//Collision between the player and storm cloud
	if (player->entityCollisionTest(stormCloud->getPosition(), stormCloud->getDimensions()))
	{
		stormCloud->setDeathParticles(true);
		stormCloud->setDeadStatus(true);
		player->decreaseHealth();
		entityManager->playHealthLostSound();
	}
}

void G_CollisionManager::playerArrowCollisionDetection(EA_Arrow* arrow)
{
	//Collision between the player and the archer arrow
	if (player->entityCollisionTest(arrow->getPosition(), arrow->getDimensions()))
	{
		player->decreaseHealth();
		entityManager->playHealthLostSound();
		arrow->setDeadStatus(true);
		arrow->setDeathParticles(true);
	}
}

void G_CollisionManager::playerCoinCollisionDetection(EPU_Coin* coin)
{
	//Collision between the player and the coin
	if (player->entityCollisionTest(coin->getPosition(), coin->getDimensions()))
	{
		coin->setDeadStatus(true);
		player->increaseCoins();
		entityManager->playCoinCollectSound();
	}
}

void G_CollisionManager::playerHealthCollisionDetection(EPU_Health* health)
{
	//Collision between the player and the health
	if (player->entityCollisionTest(health->getPosition(), health->getDimensions()))
	{
		health->setDeadStatus(true);
		player->increaseHealth();
		entityManager->playHealthLostSound();
	}
}

void G_CollisionManager::playerFlamingCollisionDetection(EPU_Flaming* flaming)
{
	//Collision between the player and the flaming pickup
	if (player->entityCollisionTest(flaming->getPosition(), flaming->getDimensions()))
	{
		flaming->setDeadStatus(true);
		player->setFlaming(true);
	}
}

void G_CollisionManager::playerCoinAllCollisionDetection(EPU_CoinAll* coinAll)
{
	//Collision between the player and the coin all pick up
	if (player->entityCollisionTest(coinAll->getPosition(), coinAll->getDimensions()))
	{
		coinAll->setDeadStatus(true);
		for (auto styphBird : entityManager->getStyphBirds())
		{
			styphBird->setDeathParticles(true);
			styphBird->setCoinSpawn(true);
			styphBird->setDeadStatus(true);
		}
		for (auto archer : entityManager->getArchers())
		{
			archer->setDeathParticles(true);
			archer->setCoinSpawn(true);
			archer->setDeadStatus(true);
		}
		for (auto stormCloud : entityManager->getStormClouds())
		{
			stormCloud->setDeathParticles(true);
			stormCloud->setDeadStatus(true);
		}
	}
}

void G_CollisionManager::playerKillAllCollisionDetection(EPU_KillAll* killAll)
{
	//Collision between the player and the kill all pickup
	if (player->entityCollisionTest(killAll->getPosition(), killAll->getDimensions()))
	{
		killAll->setDeadStatus(true);
		for (auto styphBird : entityManager->getStyphBirds())
		{
			styphBird->setDeathParticles(true);
			styphBird->setDeadStatus(true);
		}
		for (auto archer : entityManager->getArchers())
		{
			archer->setDeathParticles(true);
			archer->setDeadStatus(true);
		}
		for (auto stormCloud : entityManager->getStormClouds())
		{
			stormCloud->setDeathParticles(true);
			stormCloud->setDeadStatus(true);
		}
	}
}

void G_CollisionManager::playerShieldCollisionDetection(EPU_Shield* shield)
{
	//Collision between the player and the shield
	if (player->entityCollisionTest(shield->getPosition(), shield->getDimensions()))
	{
		shield->setDeadStatus(true);
		player->activateShield();
	}
}

void G_CollisionManager::arrowStyphBirdCollisionDetection(EA_Arrow* arrow, EE_StyphBird* styphBird)
{
	//Collision between the arrow and styphBird
	if (C_Utilities::rectRectIntersect(styphBird->getPosition(), styphBird->getDimensions(),
		arrow->getPosition(), arrow->getDimensions()))
	{
		styphBird->setDeathParticles(true);
		styphBird->setDeadStatus(true);
		styphBird->setCoinSpawn(true);
		arrow->setDeadStatus(true);
		arrow->setDeathParticles(true);
	}
}

void G_CollisionManager::arrowArcherCollisionDetection(EA_Arrow* arrow, EE_Archer* archer)
{
	//Collision between the arrow and archer
	if (C_Utilities::rectRectIntersect(archer->getPosition(), archer->getDimensions(),
		arrow->getPosition(), arrow->getDimensions()))
	{
		archer->decreaseHealth(arrow->getDamage());
		arrow->setDeadStatus(true);
		arrow->setDeathParticles(true);

		//If the arrow killed the archer
		if (archer->getDeadStatus())
		{
			archer->setDeathParticles(true);
			archer->setCoinSpawn(true);
		}
	}
}