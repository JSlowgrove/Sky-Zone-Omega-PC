#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions), 
	mousePos(C_Vec2()), 
	background(new B_BackgroundManager(renderer, dimensions)),
	playerSprite(new C_Texture("Assets/Images/player699x436.png", renderer)), 
	scoreScroll(new C_Texture("Assets/Images/scoreScroll.png", renderer)),
	healthScroll(new C_Texture("Assets/Images/healthScroll.png", renderer)),
	backgroundMusic(new C_Audio("Assets/Audio/Firebrand.ogg", true)),
	numOfCoins(new C_Text("", "Assets/Font/TheMoment.ttf",(int)(dimensions.y * 0.06f), renderer, 255, 255, 255))
{
	//Initialise random seed
	srand((unsigned int)time(NULL));

	//Initialise player
	player = new E_Player(playerSprite, C_Vec2(dimensions.x * 0.1f, dimensions.y * 0.4f), dimensions * 0.2f, dimensions);

	//Initialise entity manager
	entityManager = new E_EntityManager(dimensions, player, renderer);
}

S_Game::~S_Game()
{	
	//Stop music
	backgroundMusic->stopAudio();
	//Delete audio pointers
	delete backgroundMusic;
	//Delete pointers
	delete background;
	delete entityManager;
	delete player;
	delete playerSprite;
	delete scoreScroll;
	delete healthScroll;
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
}

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);

	//Draw the entity manager
	entityManager->draw();
	
	//Draw the player
	player->draw(renderer);

	//Draw the scroll behind the number of coins and player health
	scoreScroll->pushToScreen(renderer, 
		dimensions * 0.01f, C_Vec2(dimensions.x * 0.25f, dimensions.y * 0.075f));
	healthScroll->pushToScreen(renderer, 
		C_Vec2(dimensions.x * 0.50f, dimensions.y * 0.01f), C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.075f));

	//Draw the coin next to the number of coins
	entityManager->getCoinTexture()
		->pushToScreen(renderer, 
		C_Vec2(dimensions.x * 0.045f, dimensions.y * 0.02f), 
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f));

	//Draw the Number of Coins
	numOfCoins->pushToScreen(C_Vec2(dimensions.x * 0.08f, dimensions.y * 0.022f));

	//Work out the health sprites to display from the player health
	C_Vec2 healthOneSprite(0, 0), healthTwoSprite(0, 0), healthThreeSprite(0, 0);
	switch (player->getHealth())
	{
	case 0:
		healthOneSprite = C_Vec2(300, 0);
		healthTwoSprite = C_Vec2(300, 0);
		healthThreeSprite = C_Vec2(300, 0);
		break;
	case 1:
		healthTwoSprite = C_Vec2(300, 0);
		healthThreeSprite = C_Vec2(300, 0);
		break;
	case 2:
		healthThreeSprite = C_Vec2(300, 0);
		break;
	}

	//Draw the player health
	entityManager->getHealthTexture()->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.53f, dimensions.y * 0.021f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthOneSprite, C_Vec2(300, 299));
	entityManager->getHealthTexture()->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.565f, dimensions.y * 0.0235f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthTwoSprite, C_Vec2(300, 299));
	entityManager->getHealthTexture()->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.6f, dimensions.y * 0.026f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthThreeSprite, C_Vec2(300, 299));
}