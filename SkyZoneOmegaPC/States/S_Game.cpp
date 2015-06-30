#include "S_Game.h"

S_Game::S_Game(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions)
{
	//Initialise the background textures
	background[0] = new C_Texture("Assets/Images/bottomBackground.png", renderer);
	background[1] = new C_Texture("Assets/Images/middleBackground.png", renderer);
	background[2] = new C_Texture("Assets/Images/topBackground.png", renderer);

	//Initialise the background layers
	bottomBackgroundLayer = new E_Background(background[0], C_Vec2(), dimensions, 0.0f);
	middleBackgroundLayer[0] = new E_Background(background[1], C_Vec2(), dimensions, -100.0f);
	middleBackgroundLayer[1] = new E_Background(background[1], C_Vec2(dimensions.x, 0.0f), dimensions, -100.0f);
	topBackgroundLayer[0] = new E_Background(background[2], C_Vec2(), dimensions, -150.0f);
	topBackgroundLayer[1] = new E_Background(background[2], C_Vec2(dimensions.x, 0.0f), dimensions, -150.0f);

	//tmp
	cloud = new C_Texture("Assets/Images/clouds.png", renderer);
	clouds = new E_Background(cloud, C_Vec2(), dimensions, -200.0f);
}

S_Game::~S_Game()
{	
	//Delete pointers
	for (auto image : background)
	{
		delete image;
	}
	delete bottomBackgroundLayer;
	for (auto layer : middleBackgroundLayer)
	{
		delete layer;
	}
	for (auto layer : topBackgroundLayer)
	{
		delete layer;
	}

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
	//Update backgrounds
	for (auto layer : middleBackgroundLayer)
	{
		layer->update(dt);
	}
	for (auto layer : topBackgroundLayer)
	{
		layer->update(dt);
	}

	//tmp
	clouds->update(dt);
}

void S_Game::draw()
{
	//Draw backgrounds to screen
	bottomBackgroundLayer->draw(renderer);
	for (auto layer : middleBackgroundLayer)
	{
		layer->draw(renderer);
	}
	for (auto layer : topBackgroundLayer)
	{
		layer->draw(renderer);
	}

	//tmp
	clouds->draw(renderer);
}