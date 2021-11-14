#pragma once
#include <map.h>
#include <SDL_render.h>

enum inputKeys {
	KEY_W,
	KEY_S,
	KEY_A,
	KEY_D,
	KEY_P,
	TOTAL_KEYS
};

enum inputMouseButtons {
	LEFT_MOUSE_BUTTON,
	RIGHT_MOUSE_BUTTON,
	TOTAL_MOUSE_BUTTONS
};

const int PLAYER_SIDE = 133;

class Player {
private:
	float xPos;
	float yPos;

public:
	// Functions

	// Changes xPos and yPos depending on the state of keys pressed passed as an array of booleans
	void move(bool* keyStates);
	// renders the player as a yellow circle on map at the coordinates corresponding to xPos and yPos
	void render(SDL_Renderer* renderer);

	// Getters

	float getX();
	float getY();

	// Setters

	void setX(float x);
	void setY(float y);
};