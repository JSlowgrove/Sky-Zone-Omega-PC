#include "SM_MainMenu.h"

SM_MainMenu::SM_MainMenu(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg"))
{
}

SM_MainMenu::~SM_MainMenu()
{
	//Stop music
	backgroundMusic->stopMusic();
	//Delete audio pointers
	delete backgroundMusic;
}

bool SM_MainMenu::input()
{
}

void SM_MainMenu::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
}

void SM_MainMenu::draw()
{
}