#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "C_Vec2.h"

/**
@brief Creates a Text Texture for use with a renderer using the Text formating.
@author Jamie Slowgrove
*/
class C_Text
{
public:
	/**
	@brief Constructs the Text Texture. Font size and colour will be default (size 10 and black).
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param renderer The renderer.
	*/
	C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer);

	/**
	@brief Constructs the Text Texture. Font colour will be default (black).
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param fontSize The size of the font.
	@param renderer The renderer.
	*/
	C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer);

	/**
	@brief Constructs the Text Texture. Font size will be default (size 10).
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param renderer The renderer.
	@param r The value of red. (0-255)
	@param g The value of green. (0-255)
	@param b The value of blue. (0-255)
	*/
	C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, int r, int g, int b);

	/**
	@brief Constructs the Text Texture. Font size will be default (size 10).
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param renderer The renderer.
	@param fontColour The colour of the font.
	*/
	C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, SDL_Colour fontColour);

	/**
	@brief Constructs the Text Texture.
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param fontSize The size of the font.
	@param renderer The renderer.
	@param r The value of red. (0-255)
	@param g The value of green. (0-255)
	@param b The value of blue. (0-255)
	*/
	C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, int r, int g, int b);

	/**
	@brief Constructs the Text Texture.
	@param text The text to display.
	@param fontLocation The location of the font file.
	@param fontSize The size of the font.
	@param renderer The renderer.
	@param fontColour The colour of the font.
	*/
	C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, SDL_Colour fontColour);

	/**
	@brief Destructs the Text Texture.
	*/
	~C_Text();

	/**
	@brief Pushes the Text Texture to the Renderer to the XY Coordinates.
	@param pos The position to push the Text Texture to.
	*/
	void pushToScreen(C_Vec2 pos);

	/**
	@brief Sets the colour of the text.
	@param r The value of red. (0-255)
	@param g The value of green. (0-255)
	@param b The value of blue. (0-255)
	*/
	void setColour(int r, int g, int b);

	/**
	@brief Sets the colour of the text.
	@param colour The colour of the font.
	*/
	void setColour(SDL_Colour colour);

	/**
	@brief Sets the font size of the text.
	@param fontSize The font size of the text.
	*/
	void setFontSize(int fontSize);

	/**
	@brief Sets the font of the text.
	@param fontLocation The location of the font file.
	*/
	void setFont(std::string fontLocation);

	/**
	@brief Sets the text.
	@param text The text to display.
	*/
	void setText(std::string text);

	/**
	@brief Gets the dimensions of the Text Texture.
	@returns The dimensions of the Text Texture.
	*/
	C_Vec2 getDimensions();

private:
	///Font
	TTF_Font* font;
	///Font colour
	SDL_Colour fontColour;
	///The Texture data
	SDL_Texture* textureData;
	///A pointer to the render
	SDL_Renderer* renderer;
	///Font size
	int fontSize;
	///The text and font location
	std::string text, fontLocation;
	///The Texture dimensions
	C_Vec2 dimensions;

	/**
	@brief Creates a Text Texture using the Text data.
	*/
	void createTextTexture();
};