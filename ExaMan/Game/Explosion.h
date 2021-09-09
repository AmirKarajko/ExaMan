#pragma once
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Game/Data/Explosion/small/smallexp0.h"
#include "Game/Data/Explosion/small/smallexp1.h"
#include "Game/Data/Explosion/small/smallexp2.h"
#include "Game/Data/Explosion/small/smallexp3.h"
sf::Texture smallexp0Texture;
sf::Texture smallexp1Texture;
sf::Texture smallexp2Texture;
sf::Texture smallexp3Texture;
#include "Game/Data/Explosion/medium/mediumexp0.h"
#include "Game/Data/Explosion/medium/mediumexp1.h"
#include "Game/Data/Explosion/medium/mediumexp2.h"
#include "Game/Data/Explosion/medium/mediumexp3.h"
sf::Texture mediumexp0Texture;
sf::Texture mediumexp1Texture;
sf::Texture mediumexp2Texture;
sf::Texture mediumexp3Texture;

void loadExplosionImages() {
	smallexp0Texture.loadFromMemory(smallexp0_png, smallexp0_png_size);
	smallexp1Texture.loadFromMemory(smallexp1_png, smallexp1_png_size);
	smallexp2Texture.loadFromMemory(smallexp2_png, smallexp2_png_size);
	smallexp3Texture.loadFromMemory(smallexp3_png, smallexp3_png_size);
	mediumexp0Texture.loadFromMemory(mediumexp0_png, mediumexp0_png_size);
	mediumexp1Texture.loadFromMemory(mediumexp1_png, mediumexp1_png_size);
	mediumexp2Texture.loadFromMemory(mediumexp2_png, mediumexp2_png_size);
	mediumexp3Texture.loadFromMemory(mediumexp3_png, mediumexp3_png_size);
}

class Explosion
{
public:
	sf::Sprite sprite;

	sf::Vector2f position;

	static const int SMALL = 0, MEDIUM = 1;
	int size;

	bool remove;

	int counter;
	int anim;

	Explosion(int size, sf::Vector2f position)
	{
		this->size = size;
		this->position = position;
		remove = false;
		counter = 0;
		anim = 0;
	}

	void update()
	{
		if(counter < 2)
		{
			counter++;
		}
		else
		{
			if(anim < 4)
			{
				anim++;
			}
			else
			{
				remove = true;
			}
			counter = 0;
		}
	}

};
#endif