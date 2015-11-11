#include "SM_Help.h"

SM_Help::SM_Help(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg"))
{
}

SM_Help::~SM_Help()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
}

bool SM_Help::input()
{
}

void SM_Help::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_Help::draw()
{
}