#pragma once
#ifndef QUITSCREEN_H
#define QUITSCREEN_H

#include "SFML/Graphics.hpp";

#include "Game/Screens/Screen.h";
#include "Game/Button.h";

class QuitScreen : public Screen {
private:
	Button yesButton;
	Button noButton;

	void init() {
		this->yesButton = Button(4);
		this->yesButton.position = sf::Vector2f(20, 480);
		this->yesButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

		this->noButton = Button(5);
		this->noButton.position = sf::Vector2f(20, 620);
		this->noButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
	}

public:
	QuitScreen() : Screen() {};

	QuitScreen(sf::Font font) : Screen(font) {
		init();
	};

	void draw(sf::RenderWindow& window) override {
		sf::Text quitText;
		quitText.setString("EXIT GAME");
		quitText.setFont(font);
		quitText.setCharacterSize(128);
		quitText.setPosition(50, -50);

		sf::Text yesText;
		yesText.setFont(font);
		yesText.setCharacterSize(87);
		yesText.setString("YES");
		yesText.setPosition(
			this->yesButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (yesText.getLocalBounds().width / 2)),
			this->yesButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (yesText.getLocalBounds().height + 20)));

		sf::Text noText;
		noText.setFont(font);
		noText.setCharacterSize(87);
		noText.setString("NO");
		noText.setPosition(
			this->noButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (noText.getLocalBounds().width / 2)),
			this->noButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (noText.getLocalBounds().height + 20)));

		window.draw(quitText);
		window.draw(yesText);
		window.draw(noText);
	}
};

#endif