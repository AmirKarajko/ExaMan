#pragma once
#ifndef RCROBOT_H
#define RCROBOT_H

#include "Data/RCRobot/rcrobotidleleft.h"
#include "Data/RCRobot/rcrobotidleright.h"
#include "Data/RCRobot/rcrobotwalkleft1.h"
#include "Data/RCRobot/rcrobotwalkleft2.h"
#include "Data/RCRobot/rcrobotwalkright1.h"
#include "Data/RCRobot/rcrobotwalkright2.h"
sf::Texture rcrobotidleleftTexture;
sf::Texture rcrobotidlerightTexture;
sf::Texture rcrobotwalkleft1Texture;
sf::Texture rcrobotwalkleft2Texture;
sf::Texture rcrobotwalkright1Texture;
sf::Texture rcrobotwalkright2Texture;

void loadRCRobotImages() {
	rcrobotidleleftTexture.loadFromMemory(rcrobotidleleft_png, rcrobotidleleft_png_size);
	rcrobotidlerightTexture.loadFromMemory(rcrobotidleright_png, rcrobotidleright_png_size);
	rcrobotwalkleft1Texture.loadFromMemory(rcrobotwalkleft1_png, rcrobotwalkleft1_png_size);
	rcrobotwalkleft2Texture.loadFromMemory(rcrobotwalkleft2_png, rcrobotwalkleft2_png_size);
	rcrobotwalkright1Texture.loadFromMemory(rcrobotwalkright1_png, rcrobotwalkright1_png_size);
	rcrobotwalkright2Texture.loadFromMemory(rcrobotwalkright2_png, rcrobotwalkright2_png_size);
}

class RCRobot
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	int id;
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

	RCRobot(int id, int direction, sf::Vector2f position)
	{
		this->id = id;
		this->direction = direction;
		this->position = position;
		remove = false;
		width = 16, height = 16;
		onGround = false;
		speed = 2;
		counter = 0;
		state = IDLE;
		stateCounter = 0;
	}

	int random;

	void update(std::vector<GameObject> &objects)
	{
		if(stateCounter < 30)
		{
			stateCounter++;
		}
		else
		{
			srand(time(NULL));
			random = rand() % 2;
			state = random;
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
