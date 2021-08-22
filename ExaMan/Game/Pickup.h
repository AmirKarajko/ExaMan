#ifndef PICKUP_H
#define PICKUP_H
class Pickup
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	int id;

	bool remove;

	Pickup(int id, sf::Vector2f position)
	{
		this->id = id;
		this->position = position;
		remove = false;
	}

};
#endif