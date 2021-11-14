#pragma once
#include <character.h>
#include <SDL_render.h>

class Node {
private:
	int xPos;
	int yPos;
	Character* occupyingCharacter;
	SDL_Texture* mapLocation;

public:
	// Getters

	int getX();
	int getY();
	Character* getOccupying();
	SDL_Texture* getMap();

	// Setters

	void setX(int x);
	void setY(int y);
	void setOccupying(Character* character);
	void setMap(SDL_Texture* map);
};