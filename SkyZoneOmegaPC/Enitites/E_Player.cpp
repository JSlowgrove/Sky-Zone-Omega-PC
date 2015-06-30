#include "E_Player.h"

E_Player::E_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions)
	: E_Velocity(sprite, pos, dimensions, C_Vec2()), screenDimensions(screenDimensions), 
	up(false), down(false), left(false), right(false)
{
}

E_Player::~E_Player()
{
}

void E_Player::update(float dt)
{
	//Reset the velocities to 0
	velocities = C_Vec2();

	//If up is true set the velocity to go up the screen
	if (up)
	{
		velocities.y = -200.0f;
	}
	//If down is true set the velocity to go down the screen
	if (down)
	{
		velocities.y = 200.0f;
	}
	//If left is true set the velocity to go left along the screen
	if (left)
	{
		velocities.x = -200.0f;
	}
	//If right is true set the velocity to go right along the screen
	if (right)
	{
		velocities.x = 200.0f;
	}

	//Work out the next position
	C_Vec2 nextPos = pos + (velocities * dt);

	//Check that the player is still on the screen in the x axis
	if (nextPos.x >= (screenDimensions.x - dimensions.x) || nextPos.x <= 0.0f)
	{
		//Reset the x velocity
		velocities.x = 0.0f;
	}

	//Check that the player is still on the screen in the y axis
	if (nextPos.y >= (screenDimensions.y - dimensions.y) || nextPos.y <= 0.0f)
	{
		//Reset the y velocity
		velocities.y = 0.0f;
	}

	//update the position of the player
	updatePosWithVelocities(dt);
}

void E_Player::input(SDL_Event& incomingEvent)
{
	switch (incomingEvent.type)
	{
	case SDL_KEYDOWN:

		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_w: //If W/Up is pressed, set the up command to true
		case SDLK_UP:

			up = true;
			break;

		case SDLK_s: //If S/Down is pressed, set the down command to true
		case SDLK_DOWN:

			down = true;
			break;

		case SDLK_a: //If A/Left is pressed, set the left command to true
		case SDLK_LEFT:

			left = true;
			break;

		case SDLK_d: //If D/Right is pressed, set the right command to true
		case SDLK_RIGHT:

			right = true;
			break;
		}
		break;

	case SDL_KEYUP:

		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_w: //If W/Up is released, set the up command to false
		case SDLK_UP:

			up = false;
			break;

		case SDLK_s: //If S/Down is released, set the down command to false
		case SDLK_DOWN:

			down = false;
			break;

		case SDLK_a: //If A/Left is released, set the left command to false
		case SDLK_LEFT:

			left = false;
			break;

		case SDLK_d: //If D/Right is released, set the right command to false
		case SDLK_RIGHT:

			right = false;
			break;
		}
		break;
	}
}