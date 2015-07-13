#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions)
{
	//Initialise the background
	background = new B_BackgroundManager(renderer, dimensions);

	//Initialise player
	playerSprite = new C_Texture("Assets/Images/player.png", renderer);
	player = new E_Player(playerSprite, C_Vec2(100.0f, 100.0f), dimensions * 0.2f, dimensions);
}

S_Game::~S_Game()
{	
	//Delete pointers
	delete background;
	delete player;
	delete playerSprite;
}

bool S_Game::input()
{
	C_Vec2 mousePos = C_Vec2();
	//Check for user input
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		//set the mouse position
		mousePos.x = ((float)incomingEvent.motion.x);
		mousePos.y = ((float)incomingEvent.motion.y);

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
}

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);
	//Draw the player
	player->draw(renderer);
}