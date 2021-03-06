#include <portal.h>

bool Portal::isInPortal(int x, int y)
{
	bool isRight = x > xPos + PORTAL_SIDE;
	bool isLeft = x < xPos;
	bool isAbove = y < yPos;
	bool isBelow = y > yPos + PORTAL_SIDE;

	if ((!isRight && !isLeft) && (!isAbove && !isBelow))
	{
		return true;
	}

	return false;
}

void Portal::render(SDL_Renderer* renderer)
{
	SDL_Rect renderClip = { xPos, yPos, PORTAL_SIDE, PORTAL_SIDE };
	SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0, 0xFF);
	SDL_RenderFillRect(renderer, &renderClip);
}

SDL_Texture* Portal::getStartMap()
{
	return startMap;
}

SDL_Texture* Portal::getEndMap()
{
	return endMap;
}

int Portal::getX()
{
	return xPos;
}

int Portal::getY()
{
	return yPos;
}

void Portal::setStartMap(SDL_Texture* map)
{
	startMap = map;
}

void Portal::setEndMap(SDL_Texture* map)
{
	endMap = map;
}

void Portal::setX(int x)
{
	xPos = x;
}

void Portal::setY(int y)
{
	yPos = y;
}
