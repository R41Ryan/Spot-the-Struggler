#include <node.h>

int Node::getX()
{
	return xPos;
}

int Node::getY()
{
	return yPos;
}

Character* Node::getOccupying()
{
	return occupyingCharacter;
}

SDL_Texture* Node::getMap()
{
	return mapLocation;
}

void Node::setX(int x)
{
	xPos = x;
}

void Node::setY(int y)
{
	yPos = y;
}

void Node::setOccupying(Character* character)
{
	occupyingCharacter = character;
}

void Node::setMap(SDL_Texture* map)
{
	mapLocation = map;
}
