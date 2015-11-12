#include "SM_MainMenu.h"

SM_MainMenu::SM_MainMenu(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(new C_Music("Assets/Audio/gameplayLoop.ogg")),
	background(new C_Texture("Assets/Images/nongamebackground.png", renderer)),
	coin(new C_Texture("Assets/Images/coin.png", renderer)),
	logo(new C_Texture("Assets/Images/szologo.png", renderer)),
	coinDim(C_Vec2(dimensions.y * 0.125f, dimensions.y * 0.125f)),
	logoDim(C_Vec2(dimensions.x * 0.5f, dimensions.y * 0.33f))
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);

	//Declare an integer for use with the buttonPosY array
	int buttonIndex = 0;
	//Loop for each of the buttons
	for (int i = 5; i < 13; i += 2)
	{
		buttonYpos[buttonIndex] = (dimensions.y * 0.075f) * i;
		buttonIndex++;
	}

	//A vector for the button dimensions
	C_Vec2 buttonDim = C_Vec2(dimensions.x * 0.4f, dimensions.y * 0.125f);

	//Initialise buttons
	playButton = new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYpos[0]), //Position
		"play", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		0, 0, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		buttonDim, //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	scoresButton = new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYpos[1]), //Position
		"Scores", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		0, 0, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		buttonDim, //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	creditsButton = new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYpos[2]), //Position
		"Credits", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		0, 0, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		buttonDim, //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	exitButton = 
		new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYpos[3]), //Position
		"Exit", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		0, 0, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		buttonDim, //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	//tmp
	//backgroundMusic->muteMusic();
}

SM_MainMenu::~SM_MainMenu()
{
	//delete pointers
	delete background;
	delete coin;
	delete logo;
	delete universalSpeed;
	delete creditsButton;
	delete scoresButton;
	delete playButton;
	delete exitButton;
}

bool SM_MainMenu::input()
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

				return false;
				break;
			}
		}
		//Handle the play button input
		if (playButton->input(incomingEvent))
		{
			//Go to the game state
			stateManager->changeState(new S_Game(stateManager, renderer, dimensions, backgroundMusic));
			return true;
		}

		//Handle the credits button input
		if (creditsButton->input(incomingEvent))
		{
		}

		//Handle the scores button input
		if (scoresButton->input(incomingEvent))
		{
		}

		//Handle the exit button input
		if (exitButton->input(incomingEvent))
		{
			return false;
		}
	}
	return true;
}

void SM_MainMenu::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
	//Update the buttons
	creditsButton->update(dt);
	playButton->update(dt);
	scoresButton->update(dt);
	exitButton->update(dt);
}

void SM_MainMenu::draw()
{
	//Draw the Images
	background->pushToScreen(renderer, C_Vec2(), dimensions);
	logo->pushToScreen(renderer, C_Vec2(dimensions.x * 0.25f, dimensions.y * 0.01f), logoDim);
	
	//Loop for each of the buttons
	for (int i = 0; i < 4; i++)
	{
		//Draw the two coins outside the button
		coin->pushToScreen(
			renderer, 
			C_Vec2((dimensions.x * 0.2f) - (coinDim.x * 0.5f), buttonYpos[i]),
			coinDim);
		coin->pushToScreen(
			renderer,
			C_Vec2((dimensions.x * 0.8f) - (coinDim.x * 0.5f), buttonYpos[i]),
			coinDim);
	}

	//Draw the buttons
	scoresButton->draw(renderer);
	playButton->draw(renderer);
	creditsButton->draw(renderer);
	exitButton->draw(renderer);
}