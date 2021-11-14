#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <map.h>
#include <player.h>
#include <character.h>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 780;

SDL_Window* gameWindow = NULL;
SDL_Renderer* gameRenderer = NULL;

TTF_Font* gameFont;

bool keyStates[TOTAL_KEYS];
bool mouseStates[TOTAL_MOUSE_BUTTONS];

SDL_Texture* redWhiteSprites[TOTAL_EMOTIONS];
SDL_Texture* yellowGreenSprites[TOTAL_EMOTIONS];
SDL_Texture* orangePurpleSprites[TOTAL_EMOTIONS];

SDL_Texture* mapTextures[TOTAL_MAP_ASSETS];

SDL_Texture* gameMap;

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
	if (!loadSprite(&orangePurpleSprites[ANGRY], "sprites/character/char2/angry.png"))
	{
		printf("Failed to load orange purple angry character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[ANGRY2], "sprites/character/char2/angry2.png"))
	{
		printf("Failed to load orange purple angry2 character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[ANNOYED], "sprites/character/char2/annoyed.png"))
	{
		printf("Failed to load orange purple annoyed character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[BASHFUL], "sprites/character/char2/bashful.png"))
	{
		printf("Failed to load orange purple bashful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[CHILL], "sprites/character/char2/chill.png"))
	{
		printf("Failed to load orange purple chill character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[COPE], "sprites/character/char2/cope.png"))
	{
		printf("Failed to load orange purple cope character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[FLUSTERED], "sprites/character/char2/flustered.png"))
	{
		printf("Failed to load orange purple flustered character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[HAPPY], "sprites/character/char2/happy.png"))
	{
		printf("Failed to load orange purple happy character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[JOYFUL], "sprites/character/char2/joyful.png"))
	{
		printf("Failed to load orange purple joyful character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[LAUGHING], "sprites/character/char2/laughing.png"))
	{
		printf("Failed to load orange purple laughing character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[NERVOUS], "sprites/character/char2/nervous.png"))
	{
		printf("Failed to load orange purple nervous character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SAD], "sprites/character/char2/sad.png"))
	{
		printf("Failed to load orange purple sad character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SICK], "sprites/character/char2/sick.png"))
	{
		printf("Failed to load orange purple sick character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[SPEECHLESS], "sprites/character/char2/speechless.png"))
	{
		printf("Failed to load orange purple speechless character sprite.\n");
		success = false;
	}
	if (!loadSprite(&orangePurpleSprites[UPSET], "sprites/character/char2/upset.png"))
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

int main(int argc, char* argv[])
{
	srand(time(NULL)); // Initializes random number generator

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
			bool quit = false;

			SDL_Event e;

			while (!quit)
			{
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
						setMouseState(e.button, false);
						break;
					}
				}

				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gameRenderer);

				SDL_RenderPresent(gameRenderer);
			}
		}
	}

	close();

	return 0;
}