#include <map.h>

Map::Map()
{
	floor = NULL;
}

Map::~Map()
{
	free();
}

void Map::free()
{
	if (floor != NULL)
	{
		SDL_DestroyTexture(floor);
		floor = NULL;
	}
}

void Map::render(SDL_Renderer* renderer)
{
	if (floor != NULL)
	{
		SDL_RenderCopy(renderer, floor, NULL, NULL);
	}
	else
	{
		printf("Map floor cannot be found!\n");
	}
}

SDL_Texture* Map::getFloor()
{
	return floor;
}

void Map::setFloor(SDL_Texture* floor)
{
	this->floor = floor;
}