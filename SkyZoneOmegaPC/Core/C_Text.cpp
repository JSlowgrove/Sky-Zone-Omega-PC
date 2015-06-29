#include "C_Text.h"

C_Text::C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer)
	: text(text), fontLocation(fontLocation), renderer(renderer)
{
	//Set font size and colour to default
	fontSize = 10;
	fontColour = { (Uint8)0, (Uint8)0, (Uint8)0 };
	
	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer)
	: text(text), fontLocation(fontLocation), fontSize(fontSize), renderer(renderer)
{
	//Set font colour to default
	fontColour = { (Uint8)0, (Uint8)0, (Uint8)0 };

	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, int r, int g, int b)
	: text(text), fontLocation(fontLocation), renderer(renderer)
{
	//Set font size to default
	fontSize = 10;

	//Set font colour
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };

	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::C_Text(std::string text, std::string fontLocation, SDL_Renderer* renderer, SDL_Colour fontColour)
	: text(text), fontLocation(fontLocation), renderer(renderer), fontColour(fontColour)
{
	//Set font size to default
	fontSize = 10;

	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, int r, int g, int b)
	: text(text), fontLocation(fontLocation), fontSize(fontSize), renderer(renderer)
{
	//Set font colour
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };

	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::C_Text(std::string text, std::string fontLocation, int fontSize, SDL_Renderer* renderer, SDL_Colour fontColour)
	: text(text), fontLocation(fontLocation), fontSize(fontSize), renderer(renderer), fontColour(fontColour)
{
	//Initialise font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Create the text texture
	createTextTexture();
}

C_Text::~C_Text()
{
	//deletes the texture from memory
	SDL_DestroyTexture(textureData);
	//delete font
	TTF_CloseFont(font);
	font = NULL;
}

void C_Text::pushToScreen(C_Vec2 pos)
{
	//Create the destination rectangle of the texture
	SDL_Rect destRect;
	destRect.x = (int)pos.x;
	destRect.y = (int)pos.y;
	destRect.w = (int)dimensions.x;
	destRect.h = (int)dimensions.y;

	//Copy the texture to the renderer at the destination rectangle
	SDL_RenderCopy(renderer, textureData, NULL, &destRect);
}

void C_Text::setColour(int r, int g, int b)
{
	//Set the font colour
	fontColour = { (Uint8)r, (Uint8)g, (Uint8)b };

	//Recreate the text texture
	createTextTexture();
}

void C_Text::setColour(SDL_Colour fontColour)
{
	//Set the font colour
	this->fontColour = fontColour;

	//Recreate the text texture
	createTextTexture();
}

void C_Text::setFontSize(int fontSize)
{
	//Set the font size
	this->fontSize = fontSize;

	//Set the font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Recreate the text texture
	createTextTexture();
}

void C_Text::setFont(std::string fontLocation)
{
	//Set the font
	font = TTF_OpenFont(fontLocation.c_str(), fontSize);

	//Recreate the text texture
	createTextTexture();
}

void C_Text::setText(std::string text)
{
	//Set the text
	this->text = text;

	//Recreate the text texture
	createTextTexture();
}

C_Vec2 C_Text::getDimensions()
{
	return dimensions;
}

void C_Text::createTextTexture()
{
	//Declare the surface
	SDL_Surface *surface;

	//Create the surface from the font
	surface = TTF_RenderText_Solid(font, text.c_str(), fontColour);

	//Converts the surface into texture data
	textureData = SDL_CreateTextureFromSurface(renderer, surface);

	//Delete the surface from memory
	SDL_FreeSurface(surface);

	//Get the size of the texture
	int textureWidth;
	int textureHeight;
	SDL_QueryTexture(textureData, NULL, NULL, &textureWidth, &textureHeight);

	//Store the dimensions of the texture
	dimensions = C_Vec2(textureWidth, textureHeight);
}