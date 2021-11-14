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

class Map
{
private:
	SDL_Texture* floor;
public:
	// Constructor

	// Functions

	// Renders the map.
	void render(SDL_Renderer* renderer);
	// Getter
	SDL_Texture* getFloor();
	// Setter
	void setFloor(SDL_Texture* floor);
};