#include "SM_Help.h"

SM_Help::SM_Help(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(backgroundMusic),
	help(new C_Texture("Assets/Images/help.png", renderer)),
	coin(new C_Texture("Assets/Images/coin.png", renderer)),
	buttonBackground(new C_Texture("Assets/Images/buttonBackground981x174.png", renderer)),
	coinDim(C_Vec2(dimensions.y * 0.125f, dimensions.y * 0.125f)),
	buttonYPos((dimensions.y * 0.075f) * 11.0f)
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);

	//Initialise Buttons
	resumeButton =
		new UI_Button(
		buttonBackground, //Button Sprite
		C_Vec2(981.0f, 174.0f), //Sprite Dimensions
		C_Vec2(dimensions.x * 0.2f, buttonYPos), //Position
		"Resume", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		206, 158, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		C_Vec2(dimensions.x * 0.2f, dimensions.y * 0.125f), //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	exitButton =
		new UI_Button(
		buttonBackground, //Button Sprite
		C_Vec2(981.0f, 174.0f), //Sprite Dimensions
		C_Vec2(dimensions.x * 0.6f, buttonYPos), //Position
		"Quit", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		206, 158, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		C_Vec2(dimensions.x * 0.2f, dimensions.y * 0.125f), //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);
}

SM_Help::~SM_Help()
{
	//Delete pointers
	delete universalSpeed;
	delete help;
	delete resumeButton;
	delete exitButton;
	delete coin;
	delete buttonBackground;
}

bool SM_Help::input()
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

				//Return to the game state
				stateManager->removeLastState();
				return true;
				break;
			}
		}

		//Handle the resume button input
		if (resumeButton->input(incomingEvent))
		{
			//Return to the game state
			stateManager->removeLastState();
			return true;
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

void SM_Help::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
	//Update the buttons
	exitButton->update(dt);
	resumeButton->update(dt);
}

void SM_Help::draw()
{
	//draw the images
	help->pushToScreen(renderer, C_Vec2(dimensions.x * 0.125f, dimensions.y * 0.05f), dimensions * 0.75);

	//Draw the two coins outside the buttons
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.15f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.45f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.55f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);
	coin->pushToScreen(
		renderer,
		C_Vec2((dimensions.x * 0.85f) - (coinDim.x * 0.5f), buttonYPos),
		coinDim);

	//draw the buttons
	resumeButton->draw(renderer);
	exitButton->draw(renderer);
}