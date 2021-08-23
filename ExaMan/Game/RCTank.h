#pragma once
#ifndef RCTANK_H
#define RCTANK_H

#include "Game/Data/RCTank/rctankleft1.h"
#include "Game/Data/RCTank/rctankleft2.h"
#include "Game/Data/RCTank/rctankright1.h"
#include "Game/Data/RCTank/rctankright2.h"
sf::Texture rctankleft1Texture;
sf::Texture rctankleft2Texture;
sf::Texture rctankright1Texture;
sf::Texture rctankright2Texture;

void loadRCTankImages() {
	rctankleft1Texture.loadFromMemory(rctankleft1_png, rctankleft1_png_size);
	rctankleft2Texture.loadFromMemory(rctankleft2_png, rctankleft2_png_size);
	rctankright1Texture.loadFromMemory(rctankright1_png, rctankright1_png_size);
	rctankright2Texture.loadFromMemory(rctankright2_png, rctankright2_png_size);
}

class RCTank
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	static const int IDLE = 0, WALK = 1;
	int state;
	static const int LEFT = 0, RIGHT = 1;
	int direction;
	int animationId;
	int width, height;
	bool remove;
	bool onGround;
	int speed;
	int counter;
	int stateCounter;
	int shootCounter;
	bool shoot;

	RCTank(int direction, sf::Vector2f position)
	{
		this->direction = direction;
		this->position = position;
		remove = false;
		width = 16, height = 16;
		onGround = false;
		speed = 2;
		counter = 0;
		state = IDLE;
		stateCounter = 0;
		shootCounter = 0;
		shoot = false;
	}

	int random;

	void update(std::vector<GameObject> &objects)
	{
		if(!shoot)
		{
			if(shootCounter < 60)
			{
				shootCounter++;
			}
			else
			{
				shoot = true;
				shootCounter = 0;
			}
		}
		if(stateCounter < 30)
		{
			stateCounter++;
		}
		else
		{
			srand(time(NULL));
			random = rand() % 2;
			//state = random;
			stateCounter = 0;
		}
		switch (state)
		{
		case IDLE:
			counter = 0;
			animationId = 0;
			break;
		case WALK:
			if(counter < 5)
			{
				counter++;
			}
			else
			{
				if(animationId < 1)
				{
					animationId++;
				}
				else
				{
					animationId = 0;
				}
				counter = 0;
			}
			if (direction == LEFT)
			{
				for(int i = 0; i < speed; i++)
				{
					if(canMoveLeft(objects))
					{
						position.x--;
					}
					else
					{
						direction = RIGHT;
						break;
					}
				}
			}
			if (direction == RIGHT)
			{
				for(int i = 0; i < speed; i++)
				{
					if(canMoveRight(objects))
					{
						position.x++;
					}
					else
					{
						direction = LEFT;
						break;
					}
				}
			}
			break;
		default:
			break;
		}
		for(int i = 0; i < 3; i++)
		{
			if(canMoveDown(objects))
			{
				onGround = false;
				position.y++;
			}
			else
			{
				onGround = true;
				break;
			}
		}
	}

	bool canMoveLeft(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(position.x);
		int y1 = static_cast<int>(position.y);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((x1 == x2 + width) && (y1 + height > y2) && (y1 < y2 + height))
			{
				return false;
			}
		}
		return true;
	}

	bool canMoveRight(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(position.x);
		int y1 = static_cast<int>(position.y);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((x1 + 16 == x2) && (y1 + 16 > y2) && (y1 < y2 + height))
			{
				return false;
			}
		}
		return true;
	}

	bool canMoveDown(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(position.x);
		int y1 = static_cast<int>(position.y);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((y1 + 16 == y2) && (x1 + 16 > x2) && (x1 < x2 + width))
			{
				return false;
			}
		}
		return true;
	}

};
#endif