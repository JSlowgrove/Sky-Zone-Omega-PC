#include "SM_EndGame.h"

SM_EndGame::SM_EndGame(S_StateManager* stateManager, SDL_Renderer* renderer, C_Vec2 dimensions, C_Music* backgroundMusic, int score)
	: S_State(stateManager, renderer, dimensions),
	backgroundMusic(backgroundMusic),
	background(new C_Texture("Assets/Images/lostgamebackground.png", renderer)),
	gameOver(new C_Texture("Assets/Images/defeat.png", renderer)),
	coin(new C_Texture("Assets/Images/coin.png", renderer)),
	coinDim(C_Vec2(dimensions.y * 0.125f, dimensions.y * 0.125f)),
	updateScores(false),
	scoreText(new C_Text("Score: " + std::to_string(score), "Assets/Font/MonogramsToolbox.ttf", (int)(dimensions.y * 0.075f), renderer, 255, 255, 255))
{
	//Initialise universal speed
	universalSpeed = new float(0.0f);

	//Declare an integer for use with the buttonPosY array
	int buttonIndex = 0;
	//Loop for each of the buttons
	for (int i = 9; i < 13; i += 2)
	{
		buttonYPos[buttonIndex] = (dimensions.y * 0.075f) * i;
		buttonIndex++;
	}

	//Initialise Buttons
	retryButton =
		new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYPos[0]), //Position
		"Again", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		206, 158, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		C_Vec2(dimensions.x * 0.4f, dimensions.y * 0.125f), //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);

	exitButton =
		new UI_Button(
		255, 255, 255, //Button colour
		C_Vec2(dimensions.x * 0.3f, buttonYPos[1]), //Position
		"Quit", "Assets/Font/MonogramsToolbox.ttf", //Text & font location
		(int)(dimensions.y * 0.06f), //Font size
		206, 158, 0, //Font colour
		renderer, //The renderer
		dimensions.y * 0.025f, //Border
		C_Vec2(dimensions.x * 0.4f, dimensions.y * 0.125f), //Minimum dimensions of the button
		universalSpeed //Universal Speed
		);
	
	//Load the scores
	loadScores();

	//Compare the scores with the new score
	compareScores(score);

	//If the score file needs to be updated write the new scores to file
	if (updateScores)
	{
		writeScores();
	}
}

SM_EndGame::~SM_EndGame()
{
	//Delete audio pointers
	delete universalSpeed;
	delete background;
	delete retryButton;
	delete exitButton;
	delete coin;
	delete gameOver;
}

bool SM_EndGame::input()
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
		//Handle the retry button input
		if (retryButton->input(incomingEvent))
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

void SM_EndGame::update(float dt)
{
	//Keep the music playing
	backgroundMusic->startMusic();
	//Update the buttons
	retryButton->update(dt);
	exitButton->update(dt);
}

void SM_EndGame::draw()
{
	//draw the images
	background->pushToScreen(renderer, C_Vec2(), dimensions);
	gameOver->pushToScreen(renderer, C_Vec2(dimensions.x * 0.15f, dimensions.y * 0.1f), C_Vec2(dimensions.x * 0.7f, dimensions.y * 0.25f));
	
	//Loop for each of the buttons
	for (int i = 0; i < 2; i++)
	{
		//Draw the two coins outside the button
		coin->pushToScreen(
			renderer,
			C_Vec2((dimensions.x * 0.2f) - (coinDim.x * 0.5f), buttonYPos[i]),
			coinDim);
		coin->pushToScreen(
			renderer,
			C_Vec2((dimensions.x * 0.8f) - (coinDim.x * 0.5f), buttonYPos[i]),
			coinDim);
	}

	//draw the score
	scoreText->pushToScreen(C_Vec2(dimensions.x * 0.25f, dimensions.y * 0.42f));

	//draw the buttons
	retryButton->draw(renderer);
	exitButton->draw(renderer);
}

void SM_EndGame::loadScores()
{
	//Open the file using a ifstream
	std::ifstream file("Assets/Text/scores.txt");

	//If the file successfully opens
	if (file.is_open())
	{
		//File loading variables
		std::string currentLine;

		//While there are still lines to be read in from the file
		while (getline(file, currentLine))
		{
			//Add the current line to the scores
			scores.push_back(currentLine);
		}
		//Close the file
		file.close();
	}
	//If the file could not be opened then output error message*
	else
	{
		std::cout << "Unable to open scores file";
	}
}

void SM_EndGame::compareScores(int score)
{
	//loop through the loaded scores
	for (int i = 0; i < 5; i++)
	{
		//if the new score is greater than or equal to the loaded score
		if (stoi(scores[i]) <= score)
		{
			updateScores = true;
			
			//loop through and move the scores down by one from the new position of the score
			for (int index = 4; index > i; index--)
			{
				scores[index] = scores[index - 1];
			}
			scores[i] = std::to_string(score);
			
			//Quit the for loop
			break;
		}
	}
}

void SM_EndGame::writeScores()
{
	//Open the file using a ofstream
	std::ofstream file;
	file.open("Assets/Text/scores.txt");

	//If the file successfully opens
	if (file.is_open())
	{
		//Loop though all of the scores
		for (int i = 0; i < 5; i++)
		{
			//Write the score to the file
			file << scores[i];

			//Write a new line to the file unless it is the last score
			if (i != 4)
			{
				file << "\n";
			}
		}
		//Close the file
		file.close();
	}
	//If the file could not be opened then output error message*
	else
	{
		std::cout << "Unable to open scores file";
	}
}