#pragma once

#include <SDL.h>
#include "E_Animated.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Timer.h"

/**
@brief Contains the data and functions for the Player Archer.
@author Jamie Slowgrove
*/
class E_PlayerArcher : public E_Animated
{
public:
	/**
	@brief Constructs the Player Archer object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Player Archer.
	@param dimensions The dimensions of the Player Archer.
	*/
	E_PlayerArcher(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions);

	/**
	@brief Destructs the Player Archer object.
	*/
	~E_PlayerArcher();

	/**
	@brief A function that updates the Player Archer.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Sets the value of the fireArrow boolean.
	@param coinSpawn The new value of fireArrow.
	*/
	void setFireArrow(bool fireArrow);

	/**
	@brief Gets the value of the fireArrow boolean.
	@returns The value of fireArrow.
	*/
	bool getFireArrow();

	/**
	@brief Sets the value of the firing boolean.
	@param coinSpawn The new value of firing.
	*/
	void setFiring(bool firing);

	/**
	@brief Gets the value of the firing boolean.
	@returns The value of firing.
	*/
	bool getFiring();

private:
	///A boolean for if the Player Archer should fire an arrow.
	bool fireArrow;
	///A boolean for if the Player Archer is firing an arrow.
	bool firing;

	/**
	@brief Animates the sprite of the Archer.
	@param dt The delta time.
	*/
	void animate(float dt);
};