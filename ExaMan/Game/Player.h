#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Game/Data/Player/Idle/playerIdleRight.h"
#include "Game/Data/Player/Idle/playerIdleLeft.h"
#include "Game/Data/Player/Idle/playerIdleShootRight.h"
#include "Game/Data/Player/Idle/playerIdleShootLeft.h"
#include "Game/Data/Player/Walk/playerWalkRight1.h"
#include "Game/Data/Player/Walk/playerWalkRight2.h"
#include "Game/Data/Player/Walk/playerWalkRight3.h"
#include "Game/Data/Player/Walk/playerWalkShootRight1.h"
#include "Game/Data/Player/Walk/playerWalkShootRight2.h"
#include "Game/Data/Player/Walk/playerWalkShootRight3.h"
#include "Game/Data/Player/Walk/playerWalkLeft1.h"
#include "Game/Data/Player/Walk/playerWalkLeft2.h"
#include "Game/Data/Player/Walk/playerWalkLeft3.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft1.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft2.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft3.h"
#include "Game/Data/Player/Jump/playerJumpRight.h"
#include "Game/Data/Player/Jump/playerJumpLeft.h"
#include "Game/Data/Player/Jump/playerJumpShootRight.h"
#include "Game/Data/Player/Jump/playerJumpShootLeft.h"
#include "Game/Data/Player/Damage/playerDamageLeft.h"
#include "Game/Data/Player/Damage/playerDamageRight.h"
#include "Game/Data/Player/Death/playerDeath1Left.h"
#include "Game/Data/Player/Death/playerDeath2Left.h"
#include "Game/Data/Player/Death/playerDeath1Right.h"
#include "Game/Data/Player/Death/playerDeath2Right.h"
sf::Texture playerIdleRightTexture;
sf::Texture playerIdleLeftTexture;
sf::Texture playerIdleShootRightTexture;
sf::Texture playerIdleShootLeftTexture;
sf::Texture playerWalkRight1Texture;
sf::Texture playerWalkRight2Texture;
sf::Texture playerWalkRight3Texture;
sf::Texture playerWalkShootRight1Texture;
sf::Texture playerWalkShootRight2Texture;
sf::Texture playerWalkShootRight3Texture;
sf::Texture playerWalkLeft1Texture;
sf::Texture playerWalkLeft2Texture;
sf::Texture playerWalkLeft3Texture;
sf::Texture playerWalkShootLeft1Texture;
sf::Texture playerWalkShootLeft2Texture;
sf::Texture playerWalkShootLeft3Texture;
sf::Texture playerJumpLeftTexture;
sf::Texture playerJumpRightTexture;
sf::Texture playerJumpShootLeftTexture;
sf::Texture playerJumpShootRightTexture;
sf::Texture playerDamageLeftTexture;
sf::Texture playerDamageRightTexture;
sf::Texture playerDeath1LeftTexture;
sf::Texture playerDeath2LeftTexture;
sf::Texture playerDeath1RightTexture;
sf::Texture playerDeath2RightTexture;

void loadPlayerImages() {
	playerIdleRightTexture.loadFromMemory(playerIdleRight_png, playerIdleRight_png_size);
	playerIdleLeftTexture.loadFromMemory(playerIdleLeft_png, playerIdleLeft_png_size);
	playerIdleShootRightTexture.loadFromMemory(playerIdleShootRight_png, playerIdleShootRight_png_size);
	playerIdleShootLeftTexture.loadFromMemory(playerIdleShootLeft_png, playerIdleShootLeft_png_size);
	playerWalkRight1Texture.loadFromMemory(playerWalkRight1_png, playerWalkRight1_png_size);
	playerWalkRight2Texture.loadFromMemory(playerWalkRight2_png, playerWalkRight2_png_size);
	playerWalkRight3Texture.loadFromMemory(playerWalkRight3_png, playerWalkRight3_png_size);
	playerWalkShootRight1Texture.loadFromMemory(playerWalkShootRight1_png, playerWalkShootRight1_png_size);
	playerWalkShootRight2Texture.loadFromMemory(playerWalkShootRight2_png, playerWalkShootRight2_png_size);
	playerWalkShootRight3Texture.loadFromMemory(playerWalkShootRight3_png, playerWalkShootRight3_png_size);
	playerWalkLeft1Texture.loadFromMemory(playerWalkLeft1_png, playerWalkLeft1_png_size);
	playerWalkLeft2Texture.loadFromMemory(playerWalkLeft2_png, playerWalkLeft2_png_size);
	playerWalkLeft3Texture.loadFromMemory(playerWalkLeft3_png, playerWalkLeft3_png_size);
	playerWalkShootLeft1Texture.loadFromMemory(playerWalkShootLeft1_png, playerWalkShootLeft1_png_size);
	playerWalkShootLeft2Texture.loadFromMemory(playerWalkShootLeft2_png, playerWalkShootLeft2_png_size);
	playerWalkShootLeft3Texture.loadFromMemory(playerWalkShootLeft3_png, playerWalkShootLeft3_png_size);
	playerJumpRightTexture.loadFromMemory(playerJumpRight_png, playerJumpRight_png_size);
	playerJumpLeftTexture.loadFromMemory(playerJumpLeft_png, playerJumpLeft_png_size);
	playerJumpShootRightTexture.loadFromMemory(playerJumpShootRight_png, playerJumpShootRight_png_size);
	playerJumpShootLeftTexture.loadFromMemory(playerJumpShootLeft_png, playerJumpShootLeft_png_size);
	playerDamageLeftTexture.loadFromMemory(playerDamageLeft_png, playerDamageLeft_png_size);
	playerDamageRightTexture.loadFromMemory(playerDamageRight_png, playerDamageRight_png_size);
	playerDeath1LeftTexture.loadFromMemory(playerDeath1Left_png, playerDeath1Left_png_size);
	playerDeath2LeftTexture.loadFromMemory(playerDeath2Left_png, playerDeath2Left_png_size);
	playerDeath1RightTexture.loadFromMemory(playerDeath1Right_png, playerDeath1Right_png_size);
	playerDeath2RightTexture.loadFromMemory(playerDeath2Right_png, playerDeath2Right_png_size);
}

class Player
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f collisionPosition;
	int width, height;
	static const int IDLE = 0, WALK = 1;
	int state;
	static const int LEFT = 0, RIGHT = 1;
	int direction;
	int spriteId;
	int anim;
	int counter;
	int speed;
	bool jump;
	int jumpCounter;
	bool onGround;
	bool shoot;
	int shootCounter;
	int getLastDirection;
	bool moveLeft, moveRight;
	bool damage;
	int damageCounter;
	bool visible;
	int shieldCounter;
	bool shield;
	int visibilityCounter;
	bool gameover;
	int gameoverCounter;
	bool death;
	int deathpose;
	int deathposeCounter;
	bool missioncomplete;
	int missioncompleteCounter;

	Player() {}

	Player(sf::Vector2f position)
	{
		this->position = position;
		collisionPosition = position;
		state = IDLE;
		direction = RIGHT;
		speed = 2;
		jump = false;
		jumpCounter = 0;
		onGround = false;
		shoot = false;
		shootCounter = 0;
		anim = 0;
		moveLeft = false; moveRight = false;
		getLastDirection = direction;
		width = 17; height = 22;
		damage = false;
		damageCounter = 0;
		visible = true;
		shield = false;
		shieldCounter = 0;
		visibilityCounter = 0;
		gameover = false;
		gameoverCounter = 0;
		missioncomplete = false;
		missioncompleteCounter = 0;
		death = false;
		deathpose = 0;
		deathposeCounter = 0;
	}

	void animation()
	{
		if(counter < 5)
		{
			counter++;
		}
		else
		{
			switch(anim)
			{
			case 0:
				if(spriteId < 2)
				{
					spriteId++;
				}
				else
				{
					anim = 1;
				}
				break;
			case 1:
				if(spriteId > 0)
				{
					spriteId--;
				}
				else
				{
					anim = 0;
				}
				break;
			default:
				break;
			}
			counter = 0;
		}
	}

	void update(std::vector<GameObject> &objects)
	{
		position = collisionPosition;
		control();
		sprite = sf::Sprite();
		switch (state)
		{
		case IDLE:
			spriteId = 0;
			counter = 0;
			break;
		case WALK:
			if (direction == LEFT)
			{
				for(int i = 0; i < speed; i++)
				{
					if(canMoveLeft(objects))
					{
						collisionPosition.x--;
					}
					else
					{
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
						collisionPosition.x++;
					}
					else
					{
						break;
					}
				}
			}
			break;
		default:
			break;
		}

		// Jump
		if(!jump)
		{
			for(int i = 0; i < 3; i++)
			{
				if(canMoveDown(objects))
				{
					onGround = false;
					collisionPosition.y++;
				}
				else
				{
					if(jumpCounter > 0)
						jumpCounter = 0;
					onGround = true;
					break;
				}
			}
		}
		else
		{
			if(jumpCounter < 20)
			{
				jumpCounter++;
			}
			else
			{
				jump = false;
			}
			for(int i = 0; i < 3; i++)
			{
				if(canMoveUp(objects))
				{
					collisionPosition.y--;
				}
				else
				{
					jump = false;
					break;
				}
			}
			onGround = false;
		}
	}

	void control()
	{
		if(moveLeft || moveRight)
		{
			animation();
			if(moveLeft && moveRight)
			{
				state = IDLE;
				direction = getLastDirection;
			}
			else {
				state = WALK;
			}
			if(state == WALK)
			{
				if(moveLeft)
					direction = LEFT;
				if(moveRight)
					direction = RIGHT;
			}
		}
		if(!moveLeft && !moveRight)
		{
			state = IDLE;
		}
	}

	bool canMoveLeft(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(collisionPosition.x + 7);
		int y1 = static_cast<int>(collisionPosition.y + 10);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((x1 == x2 + 16) && (y1 + height > y2) && (y1 < y2 + 16))
			{
				return false;
			}
		}
		return true;
	}

	bool canMoveRight(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(collisionPosition.x + 8);
		int y1 = static_cast<int>(collisionPosition.y + 10);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((x1 + width == x2) && (y1 + height > y2) && (y1 < y2 + 16))
			{
				return false;
			}
		}
		return true;
	}

	bool canMoveDown(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(collisionPosition.x + 8);
		int y1 = static_cast<int>(collisionPosition.y + 10);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((y1 + height == y2) && (x1 + width > x2) && (x1 < x2 + 16))
			{
				return false;
			}
		}
		return true;
	}

	bool canMoveUp(std::vector<GameObject> &objects)
	{
		int x1 = static_cast<int>(collisionPosition.x + 8);
		int y1 = static_cast<int>(collisionPosition.y + 10);
		for(std::vector<GameObject>::iterator it = objects.begin(); it != objects.end(); it++)
		{
			int x2 = static_cast<int>(it->position.x);
			int y2 = static_cast<int>(it->position.y);
			if((y1 == y2 + 16) && (x1 + width > x2) && (x1 < x2 + 16))
			{
				return false;
			}
		}
		return true;
	}

};
#endif