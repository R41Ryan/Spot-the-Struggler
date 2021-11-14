#include <character.h>

void Character::free()
{
	name = NULL;
}

string* Character::getName()
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
