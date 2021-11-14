#pragma once
#include <string>
using namespace std;

const string names[] = { "Wes", "John", "Mary", "Jenna", "Amy", "Sam", "Peter", "Jacob", "David", "Craig", "Ashley", "Madelin", "Madison", "Olivia", "Anthony", "Dylan", "Deborah", "Edward", "Cathy", "Elijah", "Noah", "James", "Vanessa", "Blake", "Ava", "Emily", "Sloan", "Garrett", "Cole", "Alex", "Natalie", "Ricky", "Cailtlin", "Caroline", "Jordan", "Kendall", "Liam", "Will", "Henry", "Lucas" };

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