#pragma once

#include <SDL.h>
#include "../Core/C_Vec2.h"
#include "../Core/C_Texture.h"

/**
@brief A Particle object for use with the Particle System.
@author Jamie Slowgrove
*/
class PS_Particle
{
public:
	/**
	@brief Constructs the Particle Object.
	@param square A pointer to the Texture.
	@param scaleValue The scale of the Particle.
	@param direction The direction of the Particle.
	@param moveSpeed The move speed of the Particle.
	@param pos The position of the Particle.
	*/
	PS_Particle(C_Texture* texture, float scaleValue, C_Vec2 direction, float moveSpeed, C_Vec2 pos);

	/**
	@brief Constructs the Particle Object.
	@param square A pointer to the Texture.
	@param scaleValue The scale of the Particle.
	@param direction The direction of the Particle.
	@param moveSpeed The move speed of the Particle.
	@param pos The position of the Particle.
	@param tintColour The tint colour of the Particle.
	*/
	PS_Particle(C_Texture* texture, float scaleValue, C_Vec2 direction, float moveSpeed, 
		C_Vec2 pos, SDL_Colour tintColour);

	/**
	@brief Destructs the Particle Object deleting the Particle Object from memory.
	*/
	~PS_Particle();

	/**
	@brief A function that updates the Particle.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Draw the Entity to the screen.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	@brief Move the Particle.
	@param movement The amount to move by.
	*/
	void move(C_Vec2 movement);

	/**
	@brief Sets the position of the Particle.
	@param pos The new position.
	*/
	void setPosition(C_Vec2 pos);

	/**
	@brief Sets the scale of the Particle.
	@param scaleValue The new scale.
	*/
	void setScale(float scaleValue);

	/**
	@brief Sets the moveSpeed of the Particle.
	@param moveSpeed The new moveSpeed.
	*/
	void setMoveSpeed(float moveSpeed);

	/**
	@brief Sets the direction of the Particle.
	@param direction The new direction.
	*/
	void setDirection(C_Vec2 direction);

	/**
	@brief Gets the moveSpeed of the Particle.
	@returns The moveSpeed.
	*/
	float getMoveSpeed();

	/**
	@brief Gets the position of the Particle.
	@returns The position of the Particle.
	*/
	C_Vec2 getPosition();

	/**
	@brief Gets the direction of the Particle.
	@returns The direction of the Particle.
	*/
	C_Vec2 getDirection();

	/**
	@brief Gets the scale of the Particle.
	@returns The scale of the Particle.
	*/
	float getScale();

private:
	///A pointer to the Texture.
	C_Texture* texture;
	///The direction of the Particle.
	C_Vec2 direction;
	///The Position of the Particle.
	C_Vec2 pos;
	///The scale of the Particle.
	float scaleValue;
	///The movement speed of the Particle.
	float moveSpeed;
	///A boolean for if the Particle should be tinted.
	bool tint;
	///The Tint colour of the Particle.
	SDL_Colour tintColour;
};
