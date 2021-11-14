#include <character.h>

void Character::free()
{
	
}

void Character::incrementFriendLevel(int increment)
{
	if (friendLevel + increment > 100)
	{
		friendLevel = 100;
	}
	else if (friendLevel + increment < 0)
	{
		friendLevel = 0;
	}
	else
	{
		friendLevel += increment;
	}
}

string Character::getName()
{
	return name;
}

int Character::getColour()
{
	return colour;
}

int Character::getEmotion()
{
	return emotion;
}

int Character::getFriendLevel()
{
	return friendLevel;
}

SDL_Texture* Character::getPreferredMap()
{
	return preferredMap;
}

bool Character::isStruggling()
{
	return struggling;
}

void Character::setName(string name)
{
	this->name = name;
}

void Character::setColour(int colour)
{
	this->colour = colour;
}

void Character::setEmotion(int emotion)
{
	this->emotion = emotion;
}

void Character::setFriendLevel(int level)
{
	friendLevel = level;
}

void Character::setPreferredMap(SDL_Texture* map)
{
	preferredMap = map;
}

void Character::setStruggling(bool state)
{
	struggling = state;
}
