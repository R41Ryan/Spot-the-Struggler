#pragma once
#include <string>
using namespace std;

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
	string name;
	int colour;
	int emotion;
	int friend_level;

};