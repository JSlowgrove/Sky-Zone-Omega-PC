#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions)
{
	//Initialise the background
	background = new B_BackgroundManager(renderer, dimensions);

	//tmp
	cloud = new C_Texture("Assets/Images/clouds.png", renderer);
	clouds = new B_Background(cloud, C_Vec2(), dimensions, -200.0f);
}

S_Game::~S_Game()
{	
	//Delete pointers
	delete background;

	//tmp
	delete cloud;
	delete clouds;
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
		}
	}
	return true;
}

void S_Game::update(float dt)
{
	//Update background
	background->update(dt);

	//tmp
	clouds->update(dt);
}

void S_Game::draw()
{
	//Draw background
	background->draw(renderer);

	//tmp
	clouds->draw(renderer);
}