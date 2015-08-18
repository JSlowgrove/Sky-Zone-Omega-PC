#pragma once

#include "EB_Entity.h"
#include "../../Core/C_Vec2.h"
#include "../../Core/C_Timer.h"

/**
@brief An Entity that uses a spritesheet for animation.
@author Jamie Slowgrove
*/
class EB_Animated : public EB_Entity
{
public:
	/**
	@brief Constructs the Animated Entity.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	@param animationFrames The number of animation frames in the spritesheet.
	@param spriteDimensions The dimensions of the sprite.
	@param animationLength The length of each animation frame.
	@param iD The ID of the Entity type.
	*/
	EB_Animated(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, int animationFrames, 
		C_Vec2 spriteDimensions, float animationLength, std::string iD);

	/**
	@brief Destructs the Animated Entity object.
	*/
	~EB_Animated();

	/**
	@brief A pure virtual function that updates the Entity.
	@param dt The delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	@brief Draws the StormCloud to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

protected:
	///The number of animation frames in the spritesheet
	int animationFrames;
	///The dimensions of the sprite in the spritesheet.
	C_Vec2 spriteDimensions;
	///The index of the current sprite in the spritesheet.
	C_Vec2 spriteIndex;
	///The animation timer.
	C_Timer animationTimer;

	/**
	@brief A virtual function that animates the sprite.
	@param dt The delta time.
	*/
	virtual void animate(float dt);
};