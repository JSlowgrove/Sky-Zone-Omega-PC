#pragma once

#include <SDL.h>
#include <vector>
#include <time.h>
#include <string>
#include "PS_Particle.h"
#include "../Core/C_Vec2.h"
#include "../Core/C_Utilities.h"

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
	@param objectName The file name of the texture that the Particle will use.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param renderer A pointer to the renderer.
	@param moveSpeed The speed of the particle effect movement.
	*/
	PS_ParticleEffect(std::string fileName, C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed);

	/**
	@brief Constructs the ParticleEffect Object.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param renderer A pointer to the renderer.
	@param moveSpeed The speed of the particle effect movement.
	@param r The red value (0-255).
	@param g The green value (0-255).
	@param b The blue value (0-255).
	*/
	PS_ParticleEffect(C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed, int r, int g, int b);

	/**
	@brief Constructs the ParticleEffect Object.
	@param emitter The position that the particle effect emits from.
	@param emit The new value of the emit boolean.
	@param renderer A pointer to the renderer.
	@param moveSpeed The speed of the particle effect movement.
	@param colour The colour of the Particle.
	*/
	PS_ParticleEffect(C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed, SDL_Colour colour);

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

	/**
	@brief Creates the new Particle objects.
	*/
	void makeNewParticles();
};
