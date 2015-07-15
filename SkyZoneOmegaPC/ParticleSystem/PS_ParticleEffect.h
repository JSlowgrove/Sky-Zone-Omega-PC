#pragma once

#include <SDL.h>
#include <vector>
#include <time.h>
#include <string>
#include "PS_Particle.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Utilities.h"
#include "../Core/C_Timer.h"

///A definition for the max number of particles.
#define MAX_NUMBER_OF_PARTICLES 100

/**
@brief Handles Particle objects and Particle Effect functions.
@author Jamie Slowgrove
*/
class PS_ParticleEffect
{
public:
	/**
	@brief Constructs the ParticleEffect Object.
	@param texture A pointer to the particle texture.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param moveSpeed The speed of the particle effect movement.
	@param scale The scale of the particles.
	*/
	PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale);

	/**
	@brief Constructs the ParticleEffect Object.
	@param texture A pointer to the particle texture.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param moveSpeed The speed of the particle effect movement.
	@param scale The scale of the particles.
	@param timerLength The length of the lifespan timer for the particle effect.
	*/
	PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale, float timerLength);

	/**
	@brief Destructs the ParticleEffect Object deleting the Particle Object from memory.
	*/
	~PS_ParticleEffect();

	/**
	@brief A function that updates the ParticleEffect.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	@brief Draws the ParticleEffect.
	@param renderer A pointer to the renderer.
	*/
	void draw(SDL_Renderer* renderer);

	/**
	@brief Set the position of the emitter.
	@param emitter The new position of the emitter.
	*/
	void setEmitter(C_Vec2 emitter);

	/**
	@brief Set the value of the emit boolean.
	@param emit The new value of the emit boolean.
	*/
	void setEmitting(bool emit);

	/**
	@brief Set the value of the movement speed.
	@param moveSpeed The new value of the movement speed.
	*/
	void setMoveSpeed(float moveSpeed);

	/**
	@brief Set the scale of the particles.
	@param scale The scale of the particle.
	*/
	void setParticleScale(float scale);

	/**
	@brief Get the timer for the lifespan of the effect.
	@returns A pointer to the timer of the particle effect.
	*/
	C_Timer* getLifeSpan();

	/**
	@brief Set the value of dead.
	@param dead The value of dead.
	*/
	void setDead(bool dead);

	/**
	@brief Get the value of dead.
	@returns If the particle effect is dead.
	*/
	bool getDead();

private:
	///A vector of Particle objects.
	std::vector<PS_Particle*> particles;
	///A pointer to the Texture of the particles.
	C_Texture* texture;
	///The move speed of the particles.
	float moveSpeed;
	///The position of the Particle emitter.
	C_Vec2 emitter;
	///A boolean for if the ParticleEffect should emit.
	bool emit;
	///The scale of the particles.
	float scale;
	///A timer for the lifespan of the particle effect.
	C_Timer* lifeSpan;
	///A boolean for if the particle effect should be deleted.
	bool dead;

	/**
	@brief Creates the new Particle objects.
	*/
	void makeNewParticles();
};
