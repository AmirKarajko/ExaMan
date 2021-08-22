#ifndef PLAYER_H
#define PLAYER_H
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