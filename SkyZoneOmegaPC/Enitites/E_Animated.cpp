#include "E_Animated.h"

E_Animated::E_Animated(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, 
	int animationFrames, C_Vec2 spriteDimensions, float animationLength)
	: E_Entity(sprite, pos, dimensions), animationFrames(animationFrames), 
	spriteDimensions(spriteDimensions), animationTimer(animationLength), spriteIndex(C_Vec2())
{
}

E_Animated::~E_Animated()
{
}

void E_Animated::draw(SDL_Renderer* renderer)
{
	sprite->pushSpriteToScreen(renderer, pos, dimensions, spriteIndex * spriteDimensions, spriteDimensions);
}

void E_Animated::animate(float dt)
{
	//Update the animation
	animationTimer.upadateTimer(dt);

	//check if the timer has finished
	if (animationTimer.checkTimer())
	{
		//change the current sprite of animation
		spriteIndex.x++;
		if (spriteIndex.x > (float)(animationFrames - 1))
		{
			spriteIndex.x = 0.0f;
		}
		//reset the timer
		animationTimer.resetTimer();
	}
}