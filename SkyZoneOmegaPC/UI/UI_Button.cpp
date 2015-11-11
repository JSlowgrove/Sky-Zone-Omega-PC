#include "UI_Button.h"

UI_Button::UI_Button(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EB_Entity(sprite, pos, dimensions, "UI_Button", universalSpeed),
	text(NULL), border(0.0f), pressed(false), usingImage(true)
{
}

UI_Button::UI_Button(C_Texture* sprite, C_Vec2 pos, std::string message, std::string fontLocation, int fontSize,
	int r, int g, int b, SDL_Renderer* renderer, float border, C_Vec2 minDimensions, float* universalSpeed)
	: EB_Entity(sprite, pos, minDimensions, "UI_Button", universalSpeed),
	text(new C_Text(message, fontLocation, fontSize, renderer, r, g, b)),
	border(border), pressed(false), usingImage(true)
{
	//A variable for the new button size
	C_Vec2 size = getDimensions();

	//Make sure that the box wraps the text along the x
	if (text->getDimensions().x + border > getDimensions().x)
	{
		size.x = text->getDimensions().x + border;
	}

	//Make sure that the box wraps the text along the y
	if (text->getDimensions().y + border > getDimensions().y)
	{
		size.y = text->getDimensions().y + border;
	}
	
	//Set the dimensions of the button
	setDimensions(size);
}

UI_Button::UI_Button(int buttonR, int buttonG, int buttonB, C_Vec2 pos, std::string message, std::string fontLocation, int fontSize,
	int r, int g, int b, SDL_Renderer* renderer, float border, C_Vec2 minDimensions, float* universalSpeed)
	: EB_Entity(new C_Texture(renderer, buttonR, buttonG, buttonB), pos, minDimensions, "UI_Button", universalSpeed),
	text(new C_Text(message, fontLocation, fontSize, renderer, r, g, b)),
	border(border), pressed(false), usingImage(false)
{

	//A variable for the new button size
	C_Vec2 size = getDimensions();

	//Make sure that the box wraps the text along the x
	if (text->getDimensions().x + border > getDimensions().x)
	{
		size.x = text->getDimensions().x + border;
	}

	//Make sure that the box wraps the text along the y
	if (text->getDimensions().y + border > getDimensions().y)
	{
		size.y = text->getDimensions().y + border;
	}

	//Set the dimensions of the button
	setDimensions(size);
}

UI_Button::~UI_Button()
{
	/*delete pointers*/
	delete text;
}

void UI_Button::update(float dt)
{
}

bool UI_Button::input(SDL_Event& incomingEvent)
{
	C_Vec2 inputPos;
	inputPos.x = ((float)incomingEvent.motion.x);
	inputPos.y = ((float)incomingEvent.motion.y);

		//A ternary operator checking if the input position is above the button
	bool overButton = (inputPos.x > getPosition().x && inputPos.x < getPosition().x + getDimensions().x
		&& inputPos.y > getPosition().y && inputPos.y < getPosition().y + getDimensions().y) ? 1 : 0;

	//If the button is pressed but is not over the button anymore reset the button
	if (pressed && !overButton)
	{
		//reset the button
		pressed = false;
		if (!usingImage)
		{
			//Remove the tint the button if not using an image for the button
			sprite->setColourTint(255, 255, 255);
		}
	}

	switch (incomingEvent.type)
	{
	case SDL_MOUSEBUTTONDOWN: //If pressed

		//If the left mouse button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			//If the position is above the button
			if (overButton)
			{
				//The button is pressed
				pressed = true;
				if (!usingImage)
				{
					//Tint the button if not using an image for the button
					sprite->setColourTint(200, 200, 200);
				}
			}
		}
		break;

	case SDL_MOUSEBUTTONUP: //If released

		//If the left mouse button
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			//If the button is pressed return true
			if (pressed && overButton)
			{
				return true;
			}
			else
			{
				//reset the button
				pressed = false;
				if (!usingImage)
				{
					//Remove the tint the button if not using an image for the button
					sprite->setColourTint(255, 255, 255);
				}
			}
		}
		break;
	}

	//Return the state
	return false;
}

void UI_Button::draw(SDL_Renderer* renderer)
{
	//Push the button to the screen
	sprite->pushToScreen(renderer, pos, dimensions);

	//Push the text to the screen
	text->pushToScreen(C_Vec2(
		(getPosition().x + (getDimensions().x * 0.5f) - (text->getDimensions().x * 0.5f)),
		(getPosition().y + (getDimensions().y * 0.5f) - (text->getDimensions().y * 0.5f))
		));
}