#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, EP_Player* player, SDL_Renderer* renderer, 
	C_Texture* fireSprite, SDL_Colour minFireTint, SDL_Colour maxFireTint) :
	dimensions(dimensions), player(player), renderer(renderer), fireSprite(fireSprite),
	styphBirdSprite(new C_Texture("Assets/Images/stymphalianBird.png", renderer)),
	stormCloudSprite(new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer)),
	coinSprite(new C_Texture("Assets/Images/coin.png", renderer)),
	healthSprite(new C_Texture("Assets/Images/health300x299.png", renderer)),
	flamingSprite(new C_Texture("Assets/Images/particle.png", renderer)), //tmp
	killAllSprite(new C_Texture("Assets/Images/particle.png", renderer)), //tmp
	coinAllSprite(new C_Texture("Assets/Images/particle.png", renderer)), //tmp
	shieldSprite(new C_Texture("Assets/Images/particle.png", renderer)), //tmp
	playerArrowSprite(new C_Texture("Assets/Images/playerArrow.png", renderer)),
	archerArrowSprite(new C_Texture("Assets/Images/archerArrow.png", renderer)),
	archerSprite(new C_Texture("Assets/Images/archer.png", renderer)),
	particleEffectTexture(new C_Texture("Assets/Images/particle.png", renderer)),
	arrowDimensions(C_Vec2(dimensions.y * 0.08f, dimensions.y * 0.02f)),
	coinCollectSound(new C_Audio("Assets/Audio/powerUp2.ogg")),
	healthCollectSound(new C_Audio("Assets/Audio/healthUp.ogg")),
	spawnTimer(1.0f)
{	
	//tmp
	flamingSprite->setColourTint(255, 0, 0);
	coinAllSprite->setColourTint(255, 255, 0);
	killAllSprite->setColourTint(0, 0, 0);
	shieldSprite->setColourTint(0, 255, 255);

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
	minColourTints["fire"] = minFireTint;
	maxColourTints["fire"] = maxFireTint;

	//Initialise array sounds
	healthLossSounds[0] = new C_Audio("Assets/Audio/deathSound.ogg");
	healthLossSounds[1] = new C_Audio("Assets/Audio/hitSound2.ogg");
	healthLossSounds[2] = new C_Audio("Assets/Audio/hitSound.ogg");

	//Initialise spawn-able entity dimensions
	entityDimensions[0] = C_Vec2(dimensions * 0.06f);//styphBirdDimensions
	entityDimensions[1] = C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f);//stormCloudsDimensions
	entityDimensions[2] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);//coinDimensions
	entityDimensions[3] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f); //healthDimensions
	entityDimensions[4] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);//firePowerUpDimensions
	entityDimensions[5] = C_Vec2(dimensions.y * 0.1f, dimensions.y * 0.15f);//archerDimensions
	entityDimensions[6] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f); //coinAllPowerUpDimensions
	entityDimensions[7] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f); //killAllPowerDimensions
	entityDimensions[8] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f); //shieldDimensions
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
	for (auto healthPickup : healthPickups)
	{
		delete healthPickup;
	}
	delete healthSprite;

	//Delete fire power ups
	for (auto firePowerUp : flamingPickups)
	{
		delete firePowerUp;
	}
	delete flamingSprite;

	//Delete kill all power ups
	for (auto killAllPowerUp : killAllPickups)
	{
		delete killAllPowerUp;
	}
	delete killAllSprite;

	//Delete coin all power ups
	for (auto coinAllPowerUp : coinAllPickups)
	{
		delete coinAllPowerUp;
	}
	delete coinAllSprite;

	//Delete shields
	for (auto shield : shieldPickups)
	{
		delete shield;
	}
	delete shieldSprite;

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
		case SDLK_h:
			player->increaseHealth();
			break;			
		case SDLK_c:
			coinAllPickups.push_back(new EPU_CoinAll(coinAllSprite,
				C_Vec2(dimensions.x + entityDimensions[6].x, player->getPosition().y),
				entityDimensions[6], dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_d:  //KillAllPowerUp
			killAllPickups.push_back(new EPU_KillAll(killAllSprite,
				C_Vec2(dimensions.x + entityDimensions[7].x, player->getPosition().y),
				entityDimensions[7], dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_s: //Shields
			shieldPickups.push_back(new EPU_Shield(shieldSprite,
				C_Vec2(dimensions.x + entityDimensions[8].x, player->getPosition().y),
				entityDimensions[8], dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		}
		break;
	}
}

void E_EntityManager::update(float dt)
{
	//Update the spawn timer
	spawnTimer.upadateTimer(dt);
	//check if a new wave of entities should be spawned
	if (spawnTimer.checkTimer())
	{
		spawnEntityWave();
		spawnTimer.resetTimer();
	}

	//check if the player should fire an flaming arrow
	if (player->getFireArrow() && player->getFlaming())
	{
		flamingArrows.push_back(new EA_FlamingArrow(playerArrowSprite, fireSprite,
			C_Vec2(player->getPosition().x + player->getDimensions().x, player->getPosition().y),
			arrowDimensions, dimensions, minColourTints["fire"], maxColourTints["fire"]));
		player->setFireArrow(false);
	}

	//check if the player should fire a normal arrow
	if (player->getFireArrow() && !player->getFlaming())
	{
		playerArrows.push_back(new EA_PlayerArrow(playerArrowSprite,
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
			archerArrows.push_back(new EA_ArcherArrow(archerArrowSprite, archer->getPosition(), arrowDimensions));
			archer->setFireArrow(false);
		}
	}

	//Update health
	for (auto healthPickup : healthPickups)
	{
		healthPickup->update(dt);
	}

	//Update Coins
	for (auto coin : coins)
	{
		coin->update(dt);
	}

	//Update fire power ups
	for (auto firePowerUp : flamingPickups)
	{
		firePowerUp->update(dt);
	}

	//Update coin all power ups
	for (auto coinAllPowerUp : coinAllPickups)
	{
		coinAllPowerUp->update(dt);
	}

	//Update kill all power ups
	for (auto killAllPowerUp : killAllPickups)
	{
		killAllPowerUp->update(dt);
	}

	//Update shields
	for (auto shield : shieldPickups)
	{
		shield->update(dt);
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
	for (auto healthPickup : healthPickups)
	{
		healthPickup->draw(renderer);
	}

	//Draw the fire power ups
	for (auto firePowerUp : flamingPickups)
	{
		firePowerUp->draw(renderer);
	}

	//Draw the kill all power ups
	for (auto killAllPowerUp : killAllPickups)
	{
		killAllPowerUp->draw(renderer);
	}

	//Draw the coin all power ups
	for (auto coinAllPowerUp : coinAllPickups)
	{
		coinAllPowerUp->draw(renderer);
	}

	//Draw the shields
	for (auto shield : shieldPickups)
	{
		shield->draw(renderer);
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
	for (unsigned int i = 0; i < healthPickups.size(); i++)
	{
		if (healthPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete healthPickups[i];
			//erase from array
			healthPickups.erase(healthPickups.begin() + i);
		}
	}

	//Remove dead fire power ups
	for (unsigned int i = 0; i < flamingPickups.size(); i++)
	{
		if (flamingPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete flamingPickups[i];
			//erase from array
			flamingPickups.erase(flamingPickups.begin() + i);
		}
	}

	//Remove dead kill all power ups
	for (unsigned int i = 0; i < killAllPickups.size(); i++)
	{
		if (killAllPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete killAllPickups[i];
			//erase from array
			killAllPickups.erase(killAllPickups.begin() + i);
		}
	}

	//Remove dead coin all power ups
	for (unsigned int i = 0; i < coinAllPickups.size(); i++)
	{
		if (coinAllPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete coinAllPickups[i];
			//erase from array
			coinAllPickups.erase(coinAllPickups.begin() + i);
		}
	}

	//Remove dead shields
	for (unsigned int i = 0; i < shieldPickups.size(); i++)
	{
		if (shieldPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete shieldPickups[i];
			//erase from array
			shieldPickups.erase(shieldPickups.begin() + i);
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

void E_EntityManager::createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, C_Vec2 deadEntityDimensions, 
	bool coinSpawn, int maxCoins, std::string entityType)
{
	if (coinSpawn)
	{
		//push back a coin effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(coinSprite, entityPos + (deadEntityDimensions * 0.5f), true, 50.0f, 25.0f, 0.1f));

		//create a random number of coins to spawn
		int numOfCoins = (rand() % maxCoins) + 1;

		for (int i = 0; i <= numOfCoins; i++)
		{
			//generate a new random position for the coin
			C_Vec2 coinPos = entityPos + (deadEntityDimensions * 0.5f) - (entityDimensions[2] * 0.5f);
			coinPos += C_Vec2((rand() % (int)(dimensions.y * 0.1f)) - entityDimensions[2].y,
				(rand() % (int)(dimensions.y * 0.1f)) - entityDimensions[2].y);

			//spawn the coin
			coins.push_back(new EPU_Coin(coinSprite, coinPos, entityDimensions[2], dimensions, entityVelocity));
		}
		
	}
	else
	{
		//push back a death effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(particleEffectTexture,
			entityPos + (deadEntityDimensions * 0.5f), true, 50.0f, 25.0f, 0.1f, minColourTints[entityType], maxColourTints[entityType]));
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
	for (auto healthPickup : healthPickups)
	{
		if (player->entityCollisionTest(healthPickup->getPosition(), healthPickup->getDimensions()))
		{
			healthPickup->setDeadStatus(true);
			player->increaseHealth();
			healthCollectSound->playEffect();
		}
	}

	//Collision between the player and the fire power ups
	for (auto firePowerUp : flamingPickups)
	{
		if (player->entityCollisionTest(firePowerUp->getPosition(), firePowerUp->getDimensions()))
		{
			firePowerUp->setDeadStatus(true);
			player->setFlaming(true);
		}
	}

	//Collision between the player and the kill all power ups
	for (auto killAllPowerUp : killAllPickups)
	{
		if (player->entityCollisionTest(killAllPowerUp->getPosition(), killAllPowerUp->getDimensions()))
		{
			killAllPowerUp->setDeadStatus(true);
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
		}
	}

	//Collision between the player and the coin all power ups
	for (auto coinAllPowerUp : coinAllPickups)
	{
		if (player->entityCollisionTest(coinAllPowerUp->getPosition(), coinAllPowerUp->getDimensions()))
		{
			coinAllPowerUp->setDeadStatus(true);
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
		}
	}

	//Collision between the player and the shields
	for (auto shield : shieldPickups)
	{
		if (player->entityCollisionTest(shield->getPosition(), shield->getDimensions()))
		{
			shield->setDeadStatus(true);
			//TODO
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

void E_EntityManager::spawnEntityWave()
{
	//Get a number between 0 and 5 for max 6 number of things to spawn
	int numberToSpawn = (rand() % 6);

	//Divide the screen height into the number of things to spawn
	float zoneHeight = dimensions.y / numberToSpawn;
		
	for (int i = 0; i <= numberToSpawn; i++)
	{
		//Get a number between 0 and 5 for max 6 thing to spawn
		int entityToSpawn = pickEntity();

		//initialise the new spawn position
		float spawnY = 0.0f;

		//work out the minimum spawn y position within its heights zone
		float minimumY = i * zoneHeight;

		//work out the maximum spawn y position within its heights zone
		float maximumY = ((i+1) * zoneHeight) - 1;
		maximumY -= entityDimensions[entityToSpawn].y;

		//make a random y spawn within the min and max height
		spawnY = (float)(rand() % (int)(maximumY - minimumY)) + minimumY;

		//spawn the entity
		spawnEntity(spawnY, entityToSpawn);
	}
	
}

int E_EntityManager::pickEntity()
{
	//generate a new number between 1 and 200
	int spawnNumber = (rand() % 201) + 1;

	//work out the coin and health spawn % depending on lives left
	switch (player->getHealth())
	{
	case 3://3 lives left - 50% coin, 0% health
		if (spawnNumber <= 100) //50% chance
		{
			//entity is a coin
			return 2;
		}
		break;

	case 2://2 lives left - 40% coin, 10% health
		if (spawnNumber <= 80) //40% chance
		{
			//entity is a coin
			return 2;
		}
		else if (spawnNumber >= 81 && spawnNumber <= 100) //10% chance
		{
			//entity is a health
			return 3;
		}
		break;

	case 1://1 life left - 30% coin, 20% health
		if (spawnNumber <= 60) //30% chance
		{
			//entity is a coin
			return 2;
		}
		else if (spawnNumber >= 61 && spawnNumber <= 100) //20% chance
		{
			//entity is a health
			return 3;
		}
		break;
	}
		
	if (spawnNumber >= 101 && spawnNumber <= 140) // 20% chance
	{
		//entity is a cloud
		return 1;
	}
	else if (spawnNumber >= 141 && spawnNumber <= 170) // 15% chance
	{
		//entity is a styphBird
		return 0;
	}
	else if (spawnNumber >= 171 && spawnNumber <= 190) // 19% chance
	{
		//entity is a archer
		return 5;
	}
	else if (spawnNumber >= 191 && spawnNumber <= 194) // 2% chance
	{
		//entity is a firePowerUp
		return 4;
	}
	else if (spawnNumber >= 195 && spawnNumber <= 197) // 1.5% chance
	{
		//entity is a Shield
		return 8;
	}
	else if (spawnNumber >= 198 && spawnNumber <= 199) // 1% chance
	{
		//entity is a killAllPowerUp
		return 7;
	}
	else if (spawnNumber == 200) // 0.5% chance
	{
		//entity is a coinAllPowerUp
		return 6;
	}

	//something has gone wrong
	return -1;
}

void E_EntityManager::spawnEntity(float spawnY, int entityToSpawn)
{
	//Spawn the new entity
	switch (entityToSpawn)
	{
	case 0: //StyphBird
		styphBirds.push_back(new EE_StyphBird(styphBirdSprite,
			C_Vec2(dimensions.x + entityDimensions[0].x, spawnY),
			entityDimensions[0]));
		break;
	case 1: //StormCloud
		stormClouds.push_back(new EE_StormCloud(stormCloudSprite,
			C_Vec2(dimensions.x + entityDimensions[1].x, spawnY),
			entityDimensions[1]));
		break;
	case 2: //Coin
		coins.push_back(new EPU_Coin(coinSprite,
			C_Vec2(dimensions.x + entityDimensions[2].x, spawnY),
			entityDimensions[2], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	case 3: //Health
		healthPickups.push_back(new EPU_Health(healthSprite,
			C_Vec2(dimensions.x + entityDimensions[3].x, spawnY),
			entityDimensions[3], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	case 4: //FirePowerUp
		flamingPickups.push_back(new EPU_Flaming(flamingSprite,
			C_Vec2(dimensions.x + entityDimensions[4].x, spawnY),
			entityDimensions[4], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	case 5: //Archer
		archers.push_back(new EE_Archer(archerSprite,
			C_Vec2(dimensions.x + entityDimensions[5].x, spawnY),
			entityDimensions[5]));
		break;
	case 6: //CoinAllPowerUp
		coinAllPickups.push_back(new EPU_CoinAll(coinAllSprite,
			C_Vec2(dimensions.x + entityDimensions[6].x, spawnY),
			entityDimensions[6], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	case 7:  //KillAllPowerUp
		killAllPickups.push_back(new EPU_KillAll(killAllSprite,
			C_Vec2(dimensions.x + entityDimensions[7].x, spawnY),
			entityDimensions[7], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	case 8: //Shields
		shieldPickups.push_back(new EPU_Shield(shieldSprite,
			C_Vec2(dimensions.x + entityDimensions[8].x, spawnY),
			entityDimensions[8], dimensions, C_Vec2(-500.0f, 0.0f)));
		break;
	}
}


////Notes
//-problem with clouds bounding boxes including the lighting effects which throws off the 
//positioning, need to redo bounding boxes of clouds so that it does not include them.
//-player needs to be shrunk to 1/8th of the screen size so that it can fit in a zone.
//-Player also needs to possibly change where the arrows are fired on as at the moment 
//things can be spawned out of arrow range at the bottom and possibly at the top.
//-Possibly change to oval oval collision detection to improve it.
//-Make the shield pickup do something.
//-Add slow down power up?
//-possibly make the power ups be stored by the player and the player should activate them.
//-possibly make the amount of time between waves of entities decrease as the score increases.
//-OO the HELL out of the entity manager!!!!!