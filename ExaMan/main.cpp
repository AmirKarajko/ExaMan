#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Game/Button.h"
#include "Game/Bullet.h"
#include "Game/GameObject.h"
#include "Game/GameBackGround.h"
#include "Game/RCRobot.h"
#include "Game/RCHeli.h"
#include "Game/RCTank.h"
#include "Game/KarateBoss.h"
#include "Game/Player.h"
#include "Game/Explosion.h"
#include "Game/Pickup.h"
#include "Game/Map.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Textures
#include "Game/Data/Icon/icon.h"
// Button
#include "Game/Data/Button/active.h"
#include "Game/Data/Button/hover.h"
#include "Game/Data/Button/inactive.h"
sf::Texture buttonActiveTexture;
sf::Texture buttonInactiveTexture;
sf::Texture buttonHoverTexture;
// Player
#include "Game/Data/Player/Idle/playerIdleRight.h"
#include "Game/Data/Player/Idle/playerIdleLeft.h"
#include "Game/Data/Player/Idle/playerIdleShootRight.h"
#include "Game/Data/Player/Idle/playerIdleShootLeft.h"
#include "Game/Data/Player/Walk/playerWalkRight1.h"
#include "Game/Data/Player/Walk/playerWalkRight2.h"
#include "Game/Data/Player/Walk/playerWalkRight3.h"
#include "Game/Data/Player/Walk/playerWalkShootRight1.h"
#include "Game/Data/Player/Walk/playerWalkShootRight2.h"
#include "Game/Data/Player/Walk/playerWalkShootRight3.h"
#include "Game/Data/Player/Walk/playerWalkLeft1.h"
#include "Game/Data/Player/Walk/playerWalkLeft2.h"
#include "Game/Data/Player/Walk/playerWalkLeft3.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft1.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft2.h"
#include "Game/Data/Player/Walk/playerWalkShootLeft3.h"
#include "Game/Data/Player/Jump/playerJumpRight.h"
#include "Game/Data/Player/Jump/playerJumpLeft.h"
#include "Game/Data/Player/Jump/playerJumpShootRight.h"
#include "Game/Data/Player/Jump/playerJumpShootLeft.h"
#include "Game/Data/Player/Damage/playerDamageLeft.h"
#include "Game/Data/Player/Damage/playerDamageRight.h"
#include "Game/Data/Player/Death/playerDeath1Left.h"
#include "Game/Data/Player/Death/playerDeath2Left.h"
#include "Game/Data/Player/Death/playerDeath1Right.h"
#include "Game/Data/Player/Death/playerDeath2Right.h"
sf::Texture playerIdleRightTexture;
sf::Texture playerIdleLeftTexture;
sf::Texture playerIdleShootRightTexture;
sf::Texture playerIdleShootLeftTexture;
sf::Texture playerWalkRight1Texture;
sf::Texture playerWalkRight2Texture;
sf::Texture playerWalkRight3Texture;
sf::Texture playerWalkShootRight1Texture;
sf::Texture playerWalkShootRight2Texture;
sf::Texture playerWalkShootRight3Texture;
sf::Texture playerWalkLeft1Texture;
sf::Texture playerWalkLeft2Texture;
sf::Texture playerWalkLeft3Texture;
sf::Texture playerWalkShootLeft1Texture;
sf::Texture playerWalkShootLeft2Texture;
sf::Texture playerWalkShootLeft3Texture;
sf::Texture playerJumpLeftTexture;
sf::Texture playerJumpRightTexture;
sf::Texture playerJumpShootLeftTexture;
sf::Texture playerJumpShootRightTexture;
sf::Texture playerDamageLeftTexture;
sf::Texture playerDamageRightTexture;
sf::Texture playerDeath1LeftTexture;
sf::Texture playerDeath2LeftTexture;
sf::Texture playerDeath1RightTexture;
sf::Texture playerDeath2RightTexture;
// Karate Boss
#include "Game/Data/KarateBoss/bossattack1.h"
#include "Game/Data/KarateBoss/bossattack2.h"
#include "Game/Data/KarateBoss/bossattack3.h"
#include "Game/Data/KarateBoss/bossattack4.h"
#include "Game/Data/KarateBoss/bossIdleLeft.h"
#include "Game/Data/KarateBoss/bossIdleRight.h"
sf::Texture bossattack1Texture;
sf::Texture bossattack2Texture;
sf::Texture bossattack3Texture;
sf::Texture bossattack4Texture;
sf::Texture bossIdleLeftTexture;
sf::Texture bossIdleRightTexture;
// Item
#include "Game/Data/Item/heart.h"
sf::Texture heartTexture;
// RC Robot
#include "Game/Data/RCRobot/rcrobotidleleft.h"
#include "Game/Data/RCRobot/rcrobotidleright.h"
#include "Game/Data/RCRobot/rcrobotwalkleft1.h"
#include "Game/Data/RCRobot/rcrobotwalkleft2.h"
#include "Game/Data/RCRobot/rcrobotwalkright1.h"
#include "Game/Data/RCRobot/rcrobotwalkright2.h"
sf::Texture rcrobotidleleftTexture;
sf::Texture rcrobotidlerightTexture;
sf::Texture rcrobotwalkleft1Texture;
sf::Texture rcrobotwalkleft2Texture;
sf::Texture rcrobotwalkright1Texture;
sf::Texture rcrobotwalkright2Texture;
// RC Heli
#include "Game/Data/RCHeli/rcheli1.h"
#include "Game/Data/RCHeli/rcheli2.h"
sf::Texture rcheli1Texture;
sf::Texture rcheli2Texture;
// RC Tank
#include "Game/Data/RCTank/rctankleft1.h"
#include "Game/Data/RCTank/rctankleft2.h"
#include "Game/Data/RCTank/rctankright1.h"
#include "Game/Data/RCTank/rctankright2.h"
sf::Texture rctankleft1Texture;
sf::Texture rctankleft2Texture;
sf::Texture rctankright1Texture;
sf::Texture rctankright2Texture;
// Objects
#include "Game/Data/Object/box.h"
#include "Game/Data/Object/ground.h"
#include "Game/Data/Object/ironwall.h"
#include "Game/Data/Object/needle.h"
#include "Game/Data/Object/window.h"
#include "Game/Data/Object/door.h"
sf::Texture boxTexture;
sf::Texture groundTexture;
sf::Texture ironwallTexture;
sf::Texture needleTexture;
sf::Texture windowTexture;
sf::Texture doorTexture;
// Backgrounds
#include "Game/Data/BackGround/bg1.h"
#include "Game/Data/BackGround/bg2.h"
#include "Game/Data/BackGround/bg3.h"
#include "Game/Data/BackGround/bg4.h"
#include "Game/Data/BackGround/bg5.h"
sf::Texture bg1Texture;
sf::Texture bg2Texture;
sf::Texture bg3Texture;
sf::Texture bg4Texture;
sf::Texture bg5Texture;
#include "Game/Data/BackGround/clouds1.h"
#include "Game/Data/BackGround/clouds2.h"
sf::Texture clouds1Texture;
sf::Texture clouds2Texture;
#include "Game/Data/BackGround/lava1.h"
#include "Game/Data/BackGround/lava2.h"
sf::Texture lava1Texture;
sf::Texture lava2Texture;
#include "Game/Data/BackGround/wall.h"
sf::Texture wallbgTexture;
#include "Game/Data/BackGround/car.h"
sf::Texture carTexture;
// Bullet
#include "Game/Data/Bullet/bulletLeft.h"
#include "Game/Data/Bullet/bulletRight.h"
sf::Texture bulletLeftTexture;
sf::Texture bulletRightTexture;
// Explosion
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
// Music
#include "Game/Data/Music/menu.h"
#include "Game/Data/Music/stage1.h"
#include "Game/Data/Music/karateboss.h"
// Font
#include "Game/Data/Font/COMPUTERRobot.h"
// Background image
#include "Game/Data/backgroundimage.h"
sf::Texture backgroundTexture;
// Logo
#include "Game/Data/logo.h"
sf::Texture logoTexture;

#include "ScreenEnum.h";

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

int main()
{
	int logoCounter = 0;
	play_music(0);

	int playerLives = 3;

	//sf::RenderWindow window(sf::VideoMode(1024, 768), "EXA MAN");
	sf::RenderWindow window(sf::VideoMode(1024, 768), "EXA MAN", sf::Style::Fullscreen);

	// Camera
	sf::View playerView(sf::FloatRect(0, 0, 200, 150));
	sf::View menuView(sf::FloatRect(0, 0, 1024, 768));
	sf::View statusView(sf::FloatRect(0, 0, 200, 150));

	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	// Icon
	sf::Image icon;
	icon.loadFromMemory(icon_png, icon_png_size);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// Font
	sf::Font font;
	font.loadFromMemory(COMPUTERRobot_ttf, COMPUTERRobot_ttf_size);
	// Title text
	sf::Text titleText;
	titleText.setString("EXA MAN");
	titleText.setFont(font);
	titleText.setCharacterSize(128);
	titleText.setPosition(50, -50);
	// Quit text
	sf::Text quitText;
	quitText.setString("QUIT GAME");
	quitText.setFont(font);
	quitText.setCharacterSize(128);
	quitText.setPosition(50, -50);
	// Exit text
	sf::Text exitText;
	exitText.setString("EXIT GAME");
	exitText.setFont(font);
	exitText.setCharacterSize(128);
	exitText.setPosition(50, -50);
	// About text
	sf::Text aboutText;
	aboutText.setString("ABOUT");
	aboutText.setFont(font);
	aboutText.setCharacterSize(128);
	aboutText.setPosition(50, -50);
	// Credits text
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

	// Info
	sf::Text aText;
	aText.setFont(font);
	aText.setCharacterSize(52);
	string info = "EXA MAN V1.0\nPROGRAMMER:\nAMIR KARAJKO\n\nCOPYRIGHT (C) 2018";
	aText.setString(info);
	aText.setPosition(50, 150);

	// Textures
	// Background
	backgroundTexture.loadFromMemory(backgroundimage_png, backgroundimage_png_size);
	// Logo
	logoTexture.loadFromMemory(logo_jpg, logo_jpg_size);
	// Button
	buttonActiveTexture.loadFromMemory(active_png, active_png_size);
	buttonHoverTexture.loadFromMemory(hover_png, hover_png_size);
	buttonInactiveTexture.loadFromMemory(inactive_png, inactive_png_size);

	// Players
	playerIdleRightTexture.loadFromMemory(playerIdleRight_png, playerIdleRight_png_size);
	playerIdleLeftTexture.loadFromMemory(playerIdleLeft_png, playerIdleLeft_png_size);
	playerIdleShootRightTexture.loadFromMemory(playerIdleShootRight_png, playerIdleShootRight_png_size);
	playerIdleShootLeftTexture.loadFromMemory(playerIdleShootLeft_png, playerIdleShootLeft_png_size);
	playerWalkRight1Texture.loadFromMemory(playerWalkRight1_png, playerWalkRight1_png_size);
	playerWalkRight2Texture.loadFromMemory(playerWalkRight2_png, playerWalkRight2_png_size);
	playerWalkRight3Texture.loadFromMemory(playerWalkRight3_png, playerWalkRight3_png_size);
	playerWalkShootRight1Texture.loadFromMemory(playerWalkShootRight1_png, playerWalkShootRight1_png_size);
	playerWalkShootRight2Texture.loadFromMemory(playerWalkShootRight2_png, playerWalkShootRight2_png_size);
	playerWalkShootRight3Texture.loadFromMemory(playerWalkShootRight3_png, playerWalkShootRight3_png_size);
	playerWalkLeft1Texture.loadFromMemory(playerWalkLeft1_png, playerWalkLeft1_png_size);
	playerWalkLeft2Texture.loadFromMemory(playerWalkLeft2_png, playerWalkLeft2_png_size);
	playerWalkLeft3Texture.loadFromMemory(playerWalkLeft3_png, playerWalkLeft3_png_size);
	playerWalkShootLeft1Texture.loadFromMemory(playerWalkShootLeft1_png, playerWalkShootLeft1_png_size);
	playerWalkShootLeft2Texture.loadFromMemory(playerWalkShootLeft2_png, playerWalkShootLeft2_png_size);
	playerWalkShootLeft3Texture.loadFromMemory(playerWalkShootLeft3_png, playerWalkShootLeft3_png_size);
	playerJumpRightTexture.loadFromMemory(playerJumpRight_png, playerJumpRight_png_size);
	playerJumpLeftTexture.loadFromMemory(playerJumpLeft_png, playerJumpLeft_png_size);
	playerJumpShootRightTexture.loadFromMemory(playerJumpShootRight_png, playerJumpShootRight_png_size);
	playerJumpShootLeftTexture.loadFromMemory(playerJumpShootLeft_png, playerJumpShootLeft_png_size);
	playerDamageLeftTexture.loadFromMemory(playerDamageLeft_png, playerDamageLeft_png_size);
	playerDamageRightTexture.loadFromMemory(playerDamageRight_png, playerDamageRight_png_size);
	playerDeath1LeftTexture.loadFromMemory(playerDeath1Left_png, playerDeath1Left_png_size);
	playerDeath2LeftTexture.loadFromMemory(playerDeath2Left_png, playerDeath2Left_png_size);
	playerDeath1RightTexture.loadFromMemory(playerDeath1Right_png, playerDeath1Right_png_size);
	playerDeath2RightTexture.loadFromMemory(playerDeath2Right_png, playerDeath2Right_png_size);
	// Karate Boss
	bossattack1Texture.loadFromMemory(bossattack1_png, bossattack1_png_size);
	bossattack2Texture.loadFromMemory(bossattack2_png, bossattack2_png_size);
	bossattack3Texture.loadFromMemory(bossattack3_png, bossattack3_png_size);
	bossattack4Texture.loadFromMemory(bossattack4_png, bossattack4_png_size);
	bossIdleLeftTexture.loadFromMemory(bossIdleLeft_png, bossIdleLeft_png_size);
	bossIdleRightTexture.loadFromMemory(bossIdleRight_png, bossIdleRight_png_size);
	// Item
	heartTexture.loadFromMemory(heart_png, heart_png_size);
	// RC Robot
	rcrobotidleleftTexture.loadFromMemory(rcrobotidleleft_png, rcrobotidleleft_png_size);
	rcrobotidlerightTexture.loadFromMemory(rcrobotidleright_png, rcrobotidleright_png_size);
	rcrobotwalkleft1Texture.loadFromMemory(rcrobotwalkleft1_png, rcrobotwalkleft1_png_size);
	rcrobotwalkleft2Texture.loadFromMemory(rcrobotwalkleft2_png, rcrobotwalkleft2_png_size);
	rcrobotwalkright1Texture.loadFromMemory(rcrobotwalkright1_png, rcrobotwalkright1_png_size);
	rcrobotwalkright2Texture.loadFromMemory(rcrobotwalkright2_png, rcrobotwalkright2_png_size);
	// RC Heli
	rcheli1Texture.loadFromMemory(rcheli1_png, rcheli1_png_size);
	rcheli2Texture.loadFromMemory(rcheli2_png, rcheli2_png_size);
	// RC Tank
	rctankleft1Texture.loadFromMemory(rctankleft1_png, rctankleft1_png_size);
	rctankleft2Texture.loadFromMemory(rctankleft2_png, rctankleft2_png_size);
	rctankright1Texture.loadFromMemory(rctankright1_png, rctankright1_png_size);
	rctankright2Texture.loadFromMemory(rctankright2_png, rctankright2_png_size);
	// Objects
	boxTexture.loadFromMemory(box_png, box_png_size);
	groundTexture.loadFromMemory(ground_png, ground_png_size);
	ironwallTexture.loadFromMemory(ironwall_png, ironwall_png_size);
	needleTexture.loadFromMemory(needle_png, needle_png_size);
	windowTexture.loadFromMemory(window_png, window_png_size);
	doorTexture.loadFromMemory(door_png, door_png_size);
	// Backgrounds
	bg1Texture.loadFromMemory(bg1_png, bg1_png_size);
	bg2Texture.loadFromMemory(bg2_png, bg2_png_size);
	bg3Texture.loadFromMemory(bg3_png, bg3_png_size);
	bg4Texture.loadFromMemory(bg4_png, bg4_png_size);
	bg5Texture.loadFromMemory(bg5_png, bg5_png_size);
	clouds1Texture.loadFromMemory(clouds1_png, clouds1_png_size);
	clouds2Texture.loadFromMemory(clouds2_png, clouds2_png_size);
	lava1Texture.loadFromMemory(lava1_png, lava1_png_size);
	lava2Texture.loadFromMemory(lava2_png, lava2_png_size);
	wallbgTexture.loadFromMemory(wall_png, wall_png_size);
	carTexture.loadFromMemory(car_png, car_png_size);
	// Bullet
	bulletLeftTexture.loadFromMemory(bulletLeft_png, bulletLeft_png_size);
	bulletRightTexture.loadFromMemory(bulletRight_png, bulletRight_png_size);
	// Explosion
	smallexp0Texture.loadFromMemory(smallexp0_png, smallexp0_png_size);
	smallexp1Texture.loadFromMemory(smallexp1_png, smallexp1_png_size);
	smallexp2Texture.loadFromMemory(smallexp2_png, smallexp2_png_size);
	smallexp3Texture.loadFromMemory(smallexp3_png, smallexp3_png_size);
	mediumexp0Texture.loadFromMemory(mediumexp0_png, mediumexp0_png_size);
	mediumexp1Texture.loadFromMemory(mediumexp1_png, mediumexp1_png_size);
	mediumexp2Texture.loadFromMemory(mediumexp2_png, mediumexp2_png_size);
	mediumexp3Texture.loadFromMemory(mediumexp3_png, mediumexp3_png_size);
	// Map
	Map map = Map(0);

	// Button
	Button buttons[7];

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

	// Window
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
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
										map = Map(0);
										playerLives = 3;
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

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					if (!map.player.damage)
						map.player.moveLeft = true;
					break;
				case sf::Keyboard::D:
					if (!map.player.damage)
						map.player.moveRight = true;
					break;
				case sf::Keyboard::J:
					if (map.player.onGround)
						if (!map.player.damage)
							map.player.jump = true;
					break;
				case sf::Keyboard::K:
					if (!map.player.damage)
						map.player.shoot = true;
					break;
				case sf::Keyboard::Return:
					break;
				case sf::Keyboard::Escape:
					switch (screen)
					{
					case GAME:
						screen = PAUSE;
						break;
					case PAUSE:
						screen = GAME;
						break;
					case EXIT:
						screen = MENU;
						break;
					case ABOUT:
					case CREDITS:
						screen = MENU;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					map.player.moveLeft = false;
					map.player.getLastDirection = map.player.LEFT;
					break;
				case sf::Keyboard::D:
					map.player.moveRight = false;
					map.player.getLastDirection = map.player.RIGHT;
					break;
				case sf::Keyboard::J:
					map.player.jump = false;
					break;
				case sf::Keyboard::K:
					map.player.shoot = false;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}

		window.clear();

		if (screen == MENU || screen == ABOUT || screen == PAUSE || screen == CREDITS || screen == EXIT)
		{
			sf::Sprite bgSprite;
			bgSprite.setTexture(backgroundTexture);
			window.draw(bgSprite);
		}

		// Buttons
		for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
		{
			sf::Sprite sprite;
			sprite.setPosition(buttons[i].position);
			switch (buttons[i].getId())
			{
			case 0:
				if (screen == MENU)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 1:
				if (screen == MENU)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 2:
				if (screen == MENU)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 3:
				if (screen == ABOUT || screen == CREDITS)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 4:
				if (screen == PAUSE || screen == EXIT)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 5:
				if (screen == PAUSE || screen == EXIT)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			case 6:
				if (screen == MENU)
				{
					buttons[i].visible = true;
				}
				else
				{
					buttons[i].visible = false;
				}
				if (buttons[i].visible)
				{
					switch (buttons[i].getState())
					{
					case Button::STATE_ACTIVE:
						sprite.setTexture(buttonActiveTexture);
						break;
					case Button::STATE_HOVER:
						sprite.setTexture(buttonHoverTexture);
						break;
					case Button::STATE_INACTIVE:
						sprite.setTexture(buttonInactiveTexture);
						break;
					default:
						break;
					}
				}
				break;
			}
			window.draw(sprite);


			switch (buttons[i].getId())
			{
			case 0:
			{
				if (screen == MENU)
				{
					sf::Text playText;
					playText.setFont(font);
					playText.setCharacterSize(87);
					playText.setString("PLAY");
					playText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (playText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (playText.getLocalBounds().height + 20)));
					window.draw(playText);
				}
			}
			break;
			case 1:
			{
				if (screen == MENU)
				{
					sf::Text exitText;
					exitText.setFont(font);
					exitText.setCharacterSize(87);
					exitText.setString("EXIT");
					exitText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (exitText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (exitText.getLocalBounds().height + 20)));
					window.draw(exitText);
				}
			}
			break;
			case 2:
			{
				if (screen == MENU)
				{
					sf::Text aboutText;
					aboutText.setFont(font);
					aboutText.setCharacterSize(87);
					aboutText.setString("ABOUT");
					aboutText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (aboutText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (aboutText.getLocalBounds().height + 20)));
					window.draw(aboutText);
				}
			}
			break;
			case 3:
			{
				if (screen == ABOUT || screen == CREDITS)
				{
					sf::Text backText;
					backText.setFont(font);
					backText.setCharacterSize(87);
					backText.setString("BACK");
					backText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (backText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (backText.getLocalBounds().height + 20)));
					window.draw(backText);
				}
			}
			break;
			case 4:
			{
				if (screen == PAUSE || screen == EXIT)
				{
					sf::Text yesText;
					yesText.setFont(font);
					yesText.setCharacterSize(87);
					yesText.setString("YES");
					yesText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (yesText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (yesText.getLocalBounds().height + 20)));
					window.draw(yesText);
				}
			}
			break;
			case 5:
			{
				if (screen == PAUSE || screen == EXIT)
				{
					sf::Text noText;
					noText.setFont(font);
					noText.setCharacterSize(87);
					noText.setString("NO");
					noText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (noText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (noText.getLocalBounds().height + 20)));
					window.draw(noText);
				}
			}
			break;
			case 6:
			{
				if (screen == MENU)
				{
					sf::Text creditsText;
					creditsText.setFont(font);
					creditsText.setCharacterSize(87);
					creditsText.setString("CREDITS");
					creditsText.setPosition(buttons[i].position.x + ((buttonInactiveTexture.getSize().x / 2) - (creditsText.getLocalBounds().width / 2)), buttons[i].position.y - ((buttonInactiveTexture.getSize().y / 2) - (creditsText.getLocalBounds().height + 20)));
					window.draw(creditsText);
				}
			}
			break;
			}

		}

		switch (screen)
		{
		case LOGO:
		{
			if (logoCounter < 150)
			{
				logoCounter++;
			}
			else
			{
				screen = MENU;
				logoCounter = 0;
			}
			sf::Sprite logo;
			logo.setTexture(logoTexture);
			logo.setPosition(512 - logo.getLocalBounds().width / 2, 384 - logo.getLocalBounds().height / 2);
			window.draw(logo);
		}
		break;
		case CREDITS:
			window.draw(creditsTitle);
			window.draw(cText);
			break;
		case EXIT:
			// View
			window.setView(menuView);
			// Text
			window.draw(exitText);
			break;
		case PAUSE:
			// View
			window.setView(menuView);
			// Text
			window.draw(quitText);
			break;
		case ABOUT:
			// Text
			window.draw(aboutText);
			window.draw(aText);
			break;
		case MENU:
			// View
			window.setView(menuView);
			// Text
			window.draw(titleText);
			break;
		case GAME:
			// View
			playerView.setCenter(sf::Vector2f(map.player.position.x + 10, map.player.position.y));

			window.setView(playerView);

			// Background
			for (vector<GameBackground>::iterator it = map.backgrounds.begin(); it != map.backgrounds.end();)
			{
				if (it->remove)
				{
					it = map.backgrounds.erase(it);
				}
				else
				{
					switch (it->id)
					{
					case 0:
						it->sprite.setTexture(bg1Texture);
						break;
					case 1:
						it->sprite.setTexture(bg2Texture);
						break;
					case 2:
						it->sprite.setTexture(bg3Texture);
						break;
					case 3:
						it->sprite.setTexture(bg4Texture);
						break;
					case 4:
						it->sprite.setTexture(bg5Texture);
						break;
					case 5:
						switch (it->animation)
						{
						case 0:
							it->sprite.setTexture(clouds1Texture);
							break;
						case 1:
							it->sprite.setTexture(clouds2Texture);
							break;
						default:
							break;
						}
						if (it->counter < 20)
						{
							it->counter++;
						}
						else
						{
							if (it->animation < 1)
							{
								it->animation++;
							}
							else
							{
								it->animation = 0;
							}
							it->counter = 0;
						}
						break;
					case 6:
						if (!map.player.shield)
							if (map.player.collisionPosition.x + (map.player.width) + 7 > it->position.x && map.player.collisionPosition.x + 8 < it->position.x + 16
								&& map.player.collisionPosition.y + (map.player.height) > it->position.y && map.player.collisionPosition.y < it->position.y + 16)
							{
								map.player.damage = true;
							}
						switch (it->animation)
						{
						case 0:
							it->sprite.setTexture(lava1Texture);
							break;
						case 1:
							it->sprite.setTexture(lava2Texture);
							break;
						default:
							break;
						}
						if (it->counter < 20)
						{
							it->counter++;
						}
						else
						{
							if (it->animation < 1)
							{
								it->animation++;
							}
							else
							{
								it->animation = 0;
							}
							it->counter = 0;
						}
						break;
					case 7:
						it->sprite.setTexture(wallbgTexture);
						break;
					case 8:
						it->sprite.setTexture(carTexture);
						break;
					default:
						break;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// Object
			for (vector<GameObject>::iterator it = map.objects.begin(); it != map.objects.end();)
			{
				if (it->remove)
				{
					it = map.objects.erase(it);
				}
				else
				{
					switch (it->id)
					{
					case 0:
						it->sprite.setTexture(groundTexture);
						break;
					case 1:
						for (vector<Bullet>::iterator it2 = map.bullets.begin(); it2 != map.bullets.end();)
						{
							if (it->position.x + 16 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + 16 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
								it2->remove = true;
							}
							it2++;
						}
						it->sprite.setTexture(boxTexture);
						break;
					case 2:
						it->sprite.setTexture(ironwallTexture);
						break;
					case 3:
						if (!map.player.shield)
							if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
								&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
							{
								playerLives = 0;
								map.player.damage = true;
							}
						it->sprite.setTexture(needleTexture);
						break;
					case 4:
						it->sprite.setTexture(windowTexture);
						break;
					case 5:
						it->sprite.setTexture(doorTexture);
						break;
					default:
						break;
					}
					if (it->id == 5)
					{
						if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							map = Map(1);
							play_music(2);
							break;
						}
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// Pickup
			for (vector<Pickup>::iterator it = map.pickups.begin(); it != map.pickups.end();)
			{
				if (it->remove)
				{
					it = map.pickups.erase(it);
				}
				else
				{
					switch (it->id)
					{
					case 0:
						it->sprite.setTexture(heartTexture);
						break;
					default:
						break;
					}
					if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
						&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
					{
						playerLives++;
						it->remove = true;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// Explosion
			for (vector<Explosion>::iterator it = map.explosions.begin(); it != map.explosions.end();)
			{
				if (it->remove)
				{
					it = map.explosions.erase(it);
				}
				else
				{
					switch (it->size)
					{
					case Explosion::SMALL:
						switch (it->anim)
						{
						case 0:
							it->sprite.setTexture(smallexp0Texture);
							break;
						case 1:
							it->sprite.setTexture(smallexp1Texture);
							break;
						case 2:
							it->sprite.setTexture(smallexp2Texture);
							break;
						case 3:
							it->sprite.setTexture(smallexp3Texture);
							break;
						default:
							break;
						}
						break;
					case Explosion::MEDIUM:
						switch (it->anim)
						{
						case 0:
							it->sprite.setTexture(mediumexp0Texture);
							break;
						case 1:
							it->sprite.setTexture(mediumexp1Texture);
							break;
						case 2:
							it->sprite.setTexture(mediumexp2Texture);
							break;
						case 3:
							it->sprite.setTexture(mediumexp3Texture);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
					it->update();
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// RC Robot
			for (vector<RCRobot>::iterator it = map.rcrobots.begin(); it != map.rcrobots.end();)
			{
				if (it->remove)
				{
					it = map.rcrobots.erase(it);
				}
				else
				{
					if (!map.player.shield)
						if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							map.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = map.bullets.begin(); it2 != map.bullets.end();)
					{
						if (it->position.x + it->width >= it2->position.x && it->position.x <= it2->position.x + 8
							&& it->position.y + it->height >= it2->position.y && it->position.y <= it2->position.y + 8)
						{
							map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
							it->remove = true;
							it2->remove = true;
						}
						it2++;
					}
					for (vector<GameBackground>::iterator it2 = map.backgrounds.begin(); it2 != map.backgrounds.end();)
					{
						if (it2->id == 6)
						{
							if (it->position.x + it->width / 2 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height / 2 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
							}

						}
						it2++;
					}
					if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y - 75) && (map.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x - 100) && (map.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						it->update(map.objects);
					}
					switch (it->state)
					{
					case RCRobot::IDLE:
						switch (it->direction)
						{
						case RCRobot::LEFT:
							it->sprite.setTexture(rcrobotidleleftTexture);
							break;
						case RCRobot::RIGHT:
							it->sprite.setTexture(rcrobotidlerightTexture);
							break;
						default:
							break;
						}
						break;
					case RCRobot::WALK:
						switch (it->direction)
						{
						case RCRobot::LEFT:
							if (it->animationId == 0)
								it->sprite.setTexture(rcrobotwalkleft1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(rcrobotwalkleft2Texture);
							break;
						case RCRobot::RIGHT:
							if (it->animationId == 0)
								it->sprite.setTexture(rcrobotwalkright1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(rcrobotwalkright2Texture);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// RC Heli
			for (vector<RCHeli>::iterator it = map.rchelis.begin(); it != map.rchelis.end();)
			{
				if (it->remove)
				{
					it = map.rchelis.erase(it);
				}
				else
				{
					if (!map.player.shield)
						if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							map.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = map.bullets.begin(); it2 != map.bullets.end();)
					{
						if (it->position.x + 16 >= it2->position.x && it->position.x <= it2->position.x + 8
							&& it->position.y + 16 >= it2->position.y && it->position.y <= it2->position.y + 8)
						{
							map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
							it->remove = true;
							it2->remove = true;
						}
						it2++;
					}
					if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y - 75) && (map.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x - 100) && (map.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						if (map.player.position.x + map.player.width > it->position.x + 16 + 8)
						{
							it->directionX = RCHeli::RIGHT;
						}
						if (map.player.position.x + 16 + 8 < it->position.x + 16)
						{
							it->directionX = RCHeli::LEFT;
						}
						if (map.player.position.y + map.player.height - 10 < it->position.y + 16)
						{
							it->directionY = RCHeli::DOWN;
						}
						if (map.player.position.y - 10 > it->position.y + 16)
						{
							it->directionY = RCHeli::UP;
						}
						it->update();
					}
					if (it->counter < 5)
					{
						it->counter++;
					}
					else
					{
						if (it->animation < 1)
						{
							it->animation++;
						}
						else
						{
							it->animation = 0;
						}
						it->counter = 0;
					}
					switch (it->animation)
					{
					case 0:
						it->sprite.setTexture(rcheli1Texture);
						break;
					case 1:
						it->sprite.setTexture(rcheli2Texture);
						break;
					default:
						break;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// RC Tank
			for (vector<RCTank>::iterator it = map.rctanks.begin(); it != map.rctanks.end();)
			{
				if (it->remove)
				{
					it = map.rctanks.erase(it);
				}
				else
				{
					if (it->shoot)
					{
						switch (it->direction)
						{
						case RCTank::LEFT:
							map.bullets.push_back(Bullet(Bullet::ENEMIES, Bullet::LEFT, sf::Vector2f(it->position.x + 3, it->position.y - 2)));
							break;
						case RCTank::RIGHT:
							map.bullets.push_back(Bullet(Bullet::ENEMIES, Bullet::RIGHT, sf::Vector2f(it->position.x + 3, it->position.y - 2)));
							break;
						default:
							break;
						}
						it->shoot = false;
					}
					if (!map.player.shield)
						if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							map.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = map.bullets.begin(); it2 != map.bullets.end();)
					{
						if (it2->which == Bullet::PLAYERS)
							if (it->position.x + it->width >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
								it2->remove = true;
							}
						it2++;
					}
					for (vector<GameBackground>::iterator it2 = map.backgrounds.begin(); it2 != map.backgrounds.end();)
					{
						if (it2->id == 6)
						{
							if (it->position.x + it->width / 2 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height / 2 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								map.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
							}

						}
						it2++;
					}
					if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y - 75) && (map.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x - 100) && (map.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						it->update(map.objects);
					}
					switch (it->state)
					{
					case RCTank::IDLE:
						switch (it->direction)
						{
						case RCTank::LEFT:
							it->sprite.setTexture(rctankleft1Texture);
							break;
						case RCTank::RIGHT:
							it->sprite.setTexture(rctankright1Texture);
							break;
						default:
							break;
						}
						break;
					case RCTank::WALK:
						switch (it->direction)
						{
						case RCTank::LEFT:
							if (it->animationId == 0)
								it->sprite.setTexture(rctankleft1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(rctankleft2Texture);
							break;
						case RCTank::RIGHT:
							if (it->animationId == 0)
								it->sprite.setTexture(rctankright1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(rctankright2Texture);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// Karate boss
			for (vector<KarateBoss>::iterator it = map.karatebosses.begin(); it != map.karatebosses.end();)
			{
				if (it->remove)
				{
					it = map.karatebosses.erase(it);
				}
				else
				{
					if (!map.player.shield)
						if ((map.player.collisionPosition.y + 10 + map.player.height >= it->collisionPosition.y + 10) && (map.player.collisionPosition.y + 10 <= it->collisionPosition.y + 10 + it->height)
							&& (map.player.collisionPosition.x + 8 + map.player.width >= it->collisionPosition.x + 8) && (map.player.collisionPosition.x + 8 <= it->collisionPosition.x + 8 + it->width))
						{
							map.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = map.bullets.begin(); it2 != map.bullets.end();)
					{
						if (it->collisionPosition.x + 8 + it->width >= it2->position.x && it->collisionPosition.x + 8 <= it2->position.x + 8
							&& it->collisionPosition.y + 10 + it->height >= it2->position.y && it->collisionPosition.y + 10 <= it2->position.y + 8)
						{
							if (it->health > 0)
							{
								it->health--;
							}
							else
							{
								map.player.missioncomplete = true;
								map.explosions.push_back(Explosion(Explosion::MEDIUM, sf::Vector2f(it->position)));
								it->remove = true;
							}
							it2->remove = true;
						}
						it2++;
					}
					it->update(map.objects);
					switch (it->state)
					{
					case KarateBoss::IDLE:
						switch (it->direction)
						{
						case KarateBoss::LEFT:
							it->sprite.setTexture(bossIdleLeftTexture);
							break;
						case KarateBoss::RIGHT:
							it->sprite.setTexture(bossIdleRightTexture);
							break;
						default:
							break;
						}
						break;
					case KarateBoss::WALK:
						switch (it->direction)
						{
						case KarateBoss::LEFT:
							if (it->animationId == 0)
								it->sprite.setTexture(bossattack1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(bossattack2Texture);
							if (it->animationId == 2)
								it->sprite.setTexture(bossattack3Texture);
							if (it->animationId == 3)
								it->sprite.setTexture(bossattack4Texture);
							break;
						case KarateBoss::RIGHT:
							if (it->animationId == 0)
								it->sprite.setTexture(bossattack1Texture);
							if (it->animationId == 1)
								it->sprite.setTexture(bossattack2Texture);
							if (it->animationId == 2)
								it->sprite.setTexture(bossattack3Texture);
							if (it->animationId == 3)
								it->sprite.setTexture(bossattack4Texture);
							break;
						default:
							break;
						}
						break;
					default:
						break;
					}
					it->sprite.setPosition(it->position);
					window.draw(it->sprite);
					++it;
				}
			}

			// Bullet
			for (vector<Bullet>::iterator it = map.bullets.begin(); it != map.bullets.end();)
			{
				if (it->remove)
				{
					it = map.bullets.erase(it);
				}
				else
				{
					switch (it->direction)
					{
					case 0:
						it->sprite.setTexture(bulletLeftTexture);
						break;
					case 1:
						it->sprite.setTexture(bulletRightTexture);
						break;
					default:
						break;
					}
					if (it->which == Bullet::ENEMIES)
						if (!map.player.shield && !map.player.death)
							if ((map.player.collisionPosition.y + 10 + map.player.height >= it->position.y) && (map.player.collisionPosition.y + 10 <= it->position.y + 8)
								&& (map.player.collisionPosition.x + 8 + map.player.width >= it->position.x) && (map.player.collisionPosition.x + 8 <= it->position.x + 8))
							{
								map.player.damage = true;
								it->remove = true;
							}
					it->sprite.setPosition(it->position);
					it->update();
					window.draw(it->sprite);
					++it;
				}
			}

			// Player Control
			if (map.player.shoot)
			{
				if (map.player.shootCounter <= 0)
				{
					if (map.player.direction == map.player.LEFT)
						map.bullets.push_back(Bullet(Bullet::PLAYERS, map.player.direction, sf::Vector2f(map.player.position.x - 8, map.player.position.y + 14)));
					if (map.player.direction == map.player.RIGHT)
						map.bullets.push_back(Bullet(Bullet::PLAYERS, map.player.direction, sf::Vector2f(map.player.position.x + 32, map.player.position.y + 14)));
					map.player.shootCounter = 10;
				}
				else
				{
					map.player.shootCounter--;
				}
			}
			else
			{
				map.player.shootCounter = 0;
			}

			// Player draw
			if (map.player.visible)
			{
				if (!map.player.damage)
				{
					if (map.player.onGround)
					{
						if (!map.player.shoot)
						{
							switch (map.player.state)
							{
							case map.player.IDLE:
								switch (map.player.direction)
								{
								case map.player.RIGHT:
									map.player.sprite.setTexture(playerIdleRightTexture);
									break;
								case map.player.LEFT:
									map.player.sprite.setTexture(playerIdleLeftTexture);
									break;
								default:
									break;
								}
								break;
							case map.player.WALK:
								switch (map.player.direction)
								{
								case map.player.RIGHT:
									switch (map.player.spriteId)
									{
									case 0:
										map.player.sprite.setTexture(playerWalkRight1Texture);
										break;
									case 1:
										map.player.sprite.setTexture(playerWalkRight2Texture);
										break;
									case 2:
										map.player.sprite.setTexture(playerWalkRight3Texture);
										break;
									default:
										break;
									}
									break;
								case map.player.LEFT:
									switch (map.player.spriteId)
									{
									case 0:
										map.player.sprite.setTexture(playerWalkLeft1Texture);
										break;
									case 1:
										map.player.sprite.setTexture(playerWalkLeft2Texture);
										break;
									case 2:
										map.player.sprite.setTexture(playerWalkLeft3Texture);
										break;
									default:
										break;
									}
									break;
								default:
									break;
								}
								break;
							default:
								break;
							}
						}
						else
						{
							switch (map.player.state)
							{
							case map.player.IDLE:
								switch (map.player.direction)
								{
								case map.player.RIGHT:
									map.player.sprite.setTexture(playerIdleShootRightTexture);
									break;
								case map.player.LEFT:
									map.player.sprite.setTexture(playerIdleShootLeftTexture);
									break;
								default:
									break;
								}
								break;
							case map.player.WALK:
								switch (map.player.direction)
								{
								case map.player.RIGHT:
									switch (map.player.spriteId)
									{
									case 0:
										map.player.sprite.setTexture(playerWalkShootRight1Texture);
										break;
									case 1:
										map.player.sprite.setTexture(playerWalkShootRight2Texture);
										break;
									case 2:
										map.player.sprite.setTexture(playerWalkShootRight3Texture);
										break;
									default:
										break;
									}
									break;
								case map.player.LEFT:
									switch (map.player.spriteId)
									{
									case 0:
										map.player.sprite.setTexture(playerWalkShootLeft1Texture);
										break;
									case 1:
										map.player.sprite.setTexture(playerWalkShootLeft2Texture);
										break;
									case 2:
										map.player.sprite.setTexture(playerWalkShootLeft3Texture);
										break;
									default:
										break;
									}
									break;
								default:
									break;
								}
								break;
							default:
								break;
							}
						}
					}
					else
					{
						if (!map.player.shoot)
						{
							switch (map.player.direction)
							{
							case map.player.RIGHT:
								map.player.sprite.setTexture(playerJumpRightTexture);
								break;
							case map.player.LEFT:
								map.player.sprite.setTexture(playerJumpLeftTexture);
								break;
							default:
								break;
							}
						}
						else
						{
							switch (map.player.direction)
							{
							case map.player.RIGHT:
								map.player.sprite.setTexture(playerJumpShootRightTexture);
								break;
							case map.player.LEFT:
								map.player.sprite.setTexture(playerJumpShootLeftTexture);
								break;
							default:
								break;
							}
						}
					}
				}
				else
				{
					if (!map.player.death)
					{
						switch (map.player.direction)
						{
						case Player::LEFT:
							map.player.sprite.setTexture(playerDamageLeftTexture);
							break;
						case Player::RIGHT:
							map.player.sprite.setTexture(playerDamageRightTexture);
							break;
						default:
							break;
						}
					}
					else
					{
						if (map.player.deathpose < 1)
						{
							if (map.player.deathposeCounter < 10)
							{
								map.player.deathposeCounter++;
							}
							else
							{
								map.player.deathpose++;
								map.player.deathposeCounter = 0;
							}
						}
						switch (map.player.direction)
						{
						case Player::LEFT:
							switch (map.player.deathpose)
							{
							case 0:
								map.player.sprite.setTexture(playerDeath1LeftTexture);
								break;
							case 1:
								map.player.sprite.setTexture(playerDeath2LeftTexture);
								break;
							default:
								break;
							}
							break;
						case Player::RIGHT:
							switch (map.player.deathpose)
							{
							case 0:
								map.player.sprite.setTexture(playerDeath1RightTexture);
								break;
							case 1:
								map.player.sprite.setTexture(playerDeath2RightTexture);
								break;
							default:
								break;
							}
							break;
						default:
							break;
						}
					}

				}
			}
			map.player.sprite.setPosition(map.player.position);
			window.draw(map.player.sprite);
			if (map.player.damage)
			{
				map.player.moveLeft = false;
				map.player.moveRight = false;
				map.player.jump = false;
				map.player.shoot = false;
				if (map.player.damageCounter < 25)
				{
					map.player.damageCounter++;
				}
				else
				{
					if (playerLives > 0)
					{
						playerLives--;
						map.player.damage = false;
						map.player.damageCounter = 0;
						if (!map.player.shield)
						{
							map.player.shield = true;
						}
					}
					else
					{
						if (!map.player.gameover)
						{
							map.player.gameover = true;
						}
						map.player.death = true;
					}
				}
			}
			else
			{
				if (map.player.shield)
				{
					if (map.player.shieldCounter < 100)
					{
						if (map.player.visibilityCounter < 5)
						{
							map.player.visibilityCounter++;
						}
						else
						{
							if (map.player.visible)
							{
								map.player.visible = false;
							}
							else
							{
								map.player.visible = true;
							}
							map.player.visibilityCounter = 0;
						}
						map.player.shieldCounter++;
					}
					else
					{
						map.player.shield = false;
						map.player.visible = true;
						map.player.shieldCounter = 0;
					}
				}
			}
			map.player.update(map.objects);
			// Game Over
			if (map.player.gameover)
			{
				window.setView(menuView);
				sf::Text gameoverText;
				gameoverText.setCharacterSize(128);
				gameoverText.setFont(font);
				gameoverText.setString("GAME OVER");
				//gameoverText.setColor(sf::Color::Red);
				gameoverText.setPosition(512 - gameoverText.getLocalBounds().width / 2, 384 - gameoverText.getLocalBounds().height);
				window.draw(gameoverText);
				if (map.player.gameoverCounter < 150)
				{
					map.player.gameoverCounter++;
				}
				else
				{
					screen = MENU;
					play_music(0);
					map.player.gameoverCounter = 0;
				}
			}
			// Mission complete
			if (map.player.missioncomplete)
			{
				window.setView(menuView);
				sf::Text missioncompleteText;
				missioncompleteText.setCharacterSize(128);
				missioncompleteText.setFont(font);
				missioncompleteText.setString("MISSION COMPLETE");
				//missioncompleteText.setColor(sf::Color::Green);
				missioncompleteText.setPosition(512 - missioncompleteText.getLocalBounds().width / 2, 384 - missioncompleteText.getLocalBounds().height);
				window.draw(missioncompleteText);
				if (map.player.missioncompleteCounter < 150)
				{
					map.player.missioncompleteCounter++;
				}
				else
				{
					screen = MENU;
					play_music(0);
					map.player.missioncompleteCounter = 0;
				}
			}
			// Player status
			{
				window.setView(statusView);
				sf::Sprite heart;
				heart.setTexture(heartTexture);
				for (int i = 0; i < playerLives; i++)
				{
					heart.setPosition(5 + (i * 20), 5);
					window.draw(heart);
				}
			}
			break;
		default:
			break;
		}
		if (screen == GAME || screen == LOGO)
		{
			window.setMouseCursorVisible(false);
		}
		else
		{
			window.setMouseCursorVisible(true);
		}
		window.display();
	}

	return 0;
}