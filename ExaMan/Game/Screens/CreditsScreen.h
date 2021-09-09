#pragma once
#ifndef CREDITSSCREEN_H
#define CREDITSSCREEN_H

#include "SFML/Graphics.hpp";

#include "Screen.h";
#include "../Button.h";

class CreditsScreen : public Screen {
private:
	Button backButton;

	void init() {
		this->backButton = Button(3);
		this->backButton.position = sf::Vector2f(20, 620);
		this->backButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
	}

public:
	CreditsScreen() : Screen() {};

	CreditsScreen(sf::Font font) : Screen(font) {
		init();
	};

	void draw(sf::RenderWindow& window) override {
		sf::Text creditsTitle;
		creditsTitle.setString("CREDITS");
		creditsTitle.setFont(font);
		creditsTitle.setCharacterSize(128);
		creditsTitle.setPosition(50, -50);

		sf::Text cText;
		cText.setFont(font);
		cText.setCharacterSize(52);
		string credits = "MUSIC BY: wyver9\nFONT BY: weknow";
		cText.setString(credits);
		cText.setPosition(50, 150);

		sf::Text backText;
		backText.setFont(font);
		backText.setCharacterSize(87);
		backText.setString("BACK");
		backText.setPosition(
			this->backButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (backText.getLocalBounds().width / 2)),
			this->backButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (backText.getLocalBounds().height + 20)));

		window.draw(creditsTitle);
		window.draw(cText);
		window.draw(backText);
	}
};

#endif
