#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, E_Player* player, SDL_Renderer* renderer) : 
dimensions(dimensions), player(player), renderer(renderer)
{	
	//Initialise entity textures
	styphBirdSprite = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	stormCloudSprite = new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer);
	coinSprite = new C_Texture("Assets/Images/coin.png", renderer);
	healthSprite = new C_Texture("Assets/Images/health300x299.png", renderer);
	arrowSprite = new C_Texture("Assets/Images/arrow.png", renderer);

	//Initialise the particle effect textures
	deathEffectTextures["styphBird"] = new C_Texture(renderer, 255, 193, 3);
	deathEffectTextures["stormCloud"] = new C_Texture(renderer, 0, 0, 0);

	//Initialise the entity dimensions
	styphBirdDimensions = dimensions * 0.06f;
	stormCloudsDimensions = C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f);
	coinDimensions = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	healthDimensions = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
	arrowDimensions = C_Vec2(dimensions.y * 0.08f, dimensions.y * 0.02f);

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

	//Delete particle effect textures
	for (auto i = deathEffectTextures.begin(); i != deathEffectTextures.end(); ++i)
	{
		delete i->second;
	}

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

	//Delete arrows
	for (auto arrow : arrows)
	{
		delete arrow;
	}
	delete arrowSprite;

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
		case SDLK_SPACE:
			styphBirds.push_back(new E_StyphBird(styphBirdSprite,
				C_Vec2(dimensions.x + (dimensions.x * 0.06f), player->getPosition().y),
				styphBirdDimensions));
			break;
		case SDLK_s:
			stormClouds.push_back(new E_StormCloud(stormCloudSprite,
				C_Vec2(dimensions.x + (dimensions.x * 0.15f), player->getPosition().y),
				stormCloudsDimensions));
			break;
		case SDLK_c:
			coins.push_back(new E_Coin(coinSprite,
				C_Vec2(dimensions.x + (dimensions.y * 0.05f), player->getPosition().y),
				coinDimensions, dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_h:
			health.push_back(new E_Health(healthSprite,
				C_Vec2(dimensions.x + (dimensions.y * 0.05f), player->getPosition().y),
				healthDimensions, dimensions, C_Vec2(-500.0f, 0.0f)));
			break;
		case SDLK_a:
			arrows.push_back(new E_Arrow(arrowSprite,
				C_Vec2(player->getPosition().x + player->getDimensions().x, player->getPosition().y),
				arrowDimensions));
			break;
		case SDLK_k:
			for (auto styphBird : styphBirds)
			{
				styphBird->setDeathParticles(true);
				styphBird->setCoinSpawn(true);
				styphBird->setDeadStatus(true);
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

	//Update Arrows
	for (auto arrow : arrows)
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

	//Draw the arrows
	for (auto arrow : arrows)
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

	//Remove dead Arrows
	for (unsigned int i = 0; i < arrows.size(); i++)
	{
		if (arrows[i]->getDeadStatus())
		{
			//delete pointer
			delete arrows[i];
			//erase from array
			arrows.erase(arrows.begin() + i);
		}
	}
}

void E_EntityManager::createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, C_Vec2 entityDimensions, 
	bool coinSpawn, int maxCoins, std::string entityType)
{
	if (coinSpawn)
	{
		//push back a coin effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(coinSprite, entityPos, true, 50.0f, 25.0f, 0.1f));

		//create a random number of coins to spawn
		int numOfCoins = (rand() % maxCoins) + 1;

		for (int i = 0; i <= numOfCoins; i++)
		{
			//generate a new random position for the coin
			C_Vec2 coinPos = entityPos + coinDimensions * 0.5f;
			coinPos += C_Vec2((rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y, 
				(rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y);

			//spawn the coin
			coins.push_back(new E_Coin(coinSprite, coinPos, coinDimensions, dimensions, entityVelocity));
		}
		
	}
	else
	{
		//push back a death effect for the entity.
		deathEffects.push_back(	new PS_ParticleEffect(deathEffectTextures[entityType], 
			entityPos + (entityDimensions * 0.5f), true, 50.0f, 15.0f, 0.1f));
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
		if (styphBird->getPosition().x <= (player->getPosition().x + player->getDimensions().x)
			&& styphBird->getPosition().y <= (player->getPosition().y + player->getDimensions().y)
			&& player->getPosition().x <= (styphBird->getPosition().x + styphBird->getDimensions().x)
			&& player->getPosition().y <= (styphBird->getPosition().y + styphBird->getDimensions().y))
		{
			styphBird->setDeathParticles(true);
			styphBird->setDeadStatus(true);
			player->decreaseHealth();
			healthLossSounds[player->getHealth()]->playEffect();
		}

		//Collision between the arrows and StyphBirds
		for (auto arrow : arrows)
		{
			if (styphBird->getPosition().x <= (arrow->getPosition().x + arrow->getDimensions().x)
				&& styphBird->getPosition().y <= (arrow->getPosition().y + arrow->getDimensions().y)
				&& arrow->getPosition().x <= (styphBird->getPosition().x + styphBird->getDimensions().x)
				&& arrow->getPosition().y <= (styphBird->getPosition().y + styphBird->getDimensions().y))
			{
				styphBird->setDeathParticles(true);
				styphBird->setDeadStatus(true);
				styphBird->setCoinSpawn(true);
				arrow->setDeadStatus(true);
			}
		}
	}

	//Collision between the player and storm clouds
	for (auto stormCloud : stormClouds)
	{
		if (stormCloud->getPosition().x <= (player->getPosition().x + player->getDimensions().x)
			&& stormCloud->getPosition().y <= (player->getPosition().y + player->getDimensions().y)
			&& player->getPosition().x <= (stormCloud->getPosition().x + stormCloud->getDimensions().x)
			&& player->getPosition().y <= (stormCloud->getPosition().y + stormCloud->getDimensions().y))
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
		if (coin->getPosition().x <= (player->getPosition().x + player->getDimensions().x)
			&& coin->getPosition().y <= (player->getPosition().y + player->getDimensions().y)
			&& player->getPosition().x <= (coin->getPosition().x + coin->getDimensions().x)
			&& player->getPosition().y <= (coin->getPosition().y + coin->getDimensions().y))
		{
			coin->setDeadStatus(true);
			player->increaseCoins();
			coinCollectSound->playEffect();
		}
	}

	//Collision between the player and the health
	for (auto healthPickup : health)
	{
		if (healthPickup->getPosition().x <= (player->getPosition().x + player->getDimensions().x)
			&& healthPickup->getPosition().y <= (player->getPosition().y + player->getDimensions().y)
			&& player->getPosition().x <= (healthPickup->getPosition().x + healthPickup->getDimensions().x)
			&& player->getPosition().y <= (healthPickup->getPosition().y + healthPickup->getDimensions().y))
		{
			healthPickup->setDeadStatus(true);
			player->increaseHealth();
			healthCollectSound->playEffect();
		}
	}
}