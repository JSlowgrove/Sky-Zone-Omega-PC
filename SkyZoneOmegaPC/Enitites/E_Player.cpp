#include "E_Player.h"

E_Player::E_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions)
	: E_Entity(sprite, pos, dimensions), screenDimensions(screenDimensions), pressed(false), 
	spriteDimensions(C_Vec2(386, 242)), animationTimer(0.05f), spriteIndex(C_Vec2())
{
}

E_Player::~E_Player()
{
}

void E_Player::update(float dt)
{
	//Update the animation
	animate(dt);

	//Make sure that the player is on the screen
	if (pos.x + dimensions.x > screenDimensions.x)
	{
		pos.x = screenDimensions.x - dimensions.x;
	}
	if (pos.x < 0.0f)
	{
		pos.x = 0.0f;
	}
	if (pos.y + dimensions.y > screenDimensions.y)
	{
		pos.y = screenDimensions.y - dimensions.y;
	}
	if (pos.y < 0.0f)
	{
		pos.y = 0.0f;
	}
}

void E_Player::input(SDL_Event& incomingEvent, C_Vec2 mousePos)
{
	switch (incomingEvent.type)
	{
	case SDL_MOUSEBUTTONDOWN: //If a mouse button is pressed

		//Left Mouse Button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			//Test if the mouse is over the player
			if (mousePos.x >= pos.x && mousePos.x < pos.x + dimensions.x
				&& mousePos.y >= pos.y && mousePos.y < pos.y + dimensions.x)
			{
				pressed = true;
				//set the offset for making the player be attached to where the player was pressed
				offset = mousePos - pos;
			}	
			else
			{
				pressed = false;
			}
		}
		break;

	case SDL_MOUSEBUTTONUP: //If a mouse button is released

		//Left Mouse Button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
				pressed = false;
		}
		break;
	}

	if (pressed)
	{
		//set the player position to the mouse pos using the pressed offset for the mouse position on the player
		pos = mousePos - offset;
	}	
}

void E_Player::draw(SDL_Renderer* renderer)
{
	sprite->pushSpriteToScreen(renderer, pos, dimensions, spriteIndex * spriteDimensions, spriteDimensions);
}

void E_Player::animate(float dt)
{
	//Update the animation
	animationTimer.upadateTimer(dt);

	//check if the timer has finished
	if (animationTimer.checkTimer())
	{
		//change the current sprite of animation
		spriteIndex.x++;
		if (spriteIndex.x > 4.0f)
		{
			spriteIndex.x = 0.0f;
		}
		//reset the timer
		animationTimer.resetTimer();
	}
}