#pragma once
#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include "SFML/Graphics.hpp";

#include "Game/Screens/Screen.h";
#include "Game/Button.h";

class PauseScreen : public Screen {
private:
	Button yesButton;
	Button noButton;

	void init() {
		this->yesButton = Button(4);
		this->yesButton.position = sf::Vector2f(20, 480);
		this->yesButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

		this->noButton = Button(5);
		this->yesButton.position = sf::Vector2f(20, 620);
		this->yesButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
	}

public:
	PauseScreen() : Screen() {};

	PauseScreen(sf::Font font) : Screen(font) {
		init();
	};

	void draw(sf::RenderWindow& window) override {
		sf::Text quitText;
		quitText.setString("QUIT GAME");
		quitText.setFont(font);
		quitText.setCharacterSize(128);
		quitText.setPosition(50, -50);

		window.draw(quitText);
	}
};

#endif