#include "SM_Credits.h"

SM_Credits::SM_Credits(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(backgroundMusic),
	background(new C_Texture("Assets/Images/nongamebackground.png", renderer)),
	buttonBackground(new C_Texture("Assets/Images/buttonBackground981x174.png", renderer)),
	credits(new C_Texture("Assets/Images/credits.png", renderer)),
	coin(new C_Texture("Assets/Images/coin.png", renderer)),
	coinDim(C_Vec2(dimensions.y * 0.125f, dimensions.y * 0.125f)),
	buttonYPos((dimensions.y * 0.075f) * 11.0f)
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);

	//Initialise Button
	exitButton =
		new UI_Button(
		buttonBackground, //Button Sprite
		C_Vec2(981.0f, 174.0f), //Sprite Dimensions
		C_Vec2(dimensions.x * 0.3f, buttonYPos), //Position
		"Back", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		206, 158, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		C_Vec2(dimensions.x * 0.4f, dimensions.y * 0.125f), //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);
}

SM_Credits::~SM_Credits()
{
	//Delete pointers
	delete universalSpeed;
	delete credits;
	delete background;
	delete exitButton;
	delete coin;
	delete buttonBackground;
}

bool SM_Credits::input()
{
	//Check for user input
	SDL_Event incomingEvent;
	while (SDL_PollEvent(&incomingEvent))
	{
		switch (incomingEvent.type)
		{
		case SDL_QUIT: //If player closes the window, end the game loop

			return false;
			break;

		case SDL_KEYDOWN:

			switch (incomingEvent.key.keysym.sym)
			{
			case SDLK_ESCAPE: //If Escape is pressed, end the game loop

				//Go to the Main Menu state
				stateManager->changeState(new SM_MainMenu(stateManager, renderer, dimensions, backgroundMusic));
				return true;
				break;
			}
		}

		//Handle the exit button input
		if (exitButton->input(incomingEvent))
		{
			//Go to the Main Menu state
			stateManager->changeState(new SM_MainMenu(stateManager, renderer, dimensions, backgroundMusic));
			return true;
		}
	}
	return true;
}

void SM_Credits::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
	//Update the button
	exitButton->update(dt);
}

void SM_Credits::draw()
{
	//draw the images
	background->pushToScreen(renderer, C_Vec2(), dimensions);
	credits->pushToScreen(renderer, C_Vec2(dimensions.x * 0.125f, dimensions.y * 0.05f), dimensions * 0.75);

	//Draw the two coins outside the button
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.2f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.8f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);

	//draw the button
	exitButton->draw(renderer);
}