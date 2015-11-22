#pragma once

#include <SDL.h>
#include "../Base/EB_Animated.h"
#include "EP_PlayerArcher.h"
#include "../../Core/C_Vec2.h"
#include "../../Core/C_Timer.h"
#include "../../Core/C_Utilities.h"
#include "../../Core/C_Audio.h"
#include "../../ParticleSystem/PS_ParticleEffect.h"

/**
@brief Contains the data and functions for the player.
@author Jamie Slowgrove
*/
class EP_Player : public EB_Animated
{
public:
	/**
	@brief Constructs the Player object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Player.
	@param dimensions The dimensions of the Player.
	@param archerSprite A pointer to the Player Archer Texture.
	@param archerPos The position of the Player Archer.
	@param archerDimensions The dimensions of the Player Archer.
	@param screenDimensions The dimensions of the screen.
	@param fireSprite A pointer to the particles Texture.
	@param minTint The minimum tint for the fire particles.
	@param maxTint The maximum tint for the fire particles.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	EP_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Texture* archerSprite, C_Vec2 archerPos,
		C_Vec2 archerDimensions, C_Vec2 screenDimensions, C_Texture* fireSprite, SDL_Colour minTint, 
		SDL_Colour maxTint, float* universalSpeed);

	/**
	@brief Destructs the Player object.
	*/
	~EP_Player();

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
	@brief A function that draws the Player to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void draw(SDL_Renderer* renderer);

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

	/**
	@brief Sets the value of the archer fireArrow boolean.
	@param coinSpawn The new value of fireArrow.
	*/
	void setFireArrow(bool fireArrow);

	/**
	@brief Gets the value of the archer fireArrow boolean.
	@returns The value of fireArrow.
	*/
	bool getFireArrow();

	/**
	@brief Sets the value of the archer firing boolean.
	@param coinSpawn The new value of firing.
	*/
	void setFiring(bool firing);

	/**
	@brief Gets the value of the archer firing boolean.
	@returns The value of firing.
	*/
	bool getFiring();

	/**
	@brief Sets the value of the flamingPowerUp boolean.
	@param flamingPowerUp The new value of flamingPowerUp.
	*/
	void setFlaming(bool flamingPowerUp);

	/**
	@brief Gets the value of the flamingPowerUp boolean.
	@returns The value of flamingPowerUp.
	*/
	bool getFlaming();

	/**
	@brief Sets the value of the timeSlowPowerUp boolean.
	@param flamingPowerUp The new value of timeSlowPowerUp.
	*/
	void setTimeSlow(bool timeSlowPowerUp);

	/**
	@brief Gets the value of the timeSlowPowerUp boolean.
	@returns The value of timeSlowPowerUp.
	*/
	bool getTimeSlow();

	/**
	@brief Activates the Player shield.
	*/
	void activateShield();

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
	///The Player Archer
	EP_PlayerArcher* archer;
	///An offset for the position of the player archer from the position the player.
	C_Vec2 archerOffset;
	///A boolean for if the player has the flaming power up active.
	bool flamingPowerUp;
	///The flamingPowerUp timer.
	C_Timer flamingPowerUpTimer;
	///The fire particle effect.
	PS_ParticleEffect* fireEffect;
	///An offset for the position of the fire effect from the position the player.
	C_Vec2 fireEffectOffset;
	///A bool for if the Player shield is active
	bool shield;
	///The array of hit audio.
	C_Audio* healthLossSounds[3];
	///The shield loss audio
	C_Audio* shieldLossSound;
	///A boolean for if the player has the time slow power up active.
	bool timeSlowPowerUp;
	///The timeSlowPowerUp timer.
	C_Timer timeSlowPowerUpTimer;
};