#pragma once

#include <SFML/Audio.hpp>

#include "Data/Music/menu.h"
#include "Data/Music/stage1.h"
#include "Data/Music/karateboss.h"

sf::Music music;

void play_music(int id)
{
	music.stop();
	switch (id)
	{
	case 0:
	{
		music.openFromMemory(menu_ogg, menu_ogg_size);
		music.setLoop(true);
		music.play();
	}
	break;
	case 1:
	{
		music.openFromMemory(stage1_ogg, stage1_ogg_size);
		music.setLoop(true);
		music.play();
	}
	break;
	case 2:
	{
		music.openFromMemory(karateboss_wav, karateboss_wav_size);
		music.setLoop(true);
		music.play();
	}
	break;
	default:
		break;
	}
}