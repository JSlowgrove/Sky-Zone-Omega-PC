#include "PS_ParticleEffect.h"

PS_ParticleEffect::PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit), texture(texture), scale(scale), lifeSpan(new C_Timer(0.0f)), 
	dead(false), tint(false), minTint({ (Uint8)0, (Uint8)0, (Uint8)0 }), maxTint({ (Uint8)0, (Uint8)0, (Uint8)0 })
{
	//Initialize random seed
	srand((unsigned int)time(NULL));
	
	//Generate the new particles
	makeNewParticles();
}

PS_ParticleEffect::PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale, float timerLength)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit), texture(texture), scale(scale), lifeSpan(new C_Timer(timerLength)), 
	dead(false), tint(false), minTint({ (Uint8)0, (Uint8)0, (Uint8)0 }), maxTint({ (Uint8)0, (Uint8)0, (Uint8)0 })
{
	//Initialize random seed
	srand((unsigned int)time(NULL));

	//Generate the new particles
	makeNewParticles();
}

PS_ParticleEffect::PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale,
	SDL_Colour minTint, SDL_Colour maxTint)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit), texture(texture), scale(scale), lifeSpan(new C_Timer(0.0f)),
	dead(false), tint(true), minTint(minTint), maxTint(maxTint)
{
	//Initialize random seed
	srand((unsigned int)time(NULL));

	//Generate the new particles
	makeNewParticles();
}

PS_ParticleEffect::PS_ParticleEffect(C_Texture* texture, C_Vec2 emitter, bool emit, float moveSpeed, float scale, float timerLength,
	SDL_Colour minTint, SDL_Colour maxTint)
	: emitter(emitter), moveSpeed(moveSpeed), emit(emit), texture(texture), scale(scale), lifeSpan(new C_Timer(timerLength)),
	dead(false), tint(true), minTint(minTint), maxTint(maxTint)
{
	//Initialize random seed
	srand((unsigned int)time(NULL));

	//Generate the new particles
	makeNewParticles();
}

PS_ParticleEffect::~PS_ParticleEffect()
{
	//Delete pointers
	for (auto particle : particles)
	{
		delete particle;
	}
	delete lifeSpan;
}

void PS_ParticleEffect::update(float dt)
{
	//Update the timer
	lifeSpan->upadateTimer(dt);

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

void PS_ParticleEffect::setParticleScale(float scale)
{
	this->scale = scale;
}

C_Timer* PS_ParticleEffect::getLifeSpan()
{
	return lifeSpan;
}

void PS_ParticleEffect::setDead(bool dead)
{
	this->dead = dead;
}

bool PS_ParticleEffect::getDead()
{
	return dead;
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
			//Get the direction of the particle between -15 and 15
			C_Vec2 direction;
			direction.x = (float)((rand() % 30) + 1) - 15.0f;
			direction.y = (float)((rand() % 30) + 1) - 15.0f;

			//If the particle is to be tinted
			if (tint)
			{
				//Get the colour tint of the particle from the max and min tint
				int r, g, b;
				r = g = b = 0;

				//if the difference is greater than 0 make a random colour value
				if (maxTint.r - minTint.r > 0)
				{
					r = (rand() % (int)(maxTint.r - minTint.r));
				}
				r += (int)minTint.r;

				//if the difference is greater than 0 make a random colour value
				if (maxTint.g - minTint.g > 0)
				{
					g = (rand() % (int)(maxTint.g - minTint.g));
				}
				g += (int)minTint.g;

				//if the difference is greater than 0 make a random colour value
				if (maxTint.b - minTint.b > 0)
				{
					b = (rand() % (int)(maxTint.b - minTint.b));
				}
				b += (int)minTint.b;

				//Form the new colour
				SDL_Colour tintColour = { (Uint8)r, (Uint8)g, (Uint8)b};

				//Push a new particle to the vector
				particles.push_back(new PS_Particle(texture, scale, direction, moveSpeed, emitter, tintColour));
			}
			else
			{
				//Push a new particle to the vector
				particles.push_back(new PS_Particle(texture, scale, direction, moveSpeed, emitter));
			}
			
		}
	}
}