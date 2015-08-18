#include "EA_FlamingArrow.h"

EA_FlamingArrow::EA_FlamingArrow(C_Texture* sprite, C_Texture* fireSprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions,
	SDL_Colour minTint, SDL_Colour maxTint)
	: EA_Arrow(sprite, pos, dimensions, C_Vec2(1500.0f, 0.0f), "EA_FlamingArrow"), screenDimensions(screenDimensions), damage(3),
	fireEffect(new PS_ParticleEffect(fireSprite, pos + C_Vec2(dimensions.x, dimensions.y * 0.5f), true, 5.0f, 15.0f, 0.1f, minTint, maxTint))
{
}

EA_FlamingArrow::~EA_FlamingArrow()
{
	//delete pointers
	delete fireEffect;
}

void EA_FlamingArrow::update(float dt)
{
	//update the position
	updatePosWithVelocities(dt);

	//update the particle effect
	fireEffect->setEmitter(pos + C_Vec2(dimensions.x, dimensions.y * 0.25f));
	fireEffect->update(dt);

	//check if the arrow has gone off the screen
	if (pos.x > screenDimensions.x)
	{
		//set the arrow to dead
		dead = true;
	}
}

void EA_FlamingArrow::draw(SDL_Renderer* renderer)
{
	//draw the particle effect
	fireEffect->draw(renderer);
	
	//Push the texture to the screen
	sprite->pushToScreen(renderer, pos, dimensions);
}

int EA_FlamingArrow::getDamage()
{
	return damage;
}