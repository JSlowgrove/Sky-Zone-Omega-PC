#include "SM_Scores.h"

SM_Scores::SM_Scores(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg"))
{
}

SM_Scores::~SM_Scores()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
}

bool SM_Scores::input()
{
}

void SM_Scores::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_Scores::draw()
{
}