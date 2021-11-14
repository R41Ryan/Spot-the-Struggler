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
	
	// Renders the outline of the node
	void render(SDL_Renderer* renderer);
	// Returns true if the given coordinates are within the boundaries of the node
	bool isInNode(int x, int y);

	// Getters

	int getX();
	int getY();
	Character* getOccupying();

	// Setters

	void setX(int x);
	void setY(int y);
	void setOccupying(Character* character);
};