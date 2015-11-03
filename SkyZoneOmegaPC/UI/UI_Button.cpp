#include "UI_Button.h"

/**************************************************************************************************************/

/*Constructs an Button object.*/
UI_Button::UI_Button(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed)
	: EB_Entity(sprite, pos, dimensions, "UI_Button", universalSpeed)
{
	/*initialise the text*/
	text = NULL;

	/*initialise the border*/
	border = 0.0f;

	/*initialise state*/
	state = false;
}

/**************************************************************************************************************/

/*Constructs an Button object.*/
UI_Button::UI_Button(C_Texture* sprite, C_Vec2 pos, std::string message, std::string fontLocation, int fontSize,
	int r, int g, int b, SDL_Renderer* renderer, float border, C_Vec2 minDimensions, float* universalSpeed)
	: EB_Entity(sprite, pos, minDimensions, "UI_Button", universalSpeed)
{
	/*initialise the text*/
	text = new C_Text(message, fontLocation, fontSize, renderer, r, g, b);

	/*initialise the variables*/
	this->border = border;

	/*a variable for the new button size*/
	C_Vec2 size = getDimensions();

	/*make sure that the box wraps the text along the x*/
	if (text->getDimensions().x + border > getDimensions().x)
	{
		size.x = text->getDimensions().x + border;
	}

	/*make sure that the box wraps the text along the y*/
	if (text->getDimensions().y + border > getDimensions().y)
	{
		size.y = text->getDimensions().y + border;
	}
	
	/*set the dimensions of the button*/
	setDimensions(size);

	/*initialise state*/
	state = false;
}

/**************************************************************************************************************/

/*Destructs an Button object.*/
UI_Button::~UI_Button()
{
	/*delete pointers*/
	delete text;
}

/**************************************************************************************************************/

/*Updates the Button.*/
void UI_Button::update(float dt)
{
}

/**************************************************************************************************************/

/*Handles the input for the button.*/
bool UI_Button::input(SDL_Event& incomingEvent)
{
	/*a vec2 for testing the input position*/
	C_Vec2 inputPos;

	/*get the input position*/
	inputPos.x = ((float)incomingEvent.motion.x);
	inputPos.y = ((float)incomingEvent.motion.y);

	/*a ternary operator checking if the input position is above the button*/
	bool overButton = (inputPos.x > getPosition().x && inputPos.x < getPosition().x + getDimensions().x
		&& inputPos.y > getPosition().y && inputPos.y < getPosition().y + getDimensions().y) ? 1 : 0;

	switch (incomingEvent.type)
	{
	case SDL_MOUSEBUTTONDOWN: /*If pressed*/

		/*if the left mouse button*/
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			/*if the position is above the button*/
			if (overButton)
			{
				/*the button is pressed*/
				state = true;
			}
		}
		break;

	case SDL_MOUSEBUTTONUP: /*If released*/

		/*if the left mouse button*/
		if (incomingEvent.button.button == SDL_BUTTON_LEFT)
		{
			/*the button is not pressed*/
			state = false;
		}
		break;
	}

	/*return the state*/
	return state;
}

/**************************************************************************************************************/

/*Draws the Button text to the screen.*/
void UI_Button::drawText(SDL_Renderer* renderer)
{
	/*Push the text to the screen*/
	text->pushToScreen(C_Vec2(
		(getPosition().x + (getDimensions().x * 0.5f) - (text->getDimensions().x * 0.5f)),
		(getPosition().y + (getDimensions().y * 0.5f) - (text->getDimensions().y * 0.5f))
		));
}