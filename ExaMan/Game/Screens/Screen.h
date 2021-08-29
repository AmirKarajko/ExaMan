#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include "SFML/Graphics.hpp";

class Screen {
protected:
	sf::Font font;

public:

	Screen() {};

	Screen(sf::Font font) {
		this->font = font;
	};

	virtual void draw(sf::RenderWindow &window) = 0;
};

#endif