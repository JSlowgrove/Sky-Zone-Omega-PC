#pragma once

#include <SDL.h>
#include "E_Animated.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Timer.h"
#include "../Core/C_Utilities.h"

/**
@brief Contains the data and functions for the player.
@author Jamie Slowgrove
*/
class E_Player : public E_Animated
{
public:
	/**
	@brief Constructs the Player object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Player.
	@param dimensions The dimensions of the Player.
	@param screenDimensions The dimensions of the screen.
	*/
	E_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions);

	/**
	@brief Destructs the Player object.
	*/
	~E_Player();

	/**
	@brief A function that updates the Player.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief A function that handles the Player input.
	@param incomingEvent A reference to the incoming SDL event.
	@param mousePos the position of the mouse.
	*/
	void input(SDL_Event& incomingEvent, C_Vec2 mousePos);

	/**
	@brief A function that increases the Player health by 1.
	*/
	void increaseHealth();

	/**
	@brief A function that decreases the Player health by 1.
	*/
	void decreaseHealth();

	/**
	@brief Returns the health of the Player.
	@returns The Player health.
	*/
	int getHealth();

	/**
	@brief A function that increases the Player coins by 1.
	*/
	void increaseCoins();

	/**
	@brief Returns the number coins of the Player.
	@returns The Player coins.
	*/
	int getCoins();

	/**
	@brief A function to test if the player has collided with an Entity.
	@param entityPos The position of the Entity.
	@param entityDimensions The dimensions of the Entity.
	@return True if there is a collision.
	*/
	bool entityCollisionTest(C_Vec2 entityPos, C_Vec2 entityDimensions);

private:
	///The user commands for the Player.
	bool pressed;
	///An offset for the position of the player from the position the player was pressed.
	C_Vec2 offset;
	///The screen Dimensions.
	C_Vec2 screenDimensions;
	///The health of the player.
	int health;
	///The max health of the player.
	int maxHealth;
	///The current number of coins of the player.
	int coins;
	/**The maximum number of coins that the player can get.
	This is mainly to make sure that the number does not leave its boundaries on the screen*/
	int maxCoins;
};