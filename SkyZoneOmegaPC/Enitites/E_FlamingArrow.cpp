#include "E_FlamingArrow.h"

E_FlamingArrow::E_FlamingArrow(C_Texture* sprite, C_Texture* fireSprite, C_Vec2 pos, C_Vec2 dimensions, C_Vec2 screenDimensions,
	SDL_Colour minTint, SDL_Colour maxTint)
	: E_Arrow(sprite, pos, dimensions, C_Vec2(1500.0f, 0.0f)), screenDimensions(screenDimensions), damage(3),
	fireEffect(new PS_ParticleEffect(fireSprite, pos + C_Vec2(dimensions.x, dimensions.y * 0.5f), true, 5.0f, 15.0f, 0.1f, minTint, maxTint))
{
}

E_FlamingArrow::~E_FlamingArrow()
{
	//delete pointers
	delete fireEffect;
}

void E_FlamingArrow::update(float dt)
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

void E_FlamingArrow::draw(SDL_Renderer* renderer)
{
	//draw the particle effect
	fireEffect->draw(renderer);
	
	//Push the texture to the screen
	sprite->pushToScreen(renderer, pos, dimensions);
}

int E_FlamingArrow::getDamage()
{
	return damage;
}