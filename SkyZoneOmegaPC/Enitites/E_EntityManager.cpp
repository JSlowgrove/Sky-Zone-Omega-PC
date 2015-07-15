#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, E_Player* player, SDL_Renderer* renderer) : dimensions(dimensions), player(player), renderer(renderer)
{	
	//Initialise entity textures
	styphBirdSprite = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	stormCloudSprite = new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer);
	coinSprite = new C_Texture("Assets/Images/coin.png", renderer);

	//Initialise the particle effect texture
	deathEffectTexture = new C_Texture(renderer, 255, 0, 0);

	//Initialise the entity dimensions
	styphBirdDimensions = dimensions * 0.06f;
	stormCloudsDimensions = C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f);
	coinDimensions = C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f);
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
		case SDLK_k:
			for (auto styphBird : styphBirds)
			{
				styphBird->setDeathParticles(true);
				styphBird->setCoinSpawn(true);
				styphBird->setDeadStatus(true);
			}
			break;
		case SDLK_d:
			for (auto styphBird : styphBirds)
			{
				styphBird->setDeathParticles(true);
				styphBird->setDeadStatus(true);
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

	//Update Coins
	for (auto coin : coins)
	{
		coin->update(dt);
	}

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
				createDeathEffects(styphBirds[i]->getPosition(), styphBirds[i]->getVelocities(), styphBirds[i]->getCoinSpawn(), 5);
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
}

void E_EntityManager::createDeathEffects(C_Vec2 entityPos, C_Vec2 entityVelocity, bool coinSpawn, int maxCoins)
{
	if (coinSpawn)
	{
		//push back a coin effect for the entity.
		deathEffects.push_back(new PS_ParticleEffect(coinSprite, entityPos, true, 50.0f, 50.0f, 0.1f));

		//create a random number of coins to spawn
		int numOfCoins = (rand() % maxCoins) + 1;

		for (int i = 0; i <= numOfCoins; i++)
		{
			//generate a new random position for the coin
			C_Vec2 coinPos = entityPos + coinDimensions * 0.5f;
			coinPos += C_Vec2((rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y, (rand() % (int)(dimensions.y * 0.1f)) - coinDimensions.y);

			//spawn the coin
			coins.push_back(new E_Coin(coinSprite, coinPos, coinDimensions, dimensions, entityVelocity));
		}
		
	}
	else
	{
		//push back a death effect for the entity.
		deathEffects.push_back(	new PS_ParticleEffect(deathEffectTexture, entityPos + (coinDimensions * 0.5f), true, 50.0f, 15.0f, 0.1f));
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