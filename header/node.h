#pragma once
#include <character.h>
#include <SDL_render.h>

class Node {
private:
	int xPos;
	int yPos;
	Character* occupyingCharacter;

public:
	// Functions
	
	void render(SDL_Renderer* renderer);

	// Getters

	int getX();
	int getY();
	Character* getOccupying();

	// Setters

	void setX(int x);
	void setY(int y);
	void setOccupying(Character* character);
};