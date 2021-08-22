#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
class GameObject
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	int id;

	bool remove;

	GameObject(int id, sf::Vector2f position)
	{
		this->id = id;
		this->position = position;
		remove = false;
	}

};
#endif