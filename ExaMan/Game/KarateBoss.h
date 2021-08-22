#ifndef KARATEBOSS_H
#define KARATEBOSS_H
class KarateBoss
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;
	sf::Vector2f collisionPosition;

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
	int health;

	KarateBoss(sf::Vector2f position)
	{
		this->position = position;
		collisionPosition = position;
		remove = false;
		width = 17; height = 22;
		onGround = false;
		speed = 2;
		counter = 0;
		state = IDLE;
		stateCounter = 0;
		direction = LEFT;
		health = 100;
	}

	int random;

	void update(std::vector<GameObject> &objects)
	{
		position = collisionPosition;
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
				if(animationId < 3)
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
						collisionPosition.x--;
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
						collisionPosition.x++;
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
				collisionPosition.y++;
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

};
#endif