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
	playerSprite = new C_Texture("Assets/Images/Player699x436.png", renderer);
	player = new E_Player(playerSprite, C_Vec2(100.0f, 100.0f), dimensions * 0.2f, dimensions);

	//Initialise entity manager
	entityManager = new E_EntityManager(dimensions, player, renderer);
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
	//Update background
	background->update(dt);

	//Update player
	player->update(dt);

	//Update Entity Manager
	entityManager->update(dt);
}

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);

	//Draw the entity manager
	entityManager->draw();
	
	//Draw the player
	player->draw(renderer);
}