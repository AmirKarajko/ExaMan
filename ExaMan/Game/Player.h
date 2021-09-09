#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

using namespace std;

#include <SFML/Graphics.hpp>

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

	void draw(sf::RenderWindow& window, vector<Bullet>& bullets) {
		// Player Control
		if (shoot)
		{
			if (shootCounter <= 0)
			{
				if (direction == LEFT)
					bullets.push_back(Bullet(Bullet::PLAYERS, direction, sf::Vector2f(position.x - 8, position.y + 14)));
				if (direction == RIGHT)
					bullets.push_back(Bullet(Bullet::PLAYERS, direction, sf::Vector2f(position.x + 32, position.y + 14)));
				shootCounter = 10;
			}
			else
			{
				shootCounter--;
			}
		}
		else
		{
			shootCounter = 0;
		}

		// Player draw
		if (visible)
		{
			if (!damage)
			{
				if (onGround)
				{
					if (!shoot)
					{
						switch (state)
						{
						case IDLE:
							switch (direction)
							{
							case RIGHT:
								sprite.setTexture(playerIdleRightTexture);
								break;
							case LEFT:
								sprite.setTexture(playerIdleLeftTexture);
								break;
							default:
								break;
							}
							break;
						case WALK:
							switch (direction)
							{
							case RIGHT:
								switch (spriteId)
								{
								case 0:
									sprite.setTexture(playerWalkRight1Texture);
									break;
								case 1:
									sprite.setTexture(playerWalkRight2Texture);
									break;
								case 2:
									sprite.setTexture(playerWalkRight3Texture);
									break;
								default:
									break;
								}
								break;
							case LEFT:
								switch (spriteId)
								{
								case 0:
									sprite.setTexture(playerWalkLeft1Texture);
									break;
								case 1:
									sprite.setTexture(playerWalkLeft2Texture);
									break;
								case 2:
									sprite.setTexture(playerWalkLeft3Texture);
									break;
								default:
									break;
								}
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}
					else
					{
						switch (state)
						{
						case IDLE:
							switch (direction)
							{
							case RIGHT:
								sprite.setTexture(playerIdleShootRightTexture);
								break;
							case LEFT:
								sprite.setTexture(playerIdleShootLeftTexture);
								break;
							default:
								break;
							}
							break;
						case WALK:
							switch (direction)
							{
							case RIGHT:
								switch (spriteId)
								{
								case 0:
									sprite.setTexture(playerWalkShootRight1Texture);
									break;
								case 1:
									sprite.setTexture(playerWalkShootRight2Texture);
									break;
								case 2:
									sprite.setTexture(playerWalkShootRight3Texture);
									break;
								default:
									break;
								}
								break;
							case LEFT:
								switch (spriteId)
								{
								case 0:
									sprite.setTexture(playerWalkShootLeft1Texture);
									break;
								case 1:
									sprite.setTexture(playerWalkShootLeft2Texture);
									break;
								case 2:
									sprite.setTexture(playerWalkShootLeft3Texture);
									break;
								default:
									break;
								}
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}
				}
				else
				{
					if (!shoot)
					{
						switch (direction)
						{
						case RIGHT:
							sprite.setTexture(playerJumpRightTexture);
							break;
						case LEFT:
							sprite.setTexture(playerJumpLeftTexture);
							break;
						default:
							break;
						}
					}
					else
					{
						switch (direction)
						{
						case RIGHT:
							sprite.setTexture(playerJumpShootRightTexture);
							break;
						case LEFT:
							sprite.setTexture(playerJumpShootLeftTexture);
							break;
						default:
							break;
						}
					}
				}
			}
			else
			{
				if (!death)
				{
					switch (direction)
					{
					case Player::LEFT:
						sprite.setTexture(playerDamageLeftTexture);
						break;
					case Player::RIGHT:
						sprite.setTexture(playerDamageRightTexture);
						break;
					default:
						break;
					}
				}
				else
				{
					if (deathpose < 1)
					{
						if (deathposeCounter < 10)
						{
							deathposeCounter++;
						}
						else
						{
							deathpose++;
							deathposeCounter = 0;
						}
					}
					switch (direction)
					{
					case Player::LEFT:
						switch (deathpose)
						{
						case 0:
							sprite.setTexture(playerDeath1LeftTexture);
							break;
						case 1:
							sprite.setTexture(playerDeath2LeftTexture);
							break;
						default:
							break;
						}
						break;
					case Player::RIGHT:
						switch (deathpose)
						{
						case 0:
							sprite.setTexture(playerDeath1RightTexture);
							break;
						case 1:
							sprite.setTexture(playerDeath2RightTexture);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
				}

			}
		}
		sprite.setPosition(position);

		window.draw(sprite);
	}

	void update(std::vector<GameObject> &objects, int& playerLives)
	{
		if (damage)
		{
			moveLeft = false;
			moveRight = false;
			jump = false;
			shoot = false;
			if (damageCounter < 25)
			{
				damageCounter++;
			}
			else
			{
				if (playerLives > 0)
				{
					playerLives--;
					damage = false;
					damageCounter = 0;
					if (!shield)
					{
						shield = true;
					}
				}
				else
				{
					if (!gameover)
					{
						gameover = true;
					}
					death = true;
				}
			}
		}
		else
		{
			if (shield)
			{
				if (shieldCounter < 100)
				{
					if (visibilityCounter < 5)
					{
						visibilityCounter++;
					}
					else
					{
						if (visible)
						{
							visible = false;
						}
						else
						{
							visible = true;
						}
						visibilityCounter = 0;
					}
					shieldCounter++;
				}
				else
				{
					shield = false;
					visible = true;
					shieldCounter = 0;
				}
			}
		}


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