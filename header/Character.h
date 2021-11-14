#pragma once
#include <string>
#include <SDL_render.h>
using namespace std;

const string names[] = { "Wes", "John", "Mary", "Jenna", "Amy", "Sam", "Peter", "Jacob", "David", "Craig", "Ashley", "Madelin", "Madison", "Olivia", "Anthony", "Dylan", "Deborah", "Edward", "Cathy", "Elijah", "Noah", "James", "Vanessa", "Blake", "Ava", "Emily", "Sloan", "Garrett", "Cole", "Alex", "Natalie", "Ricky", "Cailtlin", "Caroline", "Jordan", "Kendall", "Liam", "Will", "Henry", "Lucas" };
const int CHARACTER_WIDTH = 150;
const int CHARACTER_HEIGHT = 116;

enum characterColours {
	RED_WHITE,
	YELLOW_GREEN,
	ORANGE_PURPLE,
	TOTAL_COLOURS
};

enum characterEmotions {
	ANGRY,
	ANGRY2,
	ANNOYED,
	BASHFUL,
	CHILL,
	COPE,
	FLUSTERED,
	HAPPY,
	JOYFUL,
	LAUGHING,
	NERVOUS,
	SAD,
	SICK,
	SPEECHLESS,
	UPSET,
	TOTAL_EMOTIONS
};

class Character {
private:
	string* name;
	int colour;
	int emotion;
	int friendLevel;
	SDL_Texture* preferredMap;
	bool struggling;

public:
	// Functions

	void free();
	void incrementFriendLevel(int increment);

	// Getters

	string* getName();
	int getColour();
	int getEmotion();
	int getFriendLevel();
	SDL_Texture* getPreferredMap();
	bool isStruggling();

	// Setters

	void setColour(int colour);
	void setEmotion(int emotion);
	void setFriendLevel(int level);
	void setPreferredMap(SDL_Texture* map);
	void setStruggling(bool state);
};