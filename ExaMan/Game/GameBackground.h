#ifndef GAMEBACKGROUND_H
#define GAMEBACKGROUND_H
class GameBackground
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	int id;

	int counter;
	int animation;

	bool remove;

	GameBackground(int id, sf::Vector2f position)
	{
		this->id = id;
		this->position = position;
		remove = false;
		counter = 0;
		animation = 0;
	}

};
#endif