#ifndef EXPLOSION_H
#define EXPLOSION_H
class Explosion
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	static const int SMALL = 0, MEDIUM = 1;
	int size;

	bool remove;

	int counter;
	int anim;

	Explosion(int size, sf::Vector2f position)
	{
		this->size = size;
		this->position = position;
		remove = false;
		counter = 0;
		anim = 0;
	}

	void update()
	{
		if(counter < 2)
		{
			counter++;
		}
		else
		{
			if(anim < 4)
			{
				anim++;
			}
			else
			{
				remove = true;
			}
			counter = 0;
		}
	}

};
#endif