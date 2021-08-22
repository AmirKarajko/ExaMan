#ifndef RCHELI_H
#define RCHELI_H
class RCHeli
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	bool remove;

	int animation;
	int counter;
	static const int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3;
	int directionX, directionY;
	static const int IDLE = 0, MOVE = 1;
	int state;
	int stateCounter;

	RCHeli(sf::Vector2f position)
	{
		this->position = position;
		remove = false;
		animation = 0;
		counter = 0;
		directionX = 0;
		directionY = 0;
		state = IDLE;
	}

	void update()
	{

		if(stateCounter < 50)
		{
			stateCounter++;
		}
		else
		{
			srand(time(NULL));
			int random = rand() % 2;
			state = random;
			stateCounter = 0;
		}
		if(state == MOVE)
		{
			switch(directionX)
			{
			case LEFT:
				position.x--;
				break;
			case RIGHT:
				position.x++;
				break;
			default:
				break;
			}
			switch(directionY)
			{
			case UP:
				position.y++;
				break;
			case DOWN:
				position.y--;
				break;
			default:
				break;
			}
		}
	}

};
#endif