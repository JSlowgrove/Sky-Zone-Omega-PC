#include "G_Gameplay.h"

G_Gameplay::G_Gameplay(EP_Player* player, E_EntityManager* entityManager) : player(player), entityManager(entityManager)
{
}

G_Gameplay::~G_Gameplay()
{
}

void G_Gameplay::update(float dt)
{
	//Collision Detection
	entityCollisionDetection();
}

void G_Gameplay::entityCollisionDetection()
{
	//Collision for the StyphBirds
	for (auto styphBird : entityManager->getStyphBirds())
	{
		//Collision between the player and StyphBirds
		if (player->entityCollisionTest(styphBird->getPosition(), styphBird->getDimensions()))
		{
			styphBird->setDeathParticles(true);
			styphBird->setDeadStatus(true);
			player->decreaseHealth();
			entityManager->playHealthLostSound();
		}

		//Collision between the arrows and StyphBirds
		for (auto arrow : entityManager->getPlayerArrows())
		{
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
		for (auto arrow : entityManager->getFlamingArrows())
		{
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
	}

	//Collision between the arrows and archers
	for (auto archer : entityManager->getArchers())
	{
		//Collision between the arrows and archers
		for (auto arrow : entityManager->getPlayerArrows())
		{
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
		for (auto arrow : entityManager->getFlamingArrows())
		{
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
	}

	//Collision between the player and storm clouds
	for (auto stormCloud : entityManager->getStormClouds())
	{
		if (player->entityCollisionTest(stormCloud->getPosition(), stormCloud->getDimensions()))
		{
			stormCloud->setDeathParticles(true);
			stormCloud->setDeadStatus(true);
			player->decreaseHealth();
			entityManager->playHealthLostSound();
		}
	}

	//Collision between the player and the coins
	for (auto coin : entityManager->getCoins())
	{
		if (player->entityCollisionTest(coin->getPosition(), coin->getDimensions()))
		{
			coin->setDeadStatus(true);
			player->increaseCoins();
			entityManager->playCoinCollectSound();
		}
	}

	//Collision between the player and the health
	for (auto healthPickup : entityManager->getHealthPickups())
	{
		if (player->entityCollisionTest(healthPickup->getPosition(), healthPickup->getDimensions()))
		{
			healthPickup->setDeadStatus(true);
			player->increaseHealth();
			entityManager->playHealthLostSound();
		}
	}

	//Collision between the player and the fire power ups
	for (auto firePowerUp : entityManager->getFlamingPickups())
	{
		if (player->entityCollisionTest(firePowerUp->getPosition(), firePowerUp->getDimensions()))
		{
			firePowerUp->setDeadStatus(true);
			player->setFlaming(true);
		}
	}

	//Collision between the player and the kill all power ups
	for (auto killAllPowerUp : entityManager->getKillAllPickups())
	{
		if (player->entityCollisionTest(killAllPowerUp->getPosition(), killAllPowerUp->getDimensions()))
		{
			killAllPowerUp->setDeadStatus(true);
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

	//Collision between the player and the coin all power ups
	for (auto coinAllPowerUp : entityManager->getCoinAllPickups())
	{
		if (player->entityCollisionTest(coinAllPowerUp->getPosition(), coinAllPowerUp->getDimensions()))
		{
			coinAllPowerUp->setDeadStatus(true);
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

	//Collision between the player and the shields
	for (auto shield : entityManager->getShieldPickups())
	{
		if (player->entityCollisionTest(shield->getPosition(), shield->getDimensions()))
		{
			shield->setDeadStatus(true);
			//TODO
		}
	}

	//Collision between the player and the archer arrows
	for (auto arrow : entityManager->getArcherArrows())
	{
		if (player->entityCollisionTest(arrow->getPosition(), arrow->getDimensions()))
		{
			player->decreaseHealth();
			entityManager->playHealthLostSound();
			arrow->setDeadStatus(true);
			arrow->setDeathParticles(true);
		}
	}
}

void G_Gameplay::playerStormCloudCollisionDetection(EB_Entity* stormCloud)
{
	//Collision between the player and storm clouds
	for (auto stormCloud : entityManager->getStormClouds())
	{
		if (player->entityCollisionTest(stormCloud->getPosition(), stormCloud->getDimensions()))
		{
			stormCloud->setDeathParticles(true);
			stormCloud->setDeadStatus(true);
			player->decreaseHealth();
			entityManager->playHealthLostSound();
		}
	}
}