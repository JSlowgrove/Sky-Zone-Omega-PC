#include "SM_Credits.h"

SM_Credits::SM_Credits(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg"))
{
}

SM_Credits::~SM_Credits()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
}

bool SM_Credits::input()
{
}

void SM_Credits::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_Credits::draw()
{
}