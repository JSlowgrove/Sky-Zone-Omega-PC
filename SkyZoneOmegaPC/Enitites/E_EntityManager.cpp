#include "E_EntityManager.h"

E_EntityManager::E_EntityManager(C_Vec2 dimensions, E_Player* player, SDL_Renderer* renderer) : dimensions(dimensions), player(player)
{	
	//Initialise entity textures
	styphBirdSprite = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	stormCloudSprite = new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer);
	coinSprite = new C_Texture("Assets/Images/coin.png", renderer);
}

E_EntityManager::~E_EntityManager()
{
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
				dimensions * 0.06f));
			break;
		case SDLK_s:
			stormClouds.push_back(new E_StormCloud(stormCloudSprite,
				C_Vec2(dimensions.x + (dimensions.x * 0.15f), player->getPosition().y),
				C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f)));
			break;
		case SDLK_c:
			coins.push_back(new E_Coin(coinSprite,
				C_Vec2(dimensions.x + (dimensions.y * 0.05f), player->getPosition().y),
				C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), dimensions));
			break;
		}
		break;
	}
}

void E_EntityManager::update(float dt)
{
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
}

void E_EntityManager::draw(SDL_Renderer* renderer)
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
}

void E_EntityManager::removeDeadEntites()
{
	//Remove dead StyphBirds
	for (unsigned int i = 0; i < styphBirds.size(); i++)
	{
		if (styphBirds[i]->getDeadStatus())
		{
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