#ifndef BULLET_H
#define BULLET_H
class Bullet
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	bool remove;

	static const int LEFT = 0, RIGHT = 1;
	int direction;
	static const int PLAYERS = 0, ENEMIES = 1;
	int which;
	int speed;
	int counter;

	Bullet(int which, int direction, sf::Vector2f position)
	{
		this->which = which;
		this->direction = direction;
		this->position = position;
		remove = false;
		speed = 5;
		counter = 20;
	}

	void update()
	{
		if(direction == LEFT)
		{
			position.x -= speed;
		}
		if(direction == RIGHT)
		{
			position.x += speed;
		}
		if(counter > 0)
		{
			counter--;
		}
		else
		{
			remove = true;
		}
	}

};
#endif