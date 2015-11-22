#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, EP_Player* player, SDL_Renderer* renderer, 
	C_Texture* fireSprite, SDL_Colour minFireTint, SDL_Colour maxFireTint, float* universalSpeed) :
	screenDimensions(dimensions), player(player), renderer(renderer),
	arrowShotSound(new C_Audio("Assets/Audio/arrowShot.ogg")),
	fireArrowShotSound(new C_Audio("Assets/Audio/fireShot.ogg")),
	coinCollectSound(new C_Audio("Assets/Audio/coinCollect.ogg")),
	healthCollectSound(new C_Audio("Assets/Audio/healthUp.ogg")),
	shieldCollectSound(new C_Audio("Assets/Audio/shieldCollect.ogg")),
	coinKillAllCollectSound(new C_Audio("Assets/Audio/coinKillAllCollect.ogg")),
	fireCollectSound(new C_Audio("Assets/Audio/fireCollect.ogg")),
	timeSlowCollectSound(new C_Audio("Assets/Audio/timeSlowCollect.ogg")),
	enemyDeathSound(new C_Audio("Assets/Audio/enemyDeath.ogg")),
	enemyHitSound(new C_Audio("Assets/Audio/enemyHit.ogg")),
	universalSpeed(universalSpeed)
{	
	//Initialise the textures
	textures["EE_StyphBird"] = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	textures["EE_StormCloud"] = new C_Texture("Assets/Images/cloudsSpritesheet562x401.png", renderer);
	textures["EE_Archer"] = new C_Texture("Assets/Images/archer.png", renderer);
	textures["EPU_Coin"] = new C_Texture("Assets/Images/coin.png", renderer);
	textures["EPU_Health"] = new C_Texture("Assets/Images/health300x299.png", renderer);
	textures["EPU_Flaming"] = new C_Texture("Assets/Images/flaming.png", renderer);
	textures["EPU_CoinAll"] = new C_Texture("Assets/Images/coinAll.png", renderer);
	textures["EPU_KillAll"] = new C_Texture("Assets/Images/killAll.png", renderer);
	textures["EPU_Shield"] = new C_Texture("Assets/Images/shield.png", renderer);
	textures["EPU_TimeSlow"] = new C_Texture("Assets/Images/timeSlow.png", renderer);
	textures["EA_PlayerArrow"] = new C_Texture("Assets/Images/playerArrow.png", renderer);
	textures["EA_ArcherArrow"] = new C_Texture("Assets/Images/archerArrow.png", renderer);
	textures["PS_DeathParticle"] = new C_Texture("Assets/Images/particle.png", renderer);
	textures["PS_FireParticle"] = fireSprite;

	//Initialise the min and max tint colours for the particle effects
	minColourTints["EE_StyphBird"] = { (Uint8)155, (Uint8)100, (Uint8)0 };
	maxColourTints["EE_StyphBird"] = { (Uint8)255, (Uint8)200, (Uint8)20 };
	minColourTints["EE_StormCloud"] = { (Uint8)0, (Uint8)0, (Uint8)0 };
	maxColourTints["EE_StormCloud"] = { (Uint8)45, (Uint8)45, (Uint8)45 };
	minColourTints["EE_Archer"] = { (Uint8)0, (Uint8)0, (Uint8)0 };
	maxColourTints["EE_Archer"] = { (Uint8)155, (Uint8)0, (Uint8)0 };
	minColourTints["EA_PlayerArrow"] = { (Uint8)0, (Uint8)0, (Uint8)155 };
	maxColourTints["EA_PlayerArrow"] = { (Uint8)0, (Uint8)155, (Uint8)255 };
	minColourTints["EA_ArcherArrow"] = { (Uint8)55, (Uint8)0, (Uint8)0 };
	maxColourTints["EA_ArcherArrow"] = { (Uint8)255, (Uint8)0, (Uint8)0 };
	minColourTints["PS_Fire"] = minFireTint;
	maxColourTints["PS_Fire"] = maxFireTint;

	//Initialise dimensions
	entityDimensions["EE_StyphBird"] = C_Vec2(dimensions * 0.06f);
	entityDimensions["EE_StormCloud"] = C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.2f);
	entityDimensions["EE_Archer"] = C_Vec2(dimensions.y * 0.1f, dimensions.y * 0.15f);
	entityDimensions["EPU_Coin"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_Health"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_Flaming"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_CoinAll"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_KillAll"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_Shield"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EPU_TimeSlow"] = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	entityDimensions["EA_Arrow"] = C_Vec2(dimensions.y * 0.08f, dimensions.y * 0.02f);

	
}

E_EntityManager::~E_EntityManager()
{
	//Delete particle effects
	for (auto deathEffect : deathEffects)
	{
		delete deathEffect;
	}

	//Delete StyphBirds
	for (auto styphBird : styphBirds)
	{
		delete styphBird;
	}

	//Delete storm clouds
	for (auto stormCloud : stormClouds)
	{
		delete stormCloud;
	}

	//Delete coins
	for (auto coin : coins)
	{
		delete coin;
	}

	//Delete health
	for (auto healthPickup : healthPickups)
	{
		delete healthPickup;
	}

	//Delete fire power ups
	for (auto firePowerUp : flamingPickups)
	{
		delete firePowerUp;
	}

	//Delete kill all power ups
	for (auto killAllPowerUp : killAllPickups)
	{
		delete killAllPowerUp;
	}

	//Delete coin all power ups
	for (auto coinAllPowerUp : coinAllPickups)
	{
		delete coinAllPowerUp;
	}

	//Delete shields
	for (auto shield : shieldPickups)
	{
		delete shield;
	}

	//Delete time slow power ups
	for (auto timeSlow : timeSlowPickups)
	{
		delete timeSlow;
	}

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

	//Delete archers
	for (auto archer : archers)
	{
		delete archer;
	}

	//Delete textures
	for (auto i = textures.begin(); i != textures.end(); ++i)
	{
		delete i->second;
	}

	//Delete audio
	delete coinCollectSound;
	delete healthCollectSound;
	delete shieldCollectSound;
	delete coinKillAllCollectSound;
	delete fireCollectSound;
	delete timeSlowCollectSound;
	delete enemyDeathSound;
	delete enemyHitSound;
}

void E_EntityManager::update(float dt)
{
	//remove entities flagged as dead.
	removeDeadEntites();

	//remove completed particle effects
	removeCompletedEffects();

	//set the time speed to be the value of the time slow effect if active
	if (player->getTimeSlow())
	{
		*universalSpeed = (screenDimensions.x * 0.000425f);
	}
	else
	{
		*universalSpeed = (screenDimensions.x * 0.00085f);
	}

	//check if the player should fire an flaming arrow
	if (player->getFireArrow() && player->getFlaming())
	{
		flamingArrows.push_back(new EA_FlamingArrow(textures["EA_PlayerArrow"], textures["PS_FireParticle"],
			C_Vec2(player->getPosition().x + (player->getDimensions().x * 0.4f), player->getPosition().y),
			entityDimensions["EA_Arrow"], screenDimensions, minColourTints["PS_Fire"], maxColourTints["PS_Fire"], universalSpeed));
		player->setFireArrow(false);
		fireArrowShotSound->playEffect();
	}

	//check if the player should fire a normal arrow
	if (player->getFireArrow() && !player->getFlaming())
	{
		playerArrows.push_back(new EA_PlayerArrow(textures["EA_PlayerArrow"],
			C_Vec2(player->getPosition().x + (player->getDimensions().x * 0.4f), player->getPosition().y),
			entityDimensions["EA_Arrow"], screenDimensions, universalSpeed));
		player->setFireArrow(false);
		arrowShotSound->playEffect();
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
			archerArrows.push_back(new EA_ArcherArrow(textures["EA_ArcherArrow"], archer->getPosition(), 
				entityDimensions["EA_Arrow"], universalSpeed));
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

	//Update time slows
	for (auto timeSlow : timeSlowPickups)
	{
		timeSlow->update(dt);
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

	//Draw the time slow power ups
	for (auto timeSlow : timeSlowPickups)
	{
		timeSlow->draw(renderer);
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
					styphBirds[i]->getDimensions(), styphBirds[i]->getCoinSpawn(), 5, "EE_StyphBird");
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
					stormClouds[i]->getDimensions(), false, 0, "EE_StormCloud");
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
					archers[i]->getDimensions(), archers[i]->getCoinSpawn(), 10, "EE_Archer");
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

	//Remove time slow power ups
	for (unsigned int i = 0; i < timeSlowPickups.size(); i++)
	{
		if (timeSlowPickups[i]->getDeadStatus())
		{
			//delete pointer
			delete timeSlowPickups[i];
			//erase from array
			timeSlowPickups.erase(timeSlowPickups.begin() + i);
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
					playerArrows[i]->getDimensions(), false, 0, "EA_PlayerArrow");
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
					archerArrows[i]->getDimensions(), false, 0, "EA_ArcherArrow");
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
					flamingArrows[i]->getDimensions(), false, 0, "PS_Fire");
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
		deathEffects.push_back(new PS_ParticleEffect(textures["EPU_Coin"],
			entityPos + (deadEntityDimensions * 0.5f), true, 50.0f, 25.0f, 0.1f));

		//create a random number of coins to spawn
		int numOfCoins = (rand() % maxCoins) + 1;

		for (int i = 0; i <= numOfCoins; i++)
		{
			//generate a new random position for the coin
			C_Vec2 coinPos = entityPos + (deadEntityDimensions * 0.5f) - (entityDimensions["EPU_Coin"] * 0.5f);
			coinPos += C_Vec2((rand() % (int)(screenDimensions.y * 0.1f)) - entityDimensions["EPU_Coin"].y,
				(rand() % (int)(screenDimensions.y * 0.1f)) - entityDimensions["EPU_Coin"].y);

			//spawn the coin
			coins.push_back(new EPU_Coin(textures["EPU_Coin"], coinPos, entityDimensions["EPU_Coin"], 
				screenDimensions, entityVelocity, universalSpeed));
		}
		
	}
	else
	{
		//push back a death effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(textures["PS_DeathParticle"],
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

C_Texture* E_EntityManager::getTexture(std::string iD)
{
	return textures[iD];
}

C_Vec2 E_EntityManager::getEntityDimensions(std::string iD)
{
	return entityDimensions[iD];
}

std::vector<EE_StyphBird*> E_EntityManager::getStyphBirds()
{ 
	return styphBirds; 
};

std::vector<EE_StormCloud*> E_EntityManager::getStormClouds()
{ 
	return stormClouds; 
};

std::vector<EE_Archer*> E_EntityManager::getArchers()
{ 
	return archers; 
};

std::vector<EPU_Coin*>E_EntityManager::getCoins()
{ 
	return coins; 
};

std::vector<EPU_Health*> E_EntityManager::getHealthPickups()
{ 
	return healthPickups; 
};

std::vector<EPU_Flaming*> E_EntityManager::getFlamingPickups()
{ 
	return flamingPickups; 
};

std::vector<EPU_KillAll*> E_EntityManager::getKillAllPickups()
{ 
	return killAllPickups; 
};

std::vector<EPU_CoinAll*> E_EntityManager::getCoinAllPickups()
{ 
	return coinAllPickups; 
};

std::vector<EPU_Shield*> E_EntityManager::getShieldPickups()
{ 
	return shieldPickups; 
};

std::vector<EPU_TimeSlow*> E_EntityManager::getTimeSlowPickups()
{
	return timeSlowPickups;
};

std::vector<EA_PlayerArrow*> E_EntityManager::getPlayerArrows()
{ 
	return playerArrows; 
};

std::vector<EA_FlamingArrow*> E_EntityManager::getFlamingArrows()
{ 
	return flamingArrows; 
};

std::vector<EA_ArcherArrow*> E_EntityManager::getArcherArrows()
{ 
	return archerArrows; 
};

void E_EntityManager::playCoinCollectSound()
{ 
	coinCollectSound->playEffect(); 
};

void E_EntityManager::playHealthCollectSound()
{
	healthCollectSound->playEffect();
};

void E_EntityManager::playShieldCollectSound()
{
	shieldCollectSound->playEffect();
};

void E_EntityManager::playCoinKillAllCollectSound()
{
	coinKillAllCollectSound->playEffect();
};

void E_EntityManager::playFireCollectSound()
{
	fireCollectSound->playEffect();
};

void E_EntityManager::playTimeSlowCollectSound()
{
	timeSlowCollectSound->playEffect();
};

void E_EntityManager::playEnemyDeathSound()
{
	enemyDeathSound->playEffect();
};

void E_EntityManager::playEnemyHitSound()
{
	enemyHitSound->playEffect();
};

void E_EntityManager::spawnStyphBird(C_Vec2 spawnPos)
{
	styphBirds.push_back(
		new EE_StyphBird(getTexture("EE_StyphBird"),spawnPos,
		getEntityDimensions("EE_StyphBird"), universalSpeed));
}

void E_EntityManager::spawnStormCloud(C_Vec2 spawnPos)
{
	stormClouds.push_back(new EE_StormCloud(getTexture("EE_StormCloud"), spawnPos,
		getEntityDimensions("EE_StormCloud"), universalSpeed));
}

void E_EntityManager::spawnArcher(C_Vec2 spawnPos)
{
	archers.push_back(new EE_Archer(getTexture("EE_Archer"), spawnPos,
		getEntityDimensions("EE_Archer"), universalSpeed));
}

void E_EntityManager::spawnCoin(C_Vec2 spawnPos)
{
	coins.push_back(new EPU_Coin(getTexture("EPU_Coin"), spawnPos,
		getEntityDimensions("EPU_Coin"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnHealth(C_Vec2 spawnPos)
{
	healthPickups.push_back(new EPU_Health(getTexture("EPU_Health"), spawnPos,
		getEntityDimensions("EPU_Health"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnFlaming(C_Vec2 spawnPos)
{
	flamingPickups.push_back(new EPU_Flaming(getTexture("EPU_Flaming"), spawnPos,
		getEntityDimensions("EPU_Flaming"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnCoinAll(C_Vec2 spawnPos)
{
	coinAllPickups.push_back(new EPU_CoinAll(getTexture("EPU_CoinAll"), spawnPos,
		getEntityDimensions("EPU_CoinAll"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnKillAll(C_Vec2 spawnPos)
{
	killAllPickups.push_back(new EPU_KillAll(getTexture("EPU_KillAll"), spawnPos,
		getEntityDimensions("EPU_KillAll"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnShield(C_Vec2 spawnPos)
{
	shieldPickups.push_back(new EPU_Shield(getTexture("EPU_Shield"), spawnPos,
		getEntityDimensions("EPU_Shield"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}

void E_EntityManager::spawnTimeSlow(C_Vec2 spawnPos)
{
	timeSlowPickups.push_back(new EPU_TimeSlow(getTexture("EPU_TimeSlow"), spawnPos,
		getEntityDimensions("EPU_TimeSlow"), screenDimensions, C_Vec2(-500.0f, 0.0f), universalSpeed));
}