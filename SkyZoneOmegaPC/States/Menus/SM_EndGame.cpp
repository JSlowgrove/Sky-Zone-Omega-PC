#include "SM_EndGame.h"

SM_EndGame::SM_EndGame(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(backgroundMusic)
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);
}

SM_EndGame::~SM_EndGame()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
	delete universalSpeed;
}

bool SM_EndGame::input()
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

void SM_EndGame::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_EndGame::draw()
{
}