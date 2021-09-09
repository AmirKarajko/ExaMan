#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "SFML/Graphics.hpp";

#include "Screen.h";
#include "../Button.h";

class MenuScreen : public Screen {
private:
	Button playButton;
	Button aboutButton;
	Button creditsButton;
	Button exitButton;

	void init() {
		this->playButton = Button(0);
		this->playButton.position = sf::Vector2f(20, 200);
		this->playButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

		this->aboutButton = Button(2);
		this->aboutButton.position = sf::Vector2f(20, 340);
		this->aboutButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

		this->creditsButton = Button(6);
		this->creditsButton.position = sf::Vector2f(20, 480);
		this->creditsButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);

		this->exitButton = Button(1);
		this->exitButton.position = sf::Vector2f(20, 620);
		this->exitButton.dimension = sf::Vector2f(buttonInactiveTexture.getSize().x, buttonInactiveTexture.getSize().y);
	}

public:
	MenuScreen() : Screen() {};

	MenuScreen(sf::Font font) : Screen(font) {
		init();
	};

	void draw(sf::RenderWindow &window) override {
		sf::Text titleText;
		titleText.setString("EXA MAN");
		titleText.setFont(font);
		titleText.setCharacterSize(128);
		titleText.setPosition(50, -50);

		sf::Text playText;
		playText.setFont(this->font);
		playText.setCharacterSize(87);
		playText.setString("PLAY");
		playText.setPosition(
			playButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (playText.getLocalBounds().width / 2)),
			playButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (playText.getLocalBounds().height + 20)));

		sf::Text aboutText;
		aboutText.setFont(font);
		aboutText.setCharacterSize(87);
		aboutText.setString("ABOUT");
		aboutText.setPosition(
			aboutButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (aboutText.getLocalBounds().width / 2)),
			aboutButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (aboutText.getLocalBounds().height + 20)));
		window.draw(aboutText);

		sf::Text creditsText;
		creditsText.setFont(font);
		creditsText.setCharacterSize(87);
		creditsText.setString("CREDITS");
		creditsText.setPosition(
			creditsButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (creditsText.getLocalBounds().width / 2)),
			creditsButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (creditsText.getLocalBounds().height + 20)));

		sf::Text exitText;
		exitText.setFont(font);
		exitText.setCharacterSize(87);
		exitText.setString("EXIT");
		exitText.setPosition(
			exitButton.position.x + ((buttonInactiveTexture.getSize().x / 2) - (exitText.getLocalBounds().width / 2)),
			exitButton.position.y - ((buttonInactiveTexture.getSize().y / 2) - (exitText.getLocalBounds().height + 20)));

		window.draw(titleText);

		window.draw(playText);
		window.draw(aboutText);
		window.draw(creditsText);
		window.draw(exitText);
	}
};

#endif
