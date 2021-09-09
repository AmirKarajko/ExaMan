#pragma once
#ifndef ABOUTGAMESCREEN_H
#define ABOUTGAMESCREEN_H

#include "SFML/Graphics.hpp";

#include "Game/Screens/Screen.h";
#include "Game/Button.h";

class AboutGameScreen : public Screen {
private:
	Button backButton;

	void init() {
		this->backButton = Button(3);
		this->backButton.position = sf::Vector2f(20, 620);
		this->backButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
	}

public:
	AboutGameScreen() : Screen() {};

	AboutGameScreen(sf::Font font) : Screen(font) {
		init();
	};

	void draw(sf::RenderWindow& window) override {
		sf::Text aboutText;
		aboutText.setString("ABOUT");
		aboutText.setFont(font);
		aboutText.setCharacterSize(128);
		aboutText.setPosition(50, -50);

		sf::Text aText;
		aText.setFont(font);
		aText.setCharacterSize(52);
		string info = "EXA MAN V1.0\nPROGRAMMER:\nAMIR KARAJKO\n\nCOPYRIGHT (C) 2018 - 2021";
		aText.setString(info);
		aText.setPosition(50, 150);

		sf::Text backText;
		backText.setFont(font);
		backText.setCharacterSize(87);
		backText.setString("BACK");
		backText.setPosition(
			this->backButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (backText.getLocalBounds().width / 2)),
			this->backButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (backText.getLocalBounds().height + 20)));

		window.draw(aboutText);
		window.draw(aText);
		window.draw(backText);
	}
};

#endif