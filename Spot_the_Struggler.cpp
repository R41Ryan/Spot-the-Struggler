#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <map.h>
#include <player.h>
#include <character.h>
#include <node.h>
#include <portal.h>
#include <vector>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 780;
vector<string> names = { "Wes", "John", "Mary", "Jenna", "Amy", "Sam", "Peter", "Jacob", "David", "Craig", "Ashley", "Madelin", "Madison", "Olivia", "Anthony", "Dylan", "Deborah", "Edward", "Cathy", "Elijah", "Noah", "James", "Vanessa", "Blake", "Ava", "Emily", "Sloan", "Garrett", "Cole", "Alex", "Natalie", "Ricky", "Cailtlin", "Caroline", "Jordan", "Kendall", "Liam", "Will", "Henry", "Lucas" };

SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

TTF_Font* gameFont;

bool keyStates[TOTAL_KEYS];
bool mouseStates[TOTAL_MOUSE_BUTTONS];
int mouseX;
int mouseY;

SDL_Texture* redWhiteSprites[TOTAL_EMOTIONS];
SDL_Texture* yellowGreenSprites[TOTAL_EMOTIONS];
SDL_Texture* orangePurpleSprites[TOTAL_EMOTIONS];

SDL_Texture* mapTextures[TOTAL_MAP_ASSETS];

Map gameMap;
Node nodes[40];
Portal portals[6];
Character characters[40];
Player gamePlayer;

bool init() {
	bool success = true;
	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0)
	{
		printf("SDL failed to initialize. SDL_ERROR: %s\n", SDL_GetError());
	}
	else
	{
		gameWindow = SDL_CreateWindow("Spot the Struggler", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gameWindow == NULL)
		{
			printf("Failed to create window. SDL_ERROR: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gameRenderer == NULL)
			{
				printf("Failed to create renderer. SDL_ERROR: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) && imgFlags))
				{
					printf("Failed to initialize SDL_IMG. IMG_ERROR: %s\n", IMG_GetError());
					success = false;
				}

				if (TTF_Init() == -1)
				{
					printf("Failed to initialize SDL_TTF. TTF_ERROR: %s\n", TTF_GetError());
					success = false;
				}
				else
				{
					gameFont = TTF_OpenFont("fonts/Nasa21-l23X.ttf", 28);
					if (gameFont == NULL)
					{
						printf("Failed to load Nasa21 Font for game. TTF_ERROR: %s.\n", TTF_GetError());
					}
				}
			}
		}
	}

	return success;
}

bool loadSprite(SDL_Texture* spriteSheet[], std::string path)
{
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());

	if (loadedSurface == NULL)
	{
		printf("Failed to load image %s. IMG_ERROR: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, 1, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(gameRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Failed to convert surface to texture. SDL_ERROR: %s \n", SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	*spriteSheet = newTexture;
	return spriteSheet != NULL;
}

bool loadCharacterSprites()
{
	bool success = true;

	// Load sprites for red white characters
	if (!loadSprite(&redWhiteSprites[ANGRY], "sprites/character/char1/angry.png"))
	{
		printf("Failed to load red white angry character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[ANGRY2], "sprites/character/char1/angry2.png"))
	{
		printf("Failed to load red white angry2 character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[ANNOYED], "sprites/character/char1/annoyed.png"))
	{
		printf("Failed to load red white annoyed character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[BASHFUL], "sprites/character/char1/bashful.png"))
	{
		printf("Failed to load red white bashful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[CHILL], "sprites/character/char1/chill.png"))
	{
		printf("Failed to load red white chill character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[COPE], "sprites/character/char1/cope.png"))
	{
		printf("Failed to load red white cope character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[FLUSTERED], "sprites/character/char1/flustered.png"))
	{
		printf("Failed to load red white flustered character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[HAPPY], "sprites/character/char1/happy.png"))
	{
		printf("Failed to load red white happy character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[JOYFUL], "sprites/character/char1/joyful.png"))
	{
		printf("Failed to load red white joyful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[LAUGHING], "sprites/character/char1/laughing.png"))
	{
		printf("Failed to load red white laughing character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[NERVOUS], "sprites/character/char1/nervous.png"))
	{
		printf("Failed to load red white nervous character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[SAD], "sprites/character/char1/sad.png"))
	{
		printf("Failed to load red white sad character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[SICK], "sprites/character/char1/sick.png"))
	{
		printf("Failed to load red white sick character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[SPEECHLESS], "sprites/character/char1/speechless.png"))
	{
		printf("Failed to load red white speechless character sprite.\n");
		success = false;
	}
	if (!loadSprite(&redWhiteSprites[UPSET], "sprites/character/char1/upset.png"))
	{
		printf("Failed to load red white upset character sprite.\n");
		success = false;
	}

	// Load sprites for yellow green characters
	if (!loadSprite(&yellowGreenSprites[ANGRY], "sprites/character/char2/angry.png"))
	{
		printf("Failed to load yellow green angry character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[ANGRY2], "sprites/character/char2/angry2.png"))
	{
		printf("Failed to load yellow green angry2 character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[ANNOYED], "sprites/character/char2/annoyed.png"))
	{
		printf("Failed to load yellow green annoyed character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[BASHFUL], "sprites/character/char2/bashful.png"))
	{
		printf("Failed to load yellow green bashful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[CHILL], "sprites/character/char2/chill.png"))
	{
		printf("Failed to load yellow green chill character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[COPE], "sprites/character/char2/cope.png"))
	{
		printf("Failed to load yellow green cope character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[FLUSTERED], "sprites/character/char2/flustered.png"))
	{
		printf("Failed to load yellow green flustered character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[HAPPY], "sprites/character/char2/happy.png"))
	{
		printf("Failed to load yellow green happy character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[JOYFUL], "sprites/character/char2/joyful.png"))
	{
		printf("Failed to load yellow green joyful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[LAUGHING], "sprites/character/char2/laughing.png"))
	{
		printf("Failed to load yellow green laughing character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[NERVOUS], "sprites/character/char2/nervous.png"))
	{
		printf("Failed to load yellow green nervous character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[SAD], "sprites/character/char2/sad.png"))
	{
		printf("Failed to load yellow green sad character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[SICK], "sprites/character/char2/sick.png"))
	{
		printf("Failed to load yellow green sick character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[SPEECHLESS], "sprites/character/char2/speechless.png"))
	{
		printf("Failed to load yellow green speechless character sprite.\n");
		success = false;
	}
	if (!loadSprite(&yellowGreenSprites[UPSET], "sprites/character/char2/upset.png"))
	{
		printf("Failed to load yellow green upset character sprite.\n");
		success = false;
	}

	// Load sprites for orange purple characters
	if (!loadSprite(&orangePurpleSprites[ANGRY], "sprites/character/char3/angry.png"))
	{
		printf("Failed to load orange purple angry character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[ANGRY2], "sprites/character/char3/angry2.png"))
	{
		printf("Failed to load orange purple angry2 character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[ANNOYED], "sprites/character/char3/annoyed.png"))
	{
		printf("Failed to load orange purple annoyed character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[BASHFUL], "sprites/character/char3/bashful.png"))
	{
		printf("Failed to load orange purple bashful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[CHILL], "sprites/character/char3/chill.png"))
	{
		printf("Failed to load orange purple chill character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[COPE], "sprites/character/char3/cope.png"))
	{
		printf("Failed to load orange purple cope character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[FLUSTERED], "sprites/character/char3/flustered.png"))
	{
		printf("Failed to load orange purple flustered character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[HAPPY], "sprites/character/char3/happy.png"))
	{
		printf("Failed to load orange purple happy character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[JOYFUL], "sprites/character/char3/joyful.png"))
	{
		printf("Failed to load orange purple joyful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[LAUGHING], "sprites/character/char3/laughing.png"))
	{
		printf("Failed to load orange purple laughing character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[NERVOUS], "sprites/character/char3/nervous.png"))
	{
		printf("Failed to load orange purple nervous character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SAD], "sprites/character/char3/sad.png"))
	{
		printf("Failed to load orange purple sad character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SICK], "sprites/character/char3/sick.png"))
	{
		printf("Failed to load orange purple sick character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SPEECHLESS], "sprites/character/char3/speechless.png"))
	{
		printf("Failed to load orange purple speechless character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[UPSET], "sprites/character/char3/upset.png"))
	{
		printf("Failed to load orange purple upset character sprite.\n");
		success = false;
	}

	return success;
}

bool loadMaps()
{
	bool success = true;

	if (!loadSprite(&mapTextures[CAFETERIA], "sprites/map/cafeteria.png"))
	{
		printf("Failed to load cafeteria map.\n");
		success = false;
	}
	if (!loadSprite(&mapTextures[CLASS], "sprites/map/class.png"))
	{
		printf("Failed to load class map.\n");
		success = false;
	}
	if (!loadSprite(&mapTextures[FIELD], "sprites/map/field.png"))
	{
		printf("Failed to load field map.\n");
		success = false;
	}
	if (!loadSprite(&mapTextures[GYM], "sprites/map/gym.png"))
	{
		printf("Failed to load gym map.\n");
		success = false;
	}

	return success;
}

bool loadMedia()
{
	bool success = true;

	if (!loadCharacterSprites())
	{
		printf("Failed to load character sprites");
		success = false;
	}
	if (!loadMaps())
	{
		printf("Failed to load maps.");
		success = false;
	}

	return success;
}

void close()
{
	TTF_CloseFont(gameFont);
	SDL_DestroyRenderer(gameRenderer);
	SDL_DestroyWindow(gameWindow);
	gameRenderer = NULL;
	gameWindow = NULL;

	for (int i = 0; i < TOTAL_EMOTIONS; i++)
	{
		SDL_DestroyTexture(redWhiteSprites[i]);
		SDL_DestroyTexture(yellowGreenSprites[i]);
		SDL_DestroyTexture(orangePurpleSprites[i]);
	}
	for (int i = 0; i < TOTAL_MAP_ASSETS; i++)
	{
		SDL_DestroyTexture(mapTextures[i]);
	}

	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

void setKeyState(SDL_Keycode sym, bool state)
{
	switch (sym)
	{
	case SDLK_w:
		keyStates[KEY_W] = state;
		break;
	case SDLK_s:
		keyStates[KEY_S] = state;
		break;
	case SDLK_a:
		keyStates[KEY_A] = state;
		break;
	case SDLK_d:
		keyStates[KEY_D] = state;
		break;
	case SDLK_p:
		keyStates[KEY_P] = state;
		break;
	}
}

void setMouseState(SDL_MouseButtonEvent button, bool state)
{
	switch (button.button)
	{
	case SDL_BUTTON_LEFT:
		mouseStates[LEFT_MOUSE_BUTTON] = state;
		break;
	case SDL_BUTTON_RIGHT:
		mouseStates[RIGHT_MOUSE_BUTTON] = state;
		break;
	}
}

void setPortals()
{
	// Cafeteria Portals
	portals[0].setStartMap(mapTextures[CAFETERIA]);
	portals[0].setEndMap(mapTextures[CLASS]);
	portals[0].setX(0);
	portals[0].setY(SCREEN_HEIGHT / 2 - PORTAL_SIDE / 2);

	portals[1].setStartMap(mapTextures[CAFETERIA]);
	portals[1].setEndMap(mapTextures[GYM]);
	portals[1].setX(SCREEN_WIDTH - PORTAL_SIDE);
	portals[1].setY(SCREEN_HEIGHT / 2 - PORTAL_SIDE / 2);

	portals[2].setStartMap(mapTextures[CAFETERIA]);
	portals[2].setEndMap(mapTextures[FIELD]);
	portals[2].setX(SCREEN_WIDTH / 2 - PORTAL_SIDE / 2);
	portals[2].setY(0);

	// Class Portal
	portals[3].setStartMap(mapTextures[CLASS]);
	portals[3].setEndMap(mapTextures[CAFETERIA]);
	portals[3].setX(1090 - PORTAL_SIDE / 2);
	portals[3].setY(100 - PORTAL_SIDE / 2);

	// Gym Portal
	portals[4].setStartMap(mapTextures[GYM]);
	portals[4].setEndMap(mapTextures[CAFETERIA]);
	portals[4].setX(0);
	portals[4].setY(SCREEN_HEIGHT / 2 - PORTAL_SIDE / 2);

	// Field Portal
	portals[5].setStartMap(mapTextures[FIELD]);
	portals[5].setEndMap(mapTextures[CAFETERIA]);
	portals[5].setX(SCREEN_WIDTH / 2 - PORTAL_SIDE / 2);
	portals[5].setY(SCREEN_HEIGHT - PORTAL_SIDE);
}

void setNodes()
{
	// Cafeteria Nodes
	nodes[0].setX(150 - CHARACTER_WIDTH / 2);
	nodes[0].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[1].setX(375 - CHARACTER_WIDTH / 2);
	nodes[1].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[2].setX(375 - CHARACTER_WIDTH / 2);
	nodes[2].setY(50 - CHARACTER_HEIGHT / 2);
	nodes[3].setX(850 - CHARACTER_WIDTH / 2);
	nodes[3].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[4].setX(1075 - CHARACTER_WIDTH / 2);
	nodes[4].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[5].setX(725 - CHARACTER_WIDTH / 2);
	nodes[5].setY(450 - CHARACTER_HEIGHT / 2);
	nodes[6].setX(500 - CHARACTER_WIDTH / 2);
	nodes[6].setY(450 - CHARACTER_HEIGHT / 2);
	nodes[7].setX(725 - CHARACTER_WIDTH / 2);
	nodes[7].setY(325 - CHARACTER_HEIGHT / 2);
	nodes[8].setX(375 - CHARACTER_WIDTH / 2);
	nodes[8].setY(725 - CHARACTER_HEIGHT / 2);
	nodes[9].setX(375 - CHARACTER_WIDTH / 2);
	nodes[9].setY(600 - CHARACTER_HEIGHT / 2);

	// Class Nodes
	nodes[10].setX(475 - CHARACTER_WIDTH / 2);
	nodes[10].setY(225 - CHARACTER_HEIGHT / 2);
	nodes[11].setX(475 - CHARACTER_WIDTH / 2);
	nodes[11].setY(350 - CHARACTER_HEIGHT / 2);
	nodes[12].setX(475 - CHARACTER_WIDTH / 2);
	nodes[12].setY(525 - CHARACTER_HEIGHT / 2);
	nodes[13].setX(475 - CHARACTER_WIDTH / 2);
	nodes[13].setY(650 - CHARACTER_HEIGHT / 2);
	nodes[14].setX(700 - CHARACTER_WIDTH / 2);
	nodes[14].setY(225 - CHARACTER_HEIGHT / 2);
	nodes[15].setX(700 - CHARACTER_WIDTH / 2);
	nodes[15].setY(525 - CHARACTER_HEIGHT / 2);
	nodes[16].setX(700 - CHARACTER_WIDTH / 2);
	nodes[16].setY(650 - CHARACTER_HEIGHT / 2);
	nodes[17].setX(925 - CHARACTER_WIDTH / 2);
	nodes[17].setY(350 - CHARACTER_HEIGHT / 2);
	nodes[18].setX(925 - CHARACTER_WIDTH / 2);
	nodes[18].setY(525 - CHARACTER_HEIGHT / 2);
	nodes[19].setX(925 - CHARACTER_WIDTH / 2);
	nodes[19].setY(650 - CHARACTER_HEIGHT / 2);

	// Gym Nodes
	nodes[20].setX(150 - CHARACTER_WIDTH / 2);
	nodes[20].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[21].setX(375 - CHARACTER_WIDTH / 2);
	nodes[21].setY(275 - CHARACTER_HEIGHT / 2);
	nodes[22].setX(375 - CHARACTER_WIDTH / 2);
	nodes[22].setY(100 - CHARACTER_HEIGHT / 2);
	nodes[23].setX(850 - CHARACTER_WIDTH / 2);
	nodes[23].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[24].setX(1075 - CHARACTER_WIDTH / 2);
	nodes[24].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[25].setX(850 - CHARACTER_WIDTH / 2);
	nodes[25].setY(550 - CHARACTER_HEIGHT / 2);
	nodes[26].setX(500 - CHARACTER_WIDTH / 2);
	nodes[26].setY(450 - CHARACTER_HEIGHT / 2);
	nodes[27].setX(725 - CHARACTER_WIDTH / 2);
	nodes[27].setY(325 - CHARACTER_HEIGHT / 2);
	nodes[28].setX(200 - CHARACTER_WIDTH / 2);
	nodes[28].setY(700 - CHARACTER_HEIGHT / 2);
	nodes[29].setX(375 - CHARACTER_WIDTH / 2);
	nodes[29].setY(600 - CHARACTER_HEIGHT / 2);

	// Field Nodes
	nodes[30].setX(150 - CHARACTER_WIDTH / 2);
	nodes[30].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[31].setX(375 - CHARACTER_WIDTH / 2);
	nodes[31].setY(275 - CHARACTER_HEIGHT / 2);
	nodes[32].setX(375 - CHARACTER_WIDTH / 2);
	nodes[32].setY(100 - CHARACTER_HEIGHT / 2);
	nodes[33].setX(850 - CHARACTER_WIDTH / 2);
	nodes[33].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[34].setX(1075 - CHARACTER_WIDTH / 2);
	nodes[34].setY(175 - CHARACTER_HEIGHT / 2);
	nodes[35].setX(850 - CHARACTER_WIDTH / 2);
	nodes[35].setY(550 - CHARACTER_HEIGHT / 2);
	nodes[36].setX(500 - CHARACTER_WIDTH / 2);
	nodes[36].setY(450 - CHARACTER_HEIGHT / 2);
	nodes[37].setX(725 - CHARACTER_WIDTH / 2);
	nodes[37].setY(325 - CHARACTER_HEIGHT / 2);
	nodes[38].setX(200 - CHARACTER_WIDTH / 2);
	nodes[38].setY(700 - CHARACTER_HEIGHT / 2);
	nodes[39].setX(375 - CHARACTER_WIDTH / 2);
	nodes[39].setY(600 - CHARACTER_HEIGHT / 2);
}

void renderPortals(int location)
{
	switch (location)
	{
	case CAFETERIA:
		for (int i = 0; i < 3; i++)
		{
			portals[i].render(gameRenderer);
		}
		break;
	case CLASS:
		portals[3].render(gameRenderer);
		break;
	case GYM:
		portals[4].render(gameRenderer);
		break;
	case FIELD:
		portals[5].render(gameRenderer);
	}
}

void renderNodes(int location)
{
	switch (location)
	{
	case CAFETERIA:
		for (int i = 0; i < 10; i++)
		{
			nodes[i].render(gameRenderer);
		}
		break;
	case CLASS:
		for (int i = 10; i < 20; i++)
		{
			nodes[i].render(gameRenderer);
		}
		break;
	case GYM:
		for (int i = 20; i < 30; i++)
		{
			nodes[i].render(gameRenderer);
		}
		break;
	case FIELD:
		for (int i = 30; i < 40; i++)
		{
			nodes[i].render(gameRenderer);
		}
	}
}

void renderCharacters(int location)
{
	switch (location)
	{
	case CAFETERIA:
		for (int i = 0; i < 10; i++)
		{
			SDL_Rect renderClip = { nodes[i].getX(), nodes[i].getY(), CHARACTER_WIDTH, CHARACTER_HEIGHT };

			if (characters[i].getColour() == RED_WHITE)
				SDL_RenderCopy(gameRenderer, redWhiteSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == YELLOW_GREEN)
				SDL_RenderCopy(gameRenderer, yellowGreenSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == ORANGE_PURPLE)
				SDL_RenderCopy(gameRenderer, orangePurpleSprites[characters[i].getEmotion()], NULL, &renderClip);
		}
		break;
	case CLASS:
		for (int i = 10; i < 20; i++)
		{
			SDL_Rect renderClip = { nodes[i].getX(), nodes[i].getY(), CHARACTER_WIDTH, CHARACTER_HEIGHT };

			if (characters[i].getColour() == RED_WHITE)
				SDL_RenderCopy(gameRenderer, redWhiteSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == YELLOW_GREEN)
				SDL_RenderCopy(gameRenderer, yellowGreenSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == ORANGE_PURPLE)
				SDL_RenderCopy(gameRenderer, orangePurpleSprites[characters[i].getEmotion()], NULL, &renderClip);
		}
		break;
	case GYM:
		for (int i = 20; i < 30; i++)
		{
			SDL_Rect renderClip = { nodes[i].getX(), nodes[i].getY(), CHARACTER_WIDTH, CHARACTER_HEIGHT };

			if (characters[i].getColour() == RED_WHITE)
				SDL_RenderCopy(gameRenderer, redWhiteSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == YELLOW_GREEN)
				SDL_RenderCopy(gameRenderer, yellowGreenSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == ORANGE_PURPLE)
				SDL_RenderCopy(gameRenderer, orangePurpleSprites[characters[i].getEmotion()], NULL, &renderClip);
		}
		break;
	case FIELD:
		for (int i = 30; i < 40; i++)
		{
			SDL_Rect renderClip = { nodes[i].getX(), nodes[i].getY(), CHARACTER_WIDTH, CHARACTER_HEIGHT };

			if (characters[i].getColour() == RED_WHITE)
				SDL_RenderCopy(gameRenderer, redWhiteSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == YELLOW_GREEN)
				SDL_RenderCopy(gameRenderer, yellowGreenSprites[characters[i].getEmotion()], NULL, &renderClip);
			else if (characters[i].getColour() == ORANGE_PURPLE)
				SDL_RenderCopy(gameRenderer, orangePurpleSprites[characters[i].getEmotion()], NULL, &renderClip);
		}
	}
}

void portalClick(int& location)
{
	switch (location)
	{
	case CAFETERIA:
		if (portals[0].isInPortal(mouseX, mouseY))
			location = CLASS;
		if (portals[1].isInPortal(mouseX, mouseY))
			location = GYM;
		if (portals[2].isInPortal(mouseX, mouseY))
			location = FIELD;
		break;
	case CLASS:
		if (portals[3].isInPortal(mouseX, mouseY))
			location = CAFETERIA;
		break;
	case GYM:
		if (portals[4].isInPortal(mouseX, mouseY))
			location = CAFETERIA;
		break;
	case FIELD:
		if (portals[5].isInPortal(mouseX, mouseY))
			location = CAFETERIA;
	}
}

int characterClick(int location)
{
	switch (location)
	{
	case CAFETERIA:
		for (int i = 0; i < 10; i++)
		{
			if (nodes[i].isInNode(mouseX, mouseY))
				return i;
		}
		break;
	case CLASS:
		for (int i = 10; i < 20; i++)
		{
			if (nodes[i].isInNode(mouseX, mouseY))
				return i;
		}
		break;
	case GYM:
		for (int i = 20; i < 30; i++)
		{
			if (nodes[i].isInNode(mouseX, mouseY))
				return i;
		}
		break;
	case FIELD:
		for (int i = 20; i < 30; i++)
		{
			if (nodes[i].isInNode(mouseX, mouseY))
				return i;
		}
	}

	return -1;
}

void randomizeCharacters()
{
	srand(time(NULL)); // Initializes random number generator
	int randomIndex;
	for (int i = 0; i < 40; i++)
	{
		randomIndex = rand() % 40;
		characters[i].setName(names[randomIndex].c_str());
		randomIndex = rand() % TOTAL_COLOURS;
		characters[i].setColour(randomIndex);
		randomIndex = rand() % TOTAL_EMOTIONS;
		characters[i].setEmotion(randomIndex);
		characters[i].setStruggling(false);
	}
	srand(time(NULL)); // Initializes random number generator
	randomIndex = rand() % 40;
	characters[randomIndex].setStruggling(true);
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < TOTAL_KEYS; i++)
	{
		keyStates[i] = false;
	}

	if (!init())
	{
		printf("Failed to initialize.\n");
	}
	else
	{
		if (!loadMedia())
		{
			printf("Failed to load media.\n");
		}
		else
		{
			setPortals();
			setNodes();
			randomizeCharacters();

			int charactersIndex;
			int location = CAFETERIA;
			int gameState = 0;

			bool quit = false;

			SDL_Event e;

			while (!quit)
			{
				SDL_GetMouseState(&mouseX, &mouseY);
				if (gameState == 0) {
					charactersIndex = -1;
				}

				while (SDL_PollEvent(&e) > 0)
				{
					switch (e.type)
					{
					case SDL_QUIT:
						quit = true;
						break;
					case SDL_KEYDOWN:
						setKeyState(e.key.keysym.sym, true);
						break;
					case SDL_KEYUP:
						setKeyState(e.key.keysym.sym, false);
						break;
					case SDL_MOUSEBUTTONDOWN:
						setMouseState(e.button, true);
						break;
					case SDL_MOUSEBUTTONUP:
						if (gameState == 0)
						{
							portalClick(location);
							charactersIndex = characterClick(location);
						}
						break;
					}
				}
				if (gameState == 0)
				{
					SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
					SDL_RenderClear(gameRenderer);

					gameMap.setFloor(mapTextures[location]);
					gameMap.render(gameRenderer);
					renderPortals(location);
					renderCharacters(location);
				}
				if (charactersIndex != -1 && gameState == 0)
				{
					gameState = 1;
					printf("\nName: %s\n", characters[charactersIndex].getName().c_str());
					nodes[charactersIndex].render(gameRenderer);
					printf("Please choose a dialogue option by pressing the corresponding key button.\n");
					printf("A. \"How are you?\"\n");
					printf("S. \"What are your plans for the weekend?\"\n");
					printf("D. \"You seem to be struggling. Are you okay?\"\n");
					renderCharacters(location);
				}
				if (gameState == 1)
				{
					if (keyStates[KEY_A])
					{
						if (characters[charactersIndex].isStruggling())
						{
							printf("\n%s says, \"Not great. I've been really stressed about college applications and I feel like I won't get into my top school.\"\n",
								characters[charactersIndex].getName().c_str());
						}
						else
						{
							srand(time(NULL)); // Initializes random number generator
							string response;
							switch (rand() % 3)
							{
							case 0:
								response = "I'm great!";
							case 1:
								response = "I'm good thanks. And you?";
							case 2:
								response = "I'm not bad, just a bit stressed.";
							}
							printf("\n%s says, \"%s\"\n", characters[charactersIndex].getName().c_str(), response.c_str());
						}
						gameState = 0;
					}
					if (keyStates[KEY_S])
					{
						if (characters[charactersIndex].isStruggling())
						{
							printf("\n%s says, \"I don't feel like doing anything. I haven't had the energy to do anything social lately.\"\n",
								characters[charactersIndex].getName().c_str());
						}
						else
						{
							srand(time(NULL)); // Initializes random number generator
							string response;
							switch (rand() % 3)
							{
							case 0:
								response = "I'm great!";
							case 1:
								response = "I'm good thanks. And you?";
							case 2:
								response = "I am not sure yet, what are you doing?";
							}
							printf("\n%s says, \"%s\"\n", characters[charactersIndex].getName().c_str(), response.c_str());
						}
						gameState = 0;
					}
					if (keyStates[KEY_D])
					{
						if (characters[charactersIndex].isStruggling())
						{
							printf("\n%s says, \"Yeah, so much has been happening and it's hard to keep all under control. I need help.\"\n",
								characters[charactersIndex].getName().c_str());
							gameState = 2;
						}
						else
						{
							printf("\n%s says, \"What? Oh. No, I'm doing alright.\"\n",
								characters[charactersIndex].getName().c_str());
							gameState = 0;
						}
					}
				}
				SDL_RenderPresent(gameRenderer);
			}
		}
	}

	close();

	return 0;
}