#include "S_State.h"

S_State::S_State(S_StateManager * stateManager, SDL_Renderer* renderer, C_Vec2 dimensions)
	: stateManager(stateManager), renderer(renderer), dimensions(dimensions)
{
}

S_State::~S_State()
{
}