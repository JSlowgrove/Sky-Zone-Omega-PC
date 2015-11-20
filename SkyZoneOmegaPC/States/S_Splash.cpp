#include "S_Splash.h"

S_Splash::S_Splash(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(backgroundMusic),
	splash(new C_Texture("Assets/Images/splash.png", renderer)),
	splashTimer(new C_Timer(1.0f))
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);
}

S_Splash::~S_Splash()
{
	//Delete pointers
	delete universalSpeed;
	delete splash;
}

bool S_Splash::input()
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
		}
	}
	return true;
}

void S_Splash::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
	//Update the timer
	splashTimer->upadateTimer(dt);

	//exit the splash screen if the timer is up
	if (splashTimer->checkTimer())
	{
		stateManager->addState(new SM_MainMenu(stateManager, renderer, dimensions, backgroundMusic));
		return;
	}
}

void S_Splash::draw()
{
	//draw the image
	splash->pushToScreen(
		renderer, 
		C_Vec2((dimensions.x * 0.5f) - (dimensions.y * 0.375f), dimensions.y * 0.125f),
		C_Vec2(dimensions.y * 0.75f, dimensions.y * 0.75f)
		);
}