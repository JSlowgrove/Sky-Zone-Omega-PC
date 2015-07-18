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
	playerSprite = new C_Texture("Assets/Images/player699x436.png", renderer);
	player = new E_Player(playerSprite, C_Vec2(dimensions.x * 0.1f, dimensions.y * 0.4f), dimensions * 0.2f, dimensions);

	//Initialise entity manager
	entityManager = new E_EntityManager(dimensions, player, renderer);

	//Initialise the scroll texture
	scroll = new C_Texture("Assets/Images/scroll.png", renderer);

	//Initialise number of coins text
	numOfCoins = new C_Text(std::to_string(player->getCoins()), "Assets/Font/TheMoment.ttf", 
		(int)(dimensions.y * 0.075f), renderer, 255, 255, 255);

	//Initialise the music
	backgroundMusic = new C_Audio("Assets/Audio/Firebrand.ogg", true);

	//TMP
	health = new C_Text(std::to_string(player->getHealth()), "Assets/Font/TheMoment.ttf", 
		(int)(dimensions.y * 0.075f), renderer, 255, 255, 255);
}

S_Game::~S_Game()
{	
	//Delete pointers
	delete background;

	//Delete entity manager
	delete entityManager;

	//Delete player
	delete player;
	delete playerSprite;

	//Delete scroll texture
	delete scroll;

	//Stop music
	backgroundMusic->stopAudio();
	//Delete audio pointers
	delete backgroundMusic;
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
			case SDLK_m:
				player->increaseCoins();
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
		//TMP Handle Entity Spawning Input
		entityManager->input(incomingEvent);

		//Handle player input
		player->input(incomingEvent, mousePos);
	}
	return true;
}

void S_Game::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startAudio();

	//Update background
	background->update(dt);

	//Update player
	player->update(dt);

	//Update Entity Manager
	entityManager->update(dt);

	//Update coins text
	numOfCoins->setText(std::to_string(player->getCoins()));

	//TMP
	health->setText(std::to_string(player->getHealth()));
}

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);

	//Draw the entity manager
	entityManager->draw();
	
	//Draw the player
	player->draw(renderer);

	//Draw the scroll behind the number of coins
	scroll->pushToScreen(renderer, dimensions * 0.01f, C_Vec2(dimensions.x * 0.25f, dimensions.y * 0.15f));

	//Draw the coin next to the number of coins
	entityManager->getCoinTexture()
		->pushToScreen(renderer, 
		C_Vec2(dimensions.x * 0.045f, dimensions.y * 0.0575f), 
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f));

	//Draw the Number of Coins
	numOfCoins->pushToScreen(C_Vec2(dimensions.x * 0.08f, dimensions.y * 0.05f));

	//TMP
	health->pushToScreen(C_Vec2(dimensions.x * 0.5f, dimensions.y * 0.05f));
}