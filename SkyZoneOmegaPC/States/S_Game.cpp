#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions)
{
	//Initialise random seed
	srand((unsigned int)time(NULL));

	//Initialise the mouse position
	mousePos = C_Vec2();

	//Initialise the background
	background = new B_BackgroundManager(renderer, dimensions);

	//Initialise player
	playerSprite = new C_Texture("Assets/Images/player.png", renderer);
	player = new E_Player(playerSprite, C_Vec2(100.0f, 100.0f), dimensions * 0.2f, dimensions);

	//Initialise entity textures
	styphBirdSprite = new C_Texture("Assets/Images/stymphalianBird.png", renderer);
	stormCloudSprite = new C_Texture("Assets/Images/cloudsSpritesheet562x500.png", renderer);
	coinSprite = new C_Texture("Assets/Images/coin.png", renderer);
}

S_Game::~S_Game()
{	
	//Delete pointers
	delete background;

	//Delete player
	delete player;
	delete playerSprite;

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

bool S_Game::input()
{
	//Check for user input
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		switch (incomingEvent.type)
		{
		case SDL_QUIT: //If player closes the window, end the game loop

			return false;
			break;

		case SDL_KEYDOWN:
			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: //If Escape is pressed, end the game loop

				return false;
				break;

				//TMP
			case SDLK_SPACE:
				styphBirds.push_back(new E_StyphBird(styphBirdSprite, 
					C_Vec2(dimensions.x + (dimensions.x * 0.06f), player->getPosition().y), 
					dimensions * 0.06f, dimensions));
				break;
			case SDLK_s:
				stormClouds.push_back(new E_StormCloud(stormCloudSprite,
					C_Vec2(dimensions.x + (dimensions.x * 0.15f), player->getPosition().y),
					C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.25f), dimensions));
				break;
			case SDLK_c:
				coins.push_back(new E_Coin(coinSprite,
					C_Vec2(dimensions.x + (dimensions.y * 0.05f), player->getPosition().y),
					C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), dimensions));
				break;
			}
			break;

		case SDL_MOUSEMOTION: //If the mouse is moved

			//set the mouse position
			mousePos.x = ((float)incomingEvent.motion.x);
			mousePos.y = ((float)incomingEvent.motion.y);
			break;

		case SDL_MOUSEBUTTONDOWN: //If a mouse button is pressed

			//Left Mouse Button
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{

			}
			break;

		case SDL_MOUSEBUTTONUP://If a mouse button is released

			//Left Mouse Button
			if (incomingEvent.button.button == SDL_BUTTON_LEFT)
			{

			}
			break;
		}
		//Handle player input
		player->input(incomingEvent, mousePos);
	}
	return true;
}

void S_Game::update(float dt)
{
	//Update background
	background->update(dt);

	//Update player
	player->update(dt);

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

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);

	//Draw the player
	player->draw(renderer);

	//Draw the StyphBirds
	for (auto styphBird : styphBirds)
	{
		styphBird->draw(renderer);
	}

	//Draw the Storm Clouds
	for (auto stormCloud : stormClouds)
	{
		stormCloud->draw(renderer);
	}

	//Draw the Coins
	for (auto coin : coins)
	{
		coin->draw(renderer);
	}
}

void S_Game::removeDeadEntites()
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