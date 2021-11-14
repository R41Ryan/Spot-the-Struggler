#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <string>
using namespace std;

enum mapAssets
{
	CAFETERIA,
	CLASS,
	FIELD,
	GYM,
	TOTAL_MAP_ASSETS
};

const int MAP_WIDTH = 1280;
const int MAP_HEIGHT = 780;

class Map
{
private:
	SDL_Texture* floor;
public:
	// Deconstructor
	~Map();

	// Functions
	// Deallocates the current floor texture if it exists.
	void free();
	// Renders the map.
	void render(SDL_Renderer* renderer);
	// Getter
	SDL_Texture* getFloor();
	// Setter
	void setFloor(SDL_Texture* floor);
};