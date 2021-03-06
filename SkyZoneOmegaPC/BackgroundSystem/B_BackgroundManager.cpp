#include "B_BackgroundManager.h"

B_BackgroundManager::B_BackgroundManager(SDL_Renderer* renderer, C_Vec2 dimensions, float* universalSpeed)
{
	//Initialise the background textures
	background[0] = new C_Texture("Assets/Images/bottomBackground.png", renderer);
	background[1] = new C_Texture("Assets/Images/middleBackground.png", renderer);
	background[2] = new C_Texture("Assets/Images/topBackground.png", renderer);

	//Initialise the background layers
	bottomBackgroundLayer = new B_Background(background[0], C_Vec2(), dimensions, C_Vec2(), universalSpeed);
	middleBackgroundLayer[0] = new B_Background(background[1], C_Vec2(), dimensions, C_Vec2(-400.0f, 0.0f), universalSpeed);
	middleBackgroundLayer[1] = new B_Background(background[1], C_Vec2(dimensions.x, 0.0f), dimensions, C_Vec2(-400.0f, 0.0f), universalSpeed);
	topBackgroundLayer[0] = new B_Background(background[2], C_Vec2(), dimensions, C_Vec2(-750.0f, 0.0f), universalSpeed);
	topBackgroundLayer[1] = new B_Background(background[2], C_Vec2(dimensions.x, 0.0f), dimensions, C_Vec2(-750.0f, 0.0f), universalSpeed);
}

B_BackgroundManager::~B_BackgroundManager()
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
}

void B_BackgroundManager::update(float dt)
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
}

void B_BackgroundManager::draw(SDL_Renderer* renderer)
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
}