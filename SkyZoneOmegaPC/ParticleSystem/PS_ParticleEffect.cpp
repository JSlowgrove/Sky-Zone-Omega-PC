#include "PS_ParticleEffect.h"

PS_ParticleEffect::PS_ParticleEffect(std::string fileName, C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit)
{
	//Initialize random seed
	srand((unsigned int)time(NULL));
	
	//Initialise the texture
	texture = new C_Texture(fileName, renderer);

	//Generate the new particles
	makeNewParticles();
}


PS_ParticleEffect::PS_ParticleEffect(C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed, int r, int g, int b)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit)
{
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*initialise the texture*/
	texture = new C_Texture(renderer, r, g, b);

	/*generate the new particles*/
	makeNewParticles();
}

PS_ParticleEffect::PS_ParticleEffect(C_Vec2 emitter, bool emit, SDL_Renderer* renderer, float moveSpeed, SDL_Colour colour)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit)
{
	/*initialize random seed: */
	srand((unsigned int)time(NULL));

	/*initialise the texture*/
	texture = new C_Texture(renderer, colour);

	/*generate the new particles*/
	makeNewParticles();
}

PS_ParticleEffect::~PS_ParticleEffect()
{
	/*delete pointers*/
	for (auto particle : particles)
	{
		delete particle;
	}
}

void PS_ParticleEffect::update(float dt)
{
	//Generate the new particles
	makeNewParticles();

	//Update the particles
	for (auto particle : particles)
	{
		particle->update(dt);
	}

	//If the particle should emit:
	if (emit)
	{
		//While the number of particles is greater than the max number of particles.
		while (particles.size() > MAX_NUMBER_OF_PARTICLES)
		{
			//delete pointer
			delete particles[0];
			//Erase the oldest particle
			particles.erase(particles.begin());
		}
	}
	//If the particle should not emit:
	else
	{
		//Make sure there is at least 1 particle left
		if (particles.size() > 0)
		{
			//Delete pointer
			delete particles[0];
			//Erase the oldest particle
			particles.erase(particles.begin());
		}
	}
}

void PS_ParticleEffect::draw(SDL_Renderer* renderer)
{
	//Draw all of the particles
	for (auto particle : particles)
	{
		particle->draw(renderer);
	}
}

void PS_ParticleEffect::setEmitter(C_Vec2 emitter)
{
	this->emitter = emitter;
}

void PS_ParticleEffect::setEmitting(bool emit)
{
	this->emit = emit;
}

void PS_ParticleEffect::setMoveSpeed(float moveSpeed)
{
	this->moveSpeed = moveSpeed;
}

void PS_ParticleEffect::makeNewParticles()
{
	//If the particle should emit:
	if (emit)
	{
		//Get the number of particles to initialise between 0 and 4
		int numberOfParticles = (rand() % 5);

		//Loop for all of the particles to create
		for (int i = 0; i < numberOfParticles; i++)
		{
			//Get the scale of the particle, between 1 and 5
			float scaleValue = (float)((rand() % 4) + 1);

			//Get the direction of the particle between -15 and 15
			C_Vec2 direction;
			direction.x = (float)((rand() % 30) + 1) - 15.0f;
			direction.y = (float)((rand() % 30) + 1) - 15.0f;

			//Push a new particle to the vector
			particles.push_back(new PS_Particle(texture, scaleValue, direction, moveSpeed, emitter));
		}
	}
}