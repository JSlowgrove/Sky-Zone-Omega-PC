#include "E_Player.h"

E_Player::E_Player(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, C_Texture* archerSprite, C_Vec2 archerPos, 
	C_Vec2 archerDimensions, C_Vec2 screenDimensions)
	: E_Animated(sprite, pos, dimensions, 5, C_Vec2(699, 436), 0.1f), screenDimensions(screenDimensions), 
	pressed(false), health(3), maxHealth(3), coins(0), maxCoins(999999999),
	archer(new E_PlayerArcher(archerSprite, archerPos, archerDimensions)), 
	archerOffset(archerPos - pos), flamingPowerUp(false), flamingPowerUpTimer(30), 
	fireEffectOffset(C_Vec2(screenDimensions.x * 0.022f, screenDimensions.y * 0.05f))
{
}

E_Player::~E_Player()
{
	//delete pointers
	delete archer;
	delete fireEffect;
}

void E_Player::update(float dt)
{
	//Update the animation
	animate(dt);

	//If the flaming power up is active update the timer
	if (flamingPowerUp)
	{
		flamingPowerUpTimer.upadateTimer(dt);

		//set the fire effect to emitting
		fireEffect->setEmitting(true);

		//If the timer has ended reset the timer and deactivate the power up
		if (flamingPowerUpTimer.checkTimer())
		{
			flamingPowerUpTimer.resetTimer();
			flamingPowerUp = false;

			//set the fire effect to not be emitting
			fireEffect->setEmitting(false);
		}
	}

	//Make sure that the player is on the screen
	if (pos.x + dimensions.x > screenDimensions.x)
	{
		pos.x = screenDimensions.x - dimensions.x;
	}
	if (pos.x < 0.0f)
	{
		pos.x = 0.0f;
	}
	if (pos.y + dimensions.y > screenDimensions.y)
	{
		pos.y = screenDimensions.y - dimensions.y;
	}
	if (pos.y + archerOffset.y < 0.0f)
	{
		pos.y = -archerOffset.y;
	}

	//set the position of the player archer
	archer->setPosition(pos + archerOffset);

	//update the particle effect
	fireEffect->setEmitter(pos + fireEffectOffset);
	fireEffect->update(dt);

	//Make sure that the number of coins is not greater than the max number of coins.
	if (coins > maxCoins)
	{
		coins = maxCoins;
	}

	//update the archer
	archer->update(dt);
}

void E_Player::input(SDL_Event& incomingEvent, C_Vec2 mousePos)
{
	switch (incomingEvent.type)
	{
	case SDL_KEYDOWN: //If a key is pressed
		switch (incomingEvent.key.keysym.sym)
		{
		case SDLK_SPACE:
			//If the player is not already firing an arrow
			if (!getFiring())
			{
				//Set the player to fire an arrow
				setFiring(true);
			}
			break;
		}
		break;

	case SDL_MOUSEBUTTONDOWN: //If a mouse button is pressed

		//Left Mouse Button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			//Test if the mouse is over the player
			if (mousePos.x >= pos.x && mousePos.x < pos.x + dimensions.x
				&& mousePos.y >= pos.y && mousePos.y < pos.y + dimensions.x)
			{
				pressed = true;
				//set the offset for making the player be attached to where the player was pressed
				offset = mousePos - pos;
			}	
			else
			{
				pressed = false;
			}
		}
		break;

	case SDL_MOUSEBUTTONUP: //If a mouse button is released

		//Left Mouse Button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
				pressed = false;
		}
		break;
	}

	if (pressed)
	{
		//set the player position to the mouse pos using the pressed offset for the mouse position on the player
		pos = mousePos - offset;
	}	
}

void E_Player::draw(SDL_Renderer* renderer)
{
	//Draw the player archer
	archer->draw(renderer);

	//Draw the player chariot and Pegasus
	sprite->pushSpriteToScreen(renderer, pos, dimensions, spriteIndex * spriteDimensions, spriteDimensions);

	//draw the particle effect
	fireEffect->draw(renderer);
}

void E_Player::increaseHealth()
{
	//increase health if lower than the max health
	if (health < maxHealth)
	{
		health++;
	}
}

void E_Player::decreaseHealth()
{
	//decrease health if higher than 0
	if (health > 0)
	{
		health--;
	}
}

int E_Player::getHealth()
{
	return health;
}

void E_Player::increaseCoins()
{
	coins++;
}

int E_Player::getCoins()
{
	return coins;
}

bool E_Player::entityCollisionTest(C_Vec2 entityPos, C_Vec2 entityDimensions)
{
	//Collision check between the player chariot or Pegasus and the entity
	if (C_Utilities::rectRectIntersect(pos, dimensions, entityPos, entityDimensions))
	{
		return true;
	}
	//Collision check between the player archer and the entity
	if (C_Utilities::rectRectIntersect(archer->getPosition(), archer->getDimensions(), entityPos, entityDimensions))
	{
		return true;
	}
	return false;
}

void E_Player::setFireArrow(bool fireArrow)
{
	archer->setFireArrow(fireArrow);
}

bool E_Player::getFireArrow()
{
	return archer->getFireArrow();
}

void E_Player::setFiring(bool firing)
{
	archer->setFiring(firing); 
}

bool E_Player::getFiring()
{
	return archer->getFiring();
}

void E_Player::setFlaming(bool flamingPowerUp)
{
	this->flamingPowerUp = flamingPowerUp;
}

bool E_Player::getFlaming()
{
	return flamingPowerUp;
}

void E_Player::initialiseFire(C_Texture* fireSprite, SDL_Colour minTint, SDL_Colour maxTint)
{
	//Initialise the particle effect
	fireEffect = new PS_ParticleEffect(fireSprite, pos + fireEffectOffset, true, 5.0f, 10.0f, 0.1f, minTint, maxTint);
	//set the fire effect to not be emitting
	fireEffect->setEmitting(false);
}