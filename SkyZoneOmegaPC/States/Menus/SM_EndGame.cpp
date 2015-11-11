#include "SM_EndGame.h"

SM_EndGame::SM_EndGame(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg"))
{
}

SM_EndGame::~SM_EndGame()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
}

bool SM_EndGame::input()
{
}

void SM_EndGame::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_EndGame::draw()
{
}