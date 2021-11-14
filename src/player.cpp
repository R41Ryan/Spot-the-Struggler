#include <player.h>
#include <cmath>

void Player::move(bool* keyStates)
{
	static float speed = 5; // 5 pixels
	int xDir = 0;
	int yDir = 0;

	if (keyStates[KEY_W])
	{
		yDir = -1;
	}

	if (keyStates[KEY_S])
	{
		yDir = 1;
	}

	if (keyStates[KEY_A])
	{
		xDir = -1;
	}

	if (keyStates[KEY_D])
	{
		xDir = 1;
	}

	if (xDir != 0 || yDir != 0)
	{
		// Finding x velocity and y velocity using similar triangles
		float hypotenuse = hypotf((float)xDir, (float)yDir);
		float convertingFactor = speed / hypotenuse;

		float xVel = xDir * convertingFactor;
		float yVel = yDir * convertingFactor;

		float newX = xPos + xVel;
		float newY = yPos + yVel;

		if (newX < PLAYER_SIDE / 2)
		{
			xPos = PLAYER_SIDE / 2;
		}
		else if (newX > 1280 - PLAYER_SIDE / 2)
		{
			xPos = 1280 - PLAYER_SIDE / 2;
		}
		else
		{
			xPos = newX;
		}

		if (newY < PLAYER_SIDE / 2)
		{
			yPos = PLAYER_SIDE / 2;
		}
		else if (newY > 780 - PLAYER_SIDE / 2)
		{
			yPos = 780 - PLAYER_SIDE / 2;
		}
		else
		{
			yPos = newY;
		}
	}
}

void Player::render(SDL_Renderer* renderer)
{
	SDL_FRect renderClip = {xPos - PLAYER_SIDE / 2, yPos - PLAYER_SIDE / 2, PLAYER_SIDE, PLAYER_SIDE};
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
	SDL_RenderDrawRectF(renderer, &renderClip);
}

float Player::getX()
{
	return xPos;
}

float Player::getY()
{
	return yPos;
}

void Player::setX(float x)
{
	xPos = x;
}

void Player::setY(float y)
{
	yPos = y;
}
