#pragma once
#include <string>
using namespace std;

enum characterColours {
	RED_WHITE,
	YELLOW_GREEN,
	ORANGE_PURPLE
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
	UPSET
};

class Character {
private:
	string name;
	int colour;
	int emotion;
	int friend_level;

};