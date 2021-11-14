#pragma once
#include <map.h>
#include <SDL_render.h>

const int PORTAL_SIDE = 50;

class Portal {
private:
	SDL_Texture* startMap;
	SDL_Texture* endMap;
	int xPos;
	int yPos;

public:
	// Functions
	
	// Returns true if the given coordinates are within the boundaries of the portal
	bool isInPortal(int x, int y);
	// Renders the portal
	void render(SDL_Renderer* renderer);

	// Getters

	SDL_Texture* getStartMap();
	SDL_Texture* getEndMap();
	int getX();
	int getY();

	// Setters

	void setStartMap(SDL_Texture* map);
	void setEndMap(SDL_Texture* map);
	void setX(int x);
	void setY(int y);
};