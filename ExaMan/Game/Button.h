#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

#include "Music.h";
#include "Game/Screens/ScreenEnum.h";

#include "Game/Data/Button/active.h"
#include "Game/Data/Button/hover.h"
#include "Game/Data/Button/inactive.h"
sf::Texture buttonActiveTexture;
sf::Texture buttonInactiveTexture;
sf::Texture buttonHoverTexture;

void loadButtonImages() {
	buttonActiveTexture.loadFromMemory(active_png, active_png_size);
	buttonHoverTexture.loadFromMemory(hover_png, hover_png_size);
	buttonInactiveTexture.loadFromMemory(inactive_png, inactive_png_size);
}

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
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
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
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
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
				sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
				sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
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

Button buttons[7];

void initButtons() {
	Button playButton = Button(0);
	buttons[0] = playButton;
	buttons[0].position = sf::Vector2f(20, 200);
	buttons[0].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button exitButton = Button(1);
	buttons[1] = exitButton;
	buttons[1].position = sf::Vector2f(20, 620);
	buttons[1].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button aboutButton = Button(2);
	buttons[2] = aboutButton;
	buttons[2].position = sf::Vector2f(20, 340);
	buttons[2].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button backButton = Button(3);
	buttons[3] = backButton;
	buttons[3].position = sf::Vector2f(20, 620);
	buttons[3].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button yesButton = Button(4);
	buttons[4] = yesButton;
	buttons[4].position = sf::Vector2f(20, 480);
	buttons[4].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button noButton = Button(5);
	buttons[5] = noButton;
	buttons[5].position = sf::Vector2f(20, 620);
	buttons[5].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

	Button creditsButton = Button(6);
	buttons[6] = creditsButton;
	buttons[6].position = sf::Vector2f(20, 480);
	buttons[6].dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
}

void updateButtons(sf::RenderWindow &window, sf::Event event) {
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePos = window.mapPixelToCoords(pixelPos);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
	{
		if (mousePosF.x > buttons[i].position.x && mousePosF.x < buttons[i].position.x + buttonInactiveTexture.getSize().x
			&& mousePosF.y > buttons[i].position.y && mousePosF.y < buttons[i].position.y + buttonInactiveTexture.getSize().y)
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonReleased:
				if (buttons[i].getState() == Button::STATE_ACTIVE)
				{
					if (buttons[i].visible)
					{
						switch (buttons[i].getId())
						{
						case 0:
							if (screen == MENU)
							{
								screen = GAME;
								resetGame();
								play_music(1);
							}
							break;
						case 1:
							if (screen == MENU)
							{
								screen = EXIT;
							}
							break;
						case 2:
							if (screen == MENU)
							{
								screen = ABOUT;
							}
							break;
						case 3:
							switch (screen)
							{
							case ABOUT:
								screen = MENU;
								break;
							case CREDITS:
								screen = MENU;
								break;
							default:
								break;
							}
							break;
						case 4:
							if (screen == PAUSE)
							{
								screen = MENU;
								play_music(0);
							}
							if (screen == EXIT)
							{
								window.close();
							}
							break;
						case 5:
							if (screen == EXIT)
							{
								screen = MENU;
							}
							if (screen == PAUSE)
							{
								screen = GAME;
							}
							break;
						case 6:
							if (screen == MENU)
							{
								screen = CREDITS;
							}
							break;
						default:
							break;
						}
					}
					buttons[i].update(event, false, window);
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					buttons[i].update(event, true, window);
				}
				break;
			case sf::Event::MouseMoved:
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					buttons[i].update(event, false, window);
				}
				break;
			}
		}
		else
		{
			if (event.type == sf::Event::MouseMoved)
			{
				buttons[i].update(event, false, window);
			}
		}
	}
}

#endif