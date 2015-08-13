#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, E_Player* player, SDL_Renderer* renderer) : 
dimensions(dimensions), player(player), renderer(renderer)
{	
	//Initialise entity textures
	styphBirdSprite = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	stormCloudSprite = new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer);
	coinSprite = new C_Texture("Assets/Images/coin.png", renderer);
	healthSprite = new C_Texture("Assets/Images/health300x299.png", renderer);
	firePowerUpSprite = new C_Texture("Assets/Images/coin.png", renderer); //tmp
	firePowerUpSprite->setColourTint(255, 0, 0);//tmp
	playerArrowSprite = new C_Texture("Assets/Images/playerArrow.png", renderer);
	archerArrowSprite = new C_Texture("Assets/Images/archerArrow.png", renderer);
	archerSprite = new C_Texture("Assets/Images/archer.png", renderer);

	//Initialise the particle effect textures
	particleEffectTexture = new C_Texture("Assets/Images/particle.png", renderer);
	fireSprite = new C_Texture("Assets/Images/fireParticle.png", renderer);

	//Initialise the min and max tint colours for the particle effects
	minColourTints["styphBird"] = { (Uint8)155, (Uint8)100, (Uint8)0 };
	maxColourTints["styphBird"] = { (Uint8)255, (Uint8)200, (Uint8)20 };
	minColourTints["stormCloud"] = { (Uint8)0, (Uint8)0, (Uint8)0 };
	maxColourTints["stormCloud"] = { (Uint8)45, (Uint8)45, (Uint8)45 };
	minColourTints["archer"] = { (Uint8)0, (Uint8)0, (Uint8)0 };
	maxColourTints["archer"] = { (Uint8)155, (Uint8)0, (Uint8)0 };
	minColourTints["archerArrow"] = { (Uint8)55, (Uint8)0, (Uint8)0 };
	maxColourTints["archerArrow"] = { (Uint8)255, (Uint8)0, (Uint8)0 };
	minColourTints["playerArrow"] = { (Uint8)0, (Uint8)0, (Uint8)155 };
	maxColourTints["playerArrow"] = { (Uint8)0, (Uint8)155, (Uint8)255 };
	minColourTints["fire"] = { (Uint8)255, (Uint8)0, (Uint8)0 };
	maxColourTints["fire"] = { (Uint8)255, (Uint8)255, (Uint8)0 };

	//Initialise player fire effect
	player->initialiseFire(fireSprite, minColourTints["fire"], maxColourTints["fire"]);

	//Initialise the entity dimensions
	styphBirdDimensions = dimensions * 0.06f;
	stormCloudsDimensions = C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f);
	coinDimensions = healthDimensions =  firePowerUpDimensions = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	arrowDimensions = C_Vec2(dimensions.y * 0.08f, dimensions.y * 0.02f);
	archerDimensions = C_Vec2(dimensions.y * 0.1f, dimensions.y * 0.15f);

	//Initialise sounds
	healthLossSounds[0] = new C_Audio("Assets/Audio/deathSound.ogg");
	healthLossSounds[1] = new C_Audio("Assets/Audio/hitSound2.ogg");
	healthLossSounds[2] = new C_Audio("Assets/Audio/hitSound.ogg");
	coinCollectSound = new C_Audio("Assets/Audio/powerUp2.ogg");
	healthCollectSound = new C_Audio("Assets/Audio/healthUp.ogg");
}

E_EntityManager::~E_EntityManager()
{
	//Delete particle effects
	for (auto deathEffect : deathEffects)
	{
		delete deathEffect;
	}
	delete particleEffectTexture;

	//Delete StyphBirds
	for (auto styphBird : styphBirds)
	{
		delete styphBird;
	}
	delete styphBirdSprite;

	//Delete storm clouds
	for (auto stormCloud : stormClouds)
	{
		delete stormCloud;
	}
	delete stormCloudSprite;

	//Delete coins
	for (auto coin : coins)
	{
		delete coin;
	}
	delete coinSprite;

	//Delete health
	for (auto healthPickup : health)
	{
		delete healthPickup;
	}
	delete healthSprite;

	//Delete fire power ups
	for (auto firePowerUp : firePowerUps)
	{
		delete firePowerUp;
	}
	delete firePowerUpSprite;

	//Delete arrows
	for (auto arrow : playerArrows)
	{
		delete arrow;
	}
	for (auto arrow : archerArrows)
	{
		delete arrow;
	}
	for (auto arrow : flamingArrows)
	{
		delete arrow;
	}
	delete playerArrowSprite;
	delete archerArrowSprite;
	delete fireSprite;

	//Delete archers
	for (auto archer : archers)
	{
		delete archer;
	}
	delete archerSprite;

	//Delete audio
	for (auto healthLossSound : healthLossSounds)
	{
		delete healthLossSound;
	}
	delete coinCollectSound;
	delete healthCollectSound;
}

//TMP
void E_EntityManager::input(SDL_Event& incomingEvent)
{
	switch (incomingEvent.type)
	{
	case SDL_KEYDOWN:
		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_b:
			styphBirds.push_back(new E_StyphBird(styphBirdSprite,
				C_Vec2(dimensions.x + styphBirdDimensions.x, player->getPosition().y),
				styphBirdDimensions));
			break;
		case SDLK_s:
			stormClouds.push_back(new E_StormCloud(stormCloudSprite,
				C_Vec2(dimensions.x + stormCloudsDimensions.x, player->getPosition().y),
				stormCloudsDimensions));
			break;
		case SDLK_c:
			coins.push_back(new E_Coin(coinSprite,
				C_Vec2(dimensions.x + coinDimensions.x, player->getPosition().y),
				coinDimensions, dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_f:
			firePowerUps.push_back(new E_FirePowerUp(firePowerUpSprite,
				C_Vec2(dimensions.x + firePowerUpDimensions.x, player->getPosition().y),
				firePowerUpDimensions, dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_h:
			health.push_back(new E_Health(healthSprite,
				C_Vec2(dimensions.x + arrowDimensions.x, player->getPosition().y),
				healthDimensions, dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_a:
			archers.push_back(new E_Archer(archerSprite,
				C_Vec2(dimensions.x + archerDimensions.x, player->getPosition().y),
				archerDimensions));
			break;
		case SDLK_k:
			for (auto styphBird : styphBirds)
			{
				styphBird->setDeathParticles(true);
				styphBird->setCoinSpawn(true);
				styphBird->setDeadStatus(true);
			}
			for (auto archer : archers)
			{
				archer->setDeathParticles(true);
				archer->setCoinSpawn(true);
				archer->setDeadStatus(true);
			}
			for (auto stormCloud : stormClouds)
			{
				stormCloud->setDeathParticles(true);
				stormCloud->setDeadStatus(true);
			}
			break;
		case SDLK_d:
			for (auto styphBird : styphBirds)
			{
				styphBird->setDeathParticles(true);
				styphBird->setDeadStatus(true);
			}
			for (auto archer : archers)
			{
				archer->setDeathParticles(true);
				archer->setDeadStatus(true);
			}
			for (auto stormCloud : stormClouds)
			{
				stormCloud->setDeathParticles(true);
				stormCloud->setDeadStatus(true);
			}
			break;
		}
		break;
	}
}

void E_EntityManager::update(float dt)
{
	//check if the player should fire an flaming arrow
	if (player->getFireArrow() && player->getFlaming())
	{
		flamingArrows.push_back(new E_FlamingArrow(playerArrowSprite, fireSprite,
			C_Vec2(player->getPosition().x + player->getDimensions().x, player->getPosition().y),
			arrowDimensions, dimensions, minColourTints["fire"], maxColourTints["fire"]));
		player->setFireArrow(false);
	}

	//check if the player should fire a normal arrow
	if (player->getFireArrow() && !player->getFlaming())
	{
		playerArrows.push_back(new E_PlayerArrow(playerArrowSprite,
			C_Vec2(player->getPosition().x + dimensions.x * 0.08f, player->getPosition().y),
			arrowDimensions, dimensions));
		player->setFireArrow(false);
	}
	
	//Update particle effects
	for (auto deathEffect : deathEffects)
	{
		deathEffect->update(dt);
	}

	//Update StyphBirds
	for (auto styphBird : styphBirds)
	{
		styphBird->update(dt);
	}

	//Update Storm Clouds
	for (auto stormCloud : stormClouds)
	{
		stormCloud->update(dt);
	}

	//Update Archers
	for (auto archer : archers)
	{
		archer->update(dt);
		//If the archer should fire an arrow
		if (archer->getFireArrow())
		{
			//Fire an arrow
			archerArrows.push_back(new E_ArcherArrow(archerArrowSprite, archer->getPosition(), arrowDimensions));
			archer->setFireArrow(false);
		}
	}

	//Update health
	for (auto healthPickup : health)
	{
		healthPickup->update(dt);
	}

	//Update Coins
	for (auto coin : coins)
	{
		coin->update(dt);
	}

	//Update fire power ups
	for (auto firePowerUp : firePowerUps)
	{
		firePowerUp->update(dt);
	}

	//Update Arrows
	for (auto arrow : playerArrows)
	{
		arrow->update(dt);
	}
	for (auto arrow : archerArrows)
	{
		arrow->update(dt);
	}
	for (auto arrow : flamingArrows)
	{
		arrow->update(dt);
	}

	//Collision detection for the entities
	entityCollisionDetection();

	//remove entities flagged as dead.
	removeDeadEntites();

	//remove completed particle effects
	removeCompletedEffects();
}

void E_EntityManager::draw()
{
	//Draw the Coins
	for (auto coin : coins)
	{
		coin->draw(renderer);
	}

	//Draw the health
	for (auto healthPickup : health)
	{
		healthPickup->draw(renderer);
	}

	//Draw the fire power ups
	for (auto firePowerUp : firePowerUps)
	{
		firePowerUp->draw(renderer);
	}

	//Draw the arrows
	for (auto arrow : playerArrows)
	{
 		arrow->draw(renderer);
	}
	for (auto arrow : archerArrows)
	{
		arrow->draw(renderer);
	}
	for (auto arrow : flamingArrows)
	{
		arrow->draw(renderer);
	}

	//Draw the Storm Clouds
	for (auto stormCloud : stormClouds)
	{
		stormCloud->draw(renderer);
	}

	//Draw the StyphBirds
	for (auto styphBird : styphBirds)
	{
		styphBird->draw(renderer);
	}

	//Draw the Archers
	for (auto archer : archers)
	{
		archer->draw(renderer);
	}

	//Draw the particle effects
	for (auto deathEffect : deathEffects)
	{
		deathEffect->draw(renderer);
	}
}

C_Texture* E_EntityManager::getCoinTexture()
{
	return coinSprite;
}

C_Texture* E_EntityManager::getHealthTexture()
{
	return healthSprite;
}

void E_EntityManager::removeDeadEntites()
{
	//Remove dead StyphBirds
	for (unsigned int i = 0; i < styphBirds.size(); i++)
	{
		if (styphBirds[i]->getDeadStatus())
		{
			//Check if the bird will have death particles
			if (styphBirds[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(styphBirds[i]->getPosition(), styphBirds[i]->getVelocities(),
					styphBirds[i]->getDimensions(), styphBirds[i]->getCoinSpawn(), 5, "styphBird");
			}
			//delete pointer
			delete styphBirds[i];
			//erase from array
			styphBirds.erase(styphBirds.begin() + i);
		}
	}

	//Remove dead Storm Clouds
	for (unsigned int i = 0; i < stormClouds.size(); i++)
	{
		if (stormClouds[i]->getDeadStatus())
		{
			//Check if the cloud will have death particles
			if (stormClouds[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(stormClouds[i]->getPosition(), stormClouds[i]->getVelocities(), 
					stormClouds[i]->getDimensions(), false, 0, "stormCloud");
			}
			//delete pointer
			delete stormClouds[i];
			//erase from array
			stormClouds.erase(stormClouds.begin() + i);
		}
	}

	//Remove dead Archers
	for (unsigned int i = 0; i < archers.size(); i++)
	{
		if (archers[i]->getDeadStatus())
		{
			//Check if the cloud will have death particles
			if (archers[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(archers[i]->getPosition(), archers[i]->getVelocities(),
					archers[i]->getDimensions(), archers[i]->getCoinSpawn(), 10, "archer");
			}
			//delete pointer
			delete archers[i];
			//erase from array
			archers.erase(archers.begin() + i);
		}
	}

	//Remove dead Coins
	for (unsigned int i = 0; i < coins.size(); i++)
	{
		if (coins[i]->getDeadStatus())
		{
			//delete pointer
			delete coins[i];
			//erase from array
			coins.erase(coins.begin() + i);
		}
	}

	//Remove dead Health
	for (unsigned int i = 0; i < health.size(); i++)
	{
		if (health[i]->getDeadStatus())
		{
			//delete pointer
			delete health[i];
			//erase from array
			health.erase(health.begin() + i);
		}
	}

	//Remove dead fire power ups
	for (unsigned int i = 0; i < firePowerUps.size(); i++)
	{
		if (firePowerUps[i]->getDeadStatus())
		{
			//delete pointer
			delete firePowerUps[i];
			//erase from array
			firePowerUps.erase(firePowerUps.begin() + i);
		}
	}

	//Remove dead Arrows
	for (unsigned int i = 0; i < playerArrows.size(); i++)
	{
		if (playerArrows[i]->getDeadStatus())
		{
			//Check if the arrow will have death particles
			if (playerArrows[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(playerArrows[i]->getPosition(), playerArrows[i]->getVelocities(),
					playerArrows[i]->getDimensions(), false, 0, "playerArrow");
			}
			//delete pointer
			delete playerArrows[i];
			//erase from array
			playerArrows.erase(playerArrows.begin() + i);
		}
	}
	for (unsigned int i = 0; i < archerArrows.size(); i++)
	{
		if (archerArrows[i]->getDeadStatus())
		{
			//Check if the arrow will have death particles
			if (archerArrows[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(archerArrows[i]->getPosition(), archerArrows[i]->getVelocities(),
					archerArrows[i]->getDimensions(), false, 0, "archerArrow");
			}
			//delete pointer
			delete archerArrows[i];
			//erase from array
			archerArrows.erase(archerArrows.begin() + i);
		}
	}
	for (unsigned int i = 0; i < flamingArrows.size(); i++)
	{
		if (flamingArrows[i]->getDeadStatus())
		{
			//Check if the arrow will have death particles
			if (flamingArrows[i]->getDeathParticles())
			{
				//Handle the death particle effects.
				createDeathEffects(flamingArrows[i]->getPosition(), flamingArrows[i]->getVelocities(),
					flamingArrows[i]->getDimensions(), false, 0, "fire");
			}
			//delete pointer
			delete flamingArrows[i];
			//erase from array
			flamingArrows.erase(flamingArrows.begin() + i);
		}
	}
}

void E_EntityManager::createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, C_Vec2 entityDimensions, 
	bool coinSpawn, int maxCoins, std::string entityType)
{
	if (coinSpawn)
	{
		//push back a coin effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(coinSprite, entityPos + (entityDimensions * 0.5f), true, 50.0f, 25.0f, 0.1f));

		//create a random number of coins to spawn
		int numOfCoins = (rand() % maxCoins) + 1;

		for (int i = 0; i <= numOfCoins; i++)
		{
			//generate a new random position for the coin
			C_Vec2 coinPos = entityPos + (entityDimensions * 0.5f) - (coinDimensions * 0.5f);
			coinPos += C_Vec2((rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y, 
				(rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y);

			//spawn the coin
			coins.push_back(new E_Coin(coinSprite, coinPos, coinDimensions, dimensions, entityVelocity));
		}
		
	}
	else
	{
		//push back a death effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(particleEffectTexture,
			entityPos + (entityDimensions * 0.5f), true, 50.0f, 25.0f, 0.1f, minColourTints[entityType], maxColourTints[entityType]));
	}
}

void E_EntityManager::removeCompletedEffects()
{
	for (unsigned int i = 0; i < deathEffects.size(); i++)
	{
		if (deathEffects[i]->getLifeSpan()->checkTimer())
		{
			if (deathEffects[i]->getDead())
			{
				//delete pointer
				delete deathEffects[i];
				//erase from array
				deathEffects.erase(deathEffects.begin() + i);
			}
			else
			{
				//deactivate death effect
				deathEffects[i]->setEmitting(false);
				//reset the lifespan of the effect
				deathEffects[i]->getLifeSpan()->setTimerLength(2.0f);
				//set the effect to dead.
				deathEffects[i]->setDead(true);
			}
			
		}
	}
}

void E_EntityManager::entityCollisionDetection()
{
	//Collision for the StyphBirds
	for (auto styphBird : styphBirds)
	{
		//Collision between the player and StyphBirds
		if (player->entityCollisionTest(styphBird->getPosition(), styphBird->getDimensions()))
		{
			styphBird->setDeathParticles(true);
			styphBird->setDeadStatus(true);
			player->decreaseHealth();
			healthLossSounds[player->getHealth()]->playEffect();
		}

		//Collision between the arrows and StyphBirds
		for (auto arrow : playerArrows)
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
		for (auto arrow : flamingArrows)
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
	for (auto archer : archers)
	{
		//Collision between the arrows and archers
		for (auto arrow : playerArrows)
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
		for (auto arrow : flamingArrows)
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
	for (auto stormCloud : stormClouds)
	{
		if (player->entityCollisionTest(stormCloud->getPosition(), stormCloud->getDimensions()))
		{
			stormCloud->setDeathParticles(true);
			stormCloud->setDeadStatus(true);
			player->decreaseHealth();
			healthLossSounds[player->getHealth()]->playEffect();
		}
	}

	//Collision between the player and the coins
	for (auto coin : coins)
	{
		if (player->entityCollisionTest(coin->getPosition(), coin->getDimensions()))
		{
			coin->setDeadStatus(true);
			player->increaseCoins();
			coinCollectSound->playEffect();
		}
	}

	//Collision between the player and the health
	for (auto healthPickup : health)
	{
		if (player->entityCollisionTest(healthPickup->getPosition(), healthPickup->getDimensions()))
		{
			healthPickup->setDeadStatus(true);
			player->increaseHealth();
			healthCollectSound->playEffect();
		}
	}

	//Collision between the player and the fire power ups
	for (auto firePowerUp : firePowerUps)
	{
		if (player->entityCollisionTest(firePowerUp->getPosition(), firePowerUp->getDimensions()))
		{
			firePowerUp->setDeadStatus(true);
			player->setFlaming(true);
		}
	}

	//Collision between the player and the archer arrows
	for (auto arrow : archerArrows)
	{
		if (player->entityCollisionTest(arrow->getPosition(), arrow->getDimensions()))
		{
			player->decreaseHealth();
			healthLossSounds[player->getHealth()]->playEffect();
			arrow->setDeadStatus(true);
			arrow->setDeathParticles(true);
		}
	}
}