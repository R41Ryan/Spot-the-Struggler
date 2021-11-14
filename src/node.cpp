#include <node.h>

void Node::render(SDL_Renderer* renderer)
{
	SDL_Rect renderRect = { xPos, yPos, CHARACTER_WIDTH, CHARACTER_HEIGHT };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0, 0xFF);
	SDL_RenderDrawRect(renderer, &renderRect);
}

bool Node::isInNode(int x, int y)
{
	bool isRight = x > xPos + CHARACTER_WIDTH;
	bool isLeft = x < xPos;
	bool isAbove = y < yPos;
	bool isBelow = y > yPos + CHARACTER_HEIGHT;

	if ((!isRight && !isLeft) && (!isAbove && !isBelow))
	{
		return true;
	}

	return false;
}

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
