#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions), 
	mousePos(C_Vec2()), 
	playerSprite(new C_Texture("Assets/Images/player699x436.png", renderer)),
	playerArcherSprite(new C_Texture("Assets/Images/tmp.png", renderer)),//tmp
	scoreScroll(new C_Texture("Assets/Images/scoreScroll.png", renderer)),
	healthScroll(new C_Texture("Assets/Images/healthScroll.png", renderer)),
	backgroundMusic(backgroundMusic),
	numOfCoins(new C_Text("", "Assets/Font/MonogramsToolbox.ttf", (int)(dimensions.y * 0.04f), renderer, 255, 255, 255)),
	minFireTint({ (Uint8)255, (Uint8)0, (Uint8)0 }),
	maxFireTint({ (Uint8)255, (Uint8)255, (Uint8)0 }),
	fireSprite(new C_Texture("Assets/Images/fireParticle.png", renderer))
{
	//Initialise random seed
	srand((unsigned int)time(NULL));

	//Initialise universal speed
	universalSpeed = new float(1.0f);

	//Initialise backgrounds
	background = new B_BackgroundManager(renderer, dimensions, universalSpeed);

	//Initialise player
	player = new EP_Player(playerSprite, C_Vec2(dimensions.x * 0.1f, dimensions.y * 0.4f), dimensions * 0.125f, 
		playerArcherSprite, C_Vec2(dimensions.x * 0.1125f, dimensions.y * 0.38f), 
		C_Vec2(dimensions.y * 0.0625f, dimensions.y * 0.09375f), dimensions, fireSprite, 
		minFireTint, maxFireTint, universalSpeed);

	//Initialise entity manager
	entityManager = new E_EntityManager(dimensions, player, renderer, fireSprite, minFireTint, maxFireTint, universalSpeed);

	//Initialise gameplay
	gameplay = new G_Gameplay(dimensions, player, entityManager, universalSpeed);
}

S_Game::~S_Game()
{	
	//Delete pointers
	delete background;
	delete gameplay;
	delete entityManager;
	delete player;
	delete playerSprite;
	delete scoreScroll;
	delete healthScroll;
	delete universalSpeed;
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
			case SDLK_ESCAPE: //If Escape is pressed, go back to the main menu

				//Go to the help state
				stateManager->addState(new SM_Help(stateManager, renderer, dimensions, backgroundMusic));
				break;

				//TMP
			case SDLK_i:
				player->increaseCoins();
				break;
			case SDLK_m:
				backgroundMusic->muteMusic();
				break;
			case SDLK_u:
				backgroundMusic->unmuteMusic();
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
	//Keep the music playing
	backgroundMusic->startMusic();

	//Update background
	background->update(dt);

	//Update player
	player->update(dt);

	//Update Entity Manager
	entityManager->update(dt);

	//Update Gameplay
	gameplay->update(dt);

	//Update coins text
	numOfCoins->setText(std::to_string(player->getCoins()));

	//If the game is over go to end game
	if (player->getHealth() <= 0)
	{
		//Go to the end game state
		stateManager->addState(new SM_EndGame(stateManager, renderer, dimensions, backgroundMusic, player->getCoins()));
		resetGame();
	}
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
	entityManager->getTexture("EPU_Coin")
		->pushToScreen(renderer, 
		C_Vec2(dimensions.x * 0.045f, dimensions.y * 0.022f), 
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
	entityManager->getTexture("EPU_Health")->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.52f, dimensions.y * 0.022f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthOneSprite, C_Vec2(300, 299));
	entityManager->getTexture("EPU_Health")->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.56f, dimensions.y * 0.022f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthTwoSprite, C_Vec2(300, 299));
	entityManager->getTexture("EPU_Health")->pushSpriteToScreen(renderer,
		C_Vec2(dimensions.x * 0.6f, dimensions.y * 0.022f),
		C_Vec2(dimensions.y * 0.05f, dimensions.y * 0.05f), healthThreeSprite, C_Vec2(300, 299));
}

void S_Game::resetGame()
{
	//Reset universal speed
	*universalSpeed = 1.0f;
	
	//Reset player
	player = new EP_Player(playerSprite, C_Vec2(dimensions.x * 0.1f, dimensions.y * 0.4f), dimensions * 0.125f,
		playerArcherSprite, C_Vec2(dimensions.x * 0.1125f, dimensions.y * 0.38f),
		C_Vec2(dimensions.y * 0.0625f, dimensions.y * 0.09375f), dimensions, fireSprite,
		minFireTint, maxFireTint, universalSpeed);

	//Reset entity manager
	entityManager = new E_EntityManager(dimensions, player, renderer, fireSprite, minFireTint, maxFireTint, universalSpeed);

	//Reset gameplay
	gameplay = new G_Gameplay(dimensions, player, entityManager, universalSpeed);
}