#ifndef BUTTON_H
#define BUTTON_H
class Button
{
private:
	int state;
	int id;

public:
	static const int STATE_INACTIVE = 0;
	static const int STATE_HOVER = 1;
	static const int STATE_ACTIVE = 2;

	bool visible;

	sf::Vector2f position;

	sf::Vector2f dimension;

	Button()
	{
		visible = false;
		id = 0;
		position = sf::Vector2f(0.0f, 0.0f);
		reset();
	}

	Button(int id)
	{
		this->id = id;
		position = sf::Vector2f(0.0f, 0.0f);
		reset();
	}

	Button(int id, sf::Vector2f position, bool visible)
	{
		this->id = id;
		this->position = position;
		this->visible = visible;
		reset();
	}

	sf::FloatRect getRect()
	{
		sf::FloatRect rect = sf::FloatRect(position, dimension);
		return rect;
	}

	int getId()
	{
		return id;
	}

	int getState()
	{
		return state;
	}

	void reset()
	{
		state = STATE_INACTIVE;
	}

	void update(sf::Event event, bool leftMouseButtonPressed, sf::RenderWindow &window)
	{
		switch(event.type)
		{
		case sf::Event::MouseMoved:
			if(!leftMouseButtonPressed) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				sf::FloatRect rect = getRect();
				if(rect.contains(mousePosF))
				{
					state = STATE_HOVER;
				}
				else
				{
					state = STATE_INACTIVE;
				}
			}
			break;
		case sf::Event::MouseButtonPressed:
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				sf::FloatRect rect = getRect();
				if(rect.contains(mousePosF))
				{
					state = STATE_ACTIVE;
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if(event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
				sf::FloatRect rect = getRect();
				if(rect.contains(mousePosF))
				{
					state = STATE_HOVER;
				}
				else
				{
					state = STATE_INACTIVE;
				}
			}
			break;
		default:
			break;
		}
	}
};
#endif