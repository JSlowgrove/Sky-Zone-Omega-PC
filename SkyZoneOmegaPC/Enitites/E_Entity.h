#pragma once

#include "../Core/C_Texture.h"
#include "../Core/C_Vec2.h"

/**
@brief Contains variables and functions to be inherited by classes that are about Entities.
@author Jamie Slowgrove
*/
class E_Entity
{
public:
	/**
	@brief Constructs the Entity object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Entity.
	@param dimensions The dimensions of the Entity.
	*/
	E_Entity(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

	/**
	@brief Destructs the Entity object.
	*/
	~E_Entity();

	/**
	@brief A pure virtual function that updates the Entity.
	@param dt The delta time.
	*/
	virtual void update(float dt) = 0;

	/**
	@brief A virtual function that draws the Entity to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	virtual void draw(SDL_Renderer* renderer);

	/**
	@brief Sets the position of the Entity.
	@param position The new position of the Entity.
	*/
	void setPosition(C_Vec2 pos);

	/**
	@brief Sets the x position of the Entity.
	@param x The x position of the Entity.
	*/
	void setX(float x);

	/**
	@brief Sets the y position of the Entity.
	@param y The y position of the Entity.
	*/
	void setY(float y);

	/**
	@brief Sets the dimensions of the Entity.
	@param dimensions The new dimensions of the Entity.
	*/
	void setDimensions(C_Vec2 dimensions);

	/**
	@brief Sets the width of the Entity.
	@param width The new width of the Entity.
	*/
	void setWidth(float width);

	/**
	@brief Sets the height of the Entity.
	@param height The new height of the Entity.
	*/
	void setHeight(float height);

	/**
	@brief Gets the position of the Entity.
	@returns The position of the Entity.
	*/
	C_Vec2 getPosition();

	/**
	@brief Gets the dimensions of the Entity.
	@returns The dimensions of the Entity.
	*/
	C_Vec2 getDimensions();

protected:
	///A pointer to the Entity Texture.
	C_Texture* sprite;
	///The position of the Entity.
	C_Vec2 pos;
	///The dimensions of the Entity.
	C_Vec2 dimensions;
};