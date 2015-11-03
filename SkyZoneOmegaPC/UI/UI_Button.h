#pragma once

#include <string>
#include "../Enitites/Base/EB_Entity.h"
#include "../Core/C_Text.h"

/**
@brief Creates a Button object that inherits Entity.
@author Jamie Slowgrove
*/
class UI_Button : public EB_Entity
{
private:
	/**The text of the button.*/
	C_Text* text;
	/**The size of the border from the button and the text.*/
	float border;
	/**A boolean for the state of the button.*/
	bool state;

public:
	/**
	Constructs the Button object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Button.
	@param dimensions The dimensions of the Button.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	UI_Button(C_Texture* sprite, C_Vec2 pos, C_Vec2 dimensions, float* universalSpeed);

	/**
	Constructs the Button object.
	@param sprite A pointer to the objects Texture.
	@param pos The position of the Button.
	@param message The text of the Button.
	@param fontLocation The location of the font.
	@param r The blue of the Button font colour.
	@param g The blue of the Button font colour.
	@param b The blue of the Button font colour.
	@param renderer A pointer to the renderer.
	@param border The size of the border of the Button.
	@param minDimensions The minimum dimensions of the Button.
	@param universalSpeed A pointer for the universal speed of the game.
	*/
	UI_Button(C_Texture* sprite, C_Vec2 pos, std::string message, std::string fontLocation, int fontSize, 
		int r, int g, int b, SDL_Renderer* renderer, float border, C_Vec2 minDimensions, float* universalSpeed);

	/**
	Destructs the Button object.
	*/
	~UI_Button();

	/**
	A function that updates the Button.
	@param dt The delta time.
	*/
	void update(float dt);

	/**
	A function that handles the Button input.
	@param incomingEvent A reference to the incoming event.
	@returns The state of the button.
	*/
	bool input(SDL_Event& incomingEvent);
	
	/**
	Draws the Button text to the screen.
	@param renderer A pointer to the SDL renderer.
	*/
	void drawText(SDL_Renderer* renderer);
};