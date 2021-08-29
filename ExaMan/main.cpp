#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

void resetGame();

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

// Item
#include "Game/Data/Item/heart.h"
sf::Texture heartTexture;
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
#include "Game/Music.h"
// Font
#include "Game/Data/Font/COMPUTERRobot.h"
// Background image
#include "Game/Data/backgroundimage.h"
sf::Texture backgroundTexture;
// Logo
#include "Game/Data/logo.h"
sf::Texture logoTexture;

// Font
sf::Font font;

#include "Game/Screens/ScreenEnum.h";
#include "Game/Screens/MenuScreen.h";
#include "Game/Screens/QuitScreen.h";
#include "Game/Screens/PauseScreen.h";
#include "Game/Screens/AboutGameScreen.h";
#include "Game/Screens/CreditsScreen.h";

MenuScreen menuScreen;
QuitScreen quitScreen;
PauseScreen pauseScreen;
AboutGameScreen aboutGameScreen;
CreditsScreen creditsScreen;

// Map
Map gameMap(0);
int playerLives = 3;

int main()
{
	int logoCounter = 0;
	play_music(0);

	sf::RenderWindow window(sf::VideoMode(1024, 768), "EXA MAN", sf::Style::Default);

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
	font.loadFromMemory(COMPUTERRobot_ttf, COMPUTERRobot_ttf_size);

	// Screens
	menuScreen = MenuScreen(font);
	quitScreen = QuitScreen(font);
	pauseScreen = PauseScreen(font);
	aboutGameScreen = AboutGameScreen(font);
	creditsScreen = CreditsScreen(font);

	// Textures
	// Background
	backgroundTexture.loadFromMemory(backgroundimage_png, backgroundimage_png_size);
	// Logo
	logoTexture.loadFromMemory(logo_jpg, logo_jpg_size);
	
	loadButtonImages();
	loadPlayerImages();
	loadKarateBossImages();

	// Item
	heartTexture.loadFromMemory(heart_png, heart_png_size);

	loadRCHeliImages();
	loadRCRobotImages();
	loadRCTankImages();

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
	
	loadBulletImages();

	// Explosion
	smallexp0Texture.loadFromMemory(smallexp0_png, smallexp0_png_size);
	smallexp1Texture.loadFromMemory(smallexp1_png, smallexp1_png_size);
	smallexp2Texture.loadFromMemory(smallexp2_png, smallexp2_png_size);
	smallexp3Texture.loadFromMemory(smallexp3_png, smallexp3_png_size);
	mediumexp0Texture.loadFromMemory(mediumexp0_png, mediumexp0_png_size);
	mediumexp1Texture.loadFromMemory(mediumexp1_png, mediumexp1_png_size);
	mediumexp2Texture.loadFromMemory(mediumexp2_png, mediumexp2_png_size);
	mediumexp3Texture.loadFromMemory(mediumexp3_png, mediumexp3_png_size);

	initButtons();

	// Window
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			updateButtons(window, event);

			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::A:
					if (!gameMap.player.damage)
						gameMap.player.moveLeft = true;
					break;
				case sf::Keyboard::D:
					if (!gameMap.player.damage)
						gameMap.player.moveRight = true;
					break;
				case sf::Keyboard::J:
					if (gameMap.player.onGround)
						if (!gameMap.player.damage)
							gameMap.player.jump = true;
					break;
				case sf::Keyboard::K:
					if (!gameMap.player.damage)
						gameMap.player.shoot = true;
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
					gameMap.player.moveLeft = false;
					gameMap.player.getLastDirection = gameMap.player.LEFT;
					break;
				case sf::Keyboard::D:
					gameMap.player.moveRight = false;
					gameMap.player.getLastDirection = gameMap.player.RIGHT;
					break;
				case sf::Keyboard::J:
					gameMap.player.jump = false;
					break;
				case sf::Keyboard::K:
					gameMap.player.shoot = false;
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
			creditsScreen.draw(window);
			break;
		case EXIT:
			window.setView(menuView);
			quitScreen.draw(window);
			break;
		case PAUSE:
			window.setView(menuView);
			pauseScreen.draw(window);
			break;
		case ABOUT:
			aboutGameScreen.draw(window);
			break;
		case MENU:
			window.setView(menuView);
			menuScreen.draw(window);
			break;
		case GAME:
			// View
			playerView.setCenter(sf::Vector2f(gameMap.player.position.x + 10, gameMap.player.position.y));

			window.setView(playerView);

			// Background
			for (vector<GameBackground>::iterator it = gameMap.backgrounds.begin(); it != gameMap.backgrounds.end();)
			{
				if (it->remove)
				{
					it = gameMap.backgrounds.erase(it);
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
						if (!gameMap.player.shield)
							if (gameMap.player.collisionPosition.x + (gameMap.player.width) + 7 > it->position.x && gameMap.player.collisionPosition.x + 8 < it->position.x + 16
								&& gameMap.player.collisionPosition.y + (gameMap.player.height) > it->position.y && gameMap.player.collisionPosition.y < it->position.y + 16)
							{
								gameMap.player.damage = true;
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
			for (vector<GameObject>::iterator it = gameMap.objects.begin(); it != gameMap.objects.end();)
			{
				if (it->remove)
				{
					it = gameMap.objects.erase(it);
				}
				else
				{
					switch (it->id)
					{
					case 0:
						it->sprite.setTexture(groundTexture);
						break;
					case 1:
						for (vector<Bullet>::iterator it2 = gameMap.bullets.begin(); it2 != gameMap.bullets.end();)
						{
							if (it->position.x + 16 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + 16 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
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
						if (!gameMap.player.shield)
							if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
								&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
							{
								playerLives = 0;
								gameMap.player.damage = true;
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
						if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							gameMap = Map(1);
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
			for (vector<Pickup>::iterator it = gameMap.pickups.begin(); it != gameMap.pickups.end();)
			{
				if (it->remove)
				{
					it = gameMap.pickups.erase(it);
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
					if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
						&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
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
			for (vector<Explosion>::iterator it = gameMap.explosions.begin(); it != gameMap.explosions.end();)
			{
				if (it->remove)
				{
					it = gameMap.explosions.erase(it);
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
			for (vector<RCRobot>::iterator it = gameMap.rcrobots.begin(); it != gameMap.rcrobots.end();)
			{
				if (it->remove)
				{
					it = gameMap.rcrobots.erase(it);
				}
				else
				{
					if (!gameMap.player.shield)
						if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							gameMap.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = gameMap.bullets.begin(); it2 != gameMap.bullets.end();)
					{
						if (it->position.x + it->width >= it2->position.x && it->position.x <= it2->position.x + 8
							&& it->position.y + it->height >= it2->position.y && it->position.y <= it2->position.y + 8)
						{
							gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
							it->remove = true;
							it2->remove = true;
						}
						it2++;
					}
					for (vector<GameBackground>::iterator it2 = gameMap.backgrounds.begin(); it2 != gameMap.backgrounds.end();)
					{
						if (it2->id == 6)
						{
							if (it->position.x + it->width / 2 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height / 2 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
							}

						}
						it2++;
					}
					if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y - 75) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x - 100) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						it->update(gameMap.objects);
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
			for (vector<RCHeli>::iterator it = gameMap.rchelis.begin(); it != gameMap.rchelis.end();)
			{
				if (it->remove)
				{
					it = gameMap.rchelis.erase(it);
				}
				else
				{
					if (!gameMap.player.shield)
						if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							gameMap.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = gameMap.bullets.begin(); it2 != gameMap.bullets.end();)
					{
						if (it->position.x + 16 >= it2->position.x && it->position.x <= it2->position.x + 8
							&& it->position.y + 16 >= it2->position.y && it->position.y <= it2->position.y + 8)
						{
							gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
							it->remove = true;
							it2->remove = true;
						}
						it2++;
					}
					if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y - 75) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x - 100) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						if (gameMap.player.position.x + gameMap.player.width > it->position.x + 16 + 8)
						{
							it->directionX = RCHeli::RIGHT;
						}
						if (gameMap.player.position.x + 16 + 8 < it->position.x + 16)
						{
							it->directionX = RCHeli::LEFT;
						}
						if (gameMap.player.position.y + gameMap.player.height - 10 < it->position.y + 16)
						{
							it->directionY = RCHeli::DOWN;
						}
						if (gameMap.player.position.y - 10 > it->position.y + 16)
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
			for (vector<RCTank>::iterator it = gameMap.rctanks.begin(); it != gameMap.rctanks.end();)
			{
				if (it->remove)
				{
					it = gameMap.rctanks.erase(it);
				}
				else
				{
					if (it->shoot)
					{
						switch (it->direction)
						{
						case RCTank::LEFT:
							gameMap.bullets.push_back(Bullet(Bullet::ENEMIES, Bullet::LEFT, sf::Vector2f(it->position.x + 3, it->position.y - 2)));
							break;
						case RCTank::RIGHT:
							gameMap.bullets.push_back(Bullet(Bullet::ENEMIES, Bullet::RIGHT, sf::Vector2f(it->position.x + 3, it->position.y - 2)));
							break;
						default:
							break;
						}
						it->shoot = false;
					}
					if (!gameMap.player.shield)
						if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 16)
							&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 16))
						{
							gameMap.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = gameMap.bullets.begin(); it2 != gameMap.bullets.end();)
					{
						if (it2->which == Bullet::PLAYERS)
							if (it->position.x + it->width >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
								it2->remove = true;
							}
						it2++;
					}
					for (vector<GameBackground>::iterator it2 = gameMap.backgrounds.begin(); it2 != gameMap.backgrounds.end();)
					{
						if (it2->id == 6)
						{
							if (it->position.x + it->width / 2 >= it2->position.x && it->position.x <= it2->position.x + 8
								&& it->position.y + it->height / 2 >= it2->position.y && it->position.y <= it2->position.y + 8)
							{
								gameMap.explosions.push_back(Explosion(Explosion::SMALL, sf::Vector2f(it->position)));
								it->remove = true;
							}

						}
						it2++;
					}
					if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y - 75) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 75 + 16)
						&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x - 100) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 100 + 16))
					{
						it->update(gameMap.objects);
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
			for (vector<KarateBoss>::iterator it = gameMap.karatebosses.begin(); it != gameMap.karatebosses.end();)
			{
				if (it->remove)
				{
					it = gameMap.karatebosses.erase(it);
				}
				else
				{
					if (!gameMap.player.shield)
						if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->collisionPosition.y + 10) && (gameMap.player.collisionPosition.y + 10 <= it->collisionPosition.y + 10 + it->height)
							&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->collisionPosition.x + 8) && (gameMap.player.collisionPosition.x + 8 <= it->collisionPosition.x + 8 + it->width))
						{
							gameMap.player.damage = true;
						}
					for (vector<Bullet>::iterator it2 = gameMap.bullets.begin(); it2 != gameMap.bullets.end();)
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
								gameMap.player.missioncomplete = true;
								gameMap.explosions.push_back(Explosion(Explosion::MEDIUM, sf::Vector2f(it->position)));
								it->remove = true;
							}
							it2->remove = true;
						}
						it2++;
					}
					it->update(gameMap.objects);
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
			for (vector<Bullet>::iterator it = gameMap.bullets.begin(); it != gameMap.bullets.end();)
			{
				if (it->remove)
				{
					it = gameMap.bullets.erase(it);
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
						if (!gameMap.player.shield && !gameMap.player.death)
							if ((gameMap.player.collisionPosition.y + 10 + gameMap.player.height >= it->position.y) && (gameMap.player.collisionPosition.y + 10 <= it->position.y + 8)
								&& (gameMap.player.collisionPosition.x + 8 + gameMap.player.width >= it->position.x) && (gameMap.player.collisionPosition.x + 8 <= it->position.x + 8))
							{
								gameMap.player.damage = true;
								it->remove = true;
							}
					it->sprite.setPosition(it->position);
					it->update();
					window.draw(it->sprite);
					++it;
				}
			}

			// Player Control
			if (gameMap.player.shoot)
			{
				if (gameMap.player.shootCounter <= 0)
				{
					if (gameMap.player.direction == gameMap.player.LEFT)
						gameMap.bullets.push_back(Bullet(Bullet::PLAYERS, gameMap.player.direction, sf::Vector2f(gameMap.player.position.x - 8, gameMap.player.position.y + 14)));
					if (gameMap.player.direction == gameMap.player.RIGHT)
						gameMap.bullets.push_back(Bullet(Bullet::PLAYERS, gameMap.player.direction, sf::Vector2f(gameMap.player.position.x + 32, gameMap.player.position.y + 14)));
					gameMap.player.shootCounter = 10;
				}
				else
				{
					gameMap.player.shootCounter--;
				}
			}
			else
			{
				gameMap.player.shootCounter = 0;
			}

			// Player draw
			if (gameMap.player.visible)
			{
				if (!gameMap.player.damage)
				{
					if (gameMap.player.onGround)
					{
						if (!gameMap.player.shoot)
						{
							switch (gameMap.player.state)
							{
							case gameMap.player.IDLE:
								switch (gameMap.player.direction)
								{
								case gameMap.player.RIGHT:
									gameMap.player.sprite.setTexture(playerIdleRightTexture);
									break;
								case gameMap.player.LEFT:
									gameMap.player.sprite.setTexture(playerIdleLeftTexture);
									break;
								default:
									break;
								}
								break;
							case gameMap.player.WALK:
								switch (gameMap.player.direction)
								{
								case gameMap.player.RIGHT:
									switch (gameMap.player.spriteId)
									{
									case 0:
										gameMap.player.sprite.setTexture(playerWalkRight1Texture);
										break;
									case 1:
										gameMap.player.sprite.setTexture(playerWalkRight2Texture);
										break;
									case 2:
										gameMap.player.sprite.setTexture(playerWalkRight3Texture);
										break;
									default:
										break;
									}
									break;
								case gameMap.player.LEFT:
									switch (gameMap.player.spriteId)
									{
									case 0:
										gameMap.player.sprite.setTexture(playerWalkLeft1Texture);
										break;
									case 1:
										gameMap.player.sprite.setTexture(playerWalkLeft2Texture);
										break;
									case 2:
										gameMap.player.sprite.setTexture(playerWalkLeft3Texture);
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
							switch (gameMap.player.state)
							{
							case gameMap.player.IDLE:
								switch (gameMap.player.direction)
								{
								case gameMap.player.RIGHT:
									gameMap.player.sprite.setTexture(playerIdleShootRightTexture);
									break;
								case gameMap.player.LEFT:
									gameMap.player.sprite.setTexture(playerIdleShootLeftTexture);
									break;
								default:
									break;
								}
								break;
							case gameMap.player.WALK:
								switch (gameMap.player.direction)
								{
								case gameMap.player.RIGHT:
									switch (gameMap.player.spriteId)
									{
									case 0:
										gameMap.player.sprite.setTexture(playerWalkShootRight1Texture);
										break;
									case 1:
										gameMap.player.sprite.setTexture(playerWalkShootRight2Texture);
										break;
									case 2:
										gameMap.player.sprite.setTexture(playerWalkShootRight3Texture);
										break;
									default:
										break;
									}
									break;
								case gameMap.player.LEFT:
									switch (gameMap.player.spriteId)
									{
									case 0:
										gameMap.player.sprite.setTexture(playerWalkShootLeft1Texture);
										break;
									case 1:
										gameMap.player.sprite.setTexture(playerWalkShootLeft2Texture);
										break;
									case 2:
										gameMap.player.sprite.setTexture(playerWalkShootLeft3Texture);
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
						if (!gameMap.player.shoot)
						{
							switch (gameMap.player.direction)
							{
							case gameMap.player.RIGHT:
								gameMap.player.sprite.setTexture(playerJumpRightTexture);
								break;
							case gameMap.player.LEFT:
								gameMap.player.sprite.setTexture(playerJumpLeftTexture);
								break;
							default:
								break;
							}
						}
						else
						{
							switch (gameMap.player.direction)
							{
							case gameMap.player.RIGHT:
								gameMap.player.sprite.setTexture(playerJumpShootRightTexture);
								break;
							case gameMap.player.LEFT:
								gameMap.player.sprite.setTexture(playerJumpShootLeftTexture);
								break;
							default:
								break;
							}
						}
					}
				}
				else
				{
					if (!gameMap.player.death)
					{
						switch (gameMap.player.direction)
						{
						case Player::LEFT:
							gameMap.player.sprite.setTexture(playerDamageLeftTexture);
							break;
						case Player::RIGHT:
							gameMap.player.sprite.setTexture(playerDamageRightTexture);
							break;
						default:
							break;
						}
					}
					else
					{
						if (gameMap.player.deathpose < 1)
						{
							if (gameMap.player.deathposeCounter < 10)
							{
								gameMap.player.deathposeCounter++;
							}
							else
							{
								gameMap.player.deathpose++;
								gameMap.player.deathposeCounter = 0;
							}
						}
						switch (gameMap.player.direction)
						{
						case Player::LEFT:
							switch (gameMap.player.deathpose)
							{
							case 0:
								gameMap.player.sprite.setTexture(playerDeath1LeftTexture);
								break;
							case 1:
								gameMap.player.sprite.setTexture(playerDeath2LeftTexture);
								break;
							default:
								break;
							}
							break;
						case Player::RIGHT:
							switch (gameMap.player.deathpose)
							{
							case 0:
								gameMap.player.sprite.setTexture(playerDeath1RightTexture);
								break;
							case 1:
								gameMap.player.sprite.setTexture(playerDeath2RightTexture);
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
			gameMap.player.sprite.setPosition(gameMap.player.position);
			window.draw(gameMap.player.sprite);
			if (gameMap.player.damage)
			{
				gameMap.player.moveLeft = false;
				gameMap.player.moveRight = false;
				gameMap.player.jump = false;
				gameMap.player.shoot = false;
				if (gameMap.player.damageCounter < 25)
				{
					gameMap.player.damageCounter++;
				}
				else
				{
					if (playerLives > 0)
					{
						playerLives--;
						gameMap.player.damage = false;
						gameMap.player.damageCounter = 0;
						if (!gameMap.player.shield)
						{
							gameMap.player.shield = true;
						}
					}
					else
					{
						if (!gameMap.player.gameover)
						{
							gameMap.player.gameover = true;
						}
						gameMap.player.death = true;
					}
				}
			}
			else
			{
				if (gameMap.player.shield)
				{
					if (gameMap.player.shieldCounter < 100)
					{
						if (gameMap.player.visibilityCounter < 5)
						{
							gameMap.player.visibilityCounter++;
						}
						else
						{
							if (gameMap.player.visible)
							{
								gameMap.player.visible = false;
							}
							else
							{
								gameMap.player.visible = true;
							}
							gameMap.player.visibilityCounter = 0;
						}
						gameMap.player.shieldCounter++;
					}
					else
					{
						gameMap.player.shield = false;
						gameMap.player.visible = true;
						gameMap.player.shieldCounter = 0;
					}
				}
			}
			gameMap.player.update(gameMap.objects);
			// Game Over
			if (gameMap.player.gameover)
			{
				window.setView(menuView);
				sf::Text gameoverText;
				gameoverText.setCharacterSize(128);
				gameoverText.setFont(font);
				gameoverText.setString("GAME OVER");
				//gameoverText.setColor(sf::Color::Red);
				gameoverText.setPosition(512 - gameoverText.getLocalBounds().width / 2, 384 - gameoverText.getLocalBounds().height);
				window.draw(gameoverText);
				if (gameMap.player.gameoverCounter < 150)
				{
					gameMap.player.gameoverCounter++;
				}
				else
				{
					screen = MENU;
					play_music(0);
					gameMap.player.gameoverCounter = 0;
				}
			}
			// Mission complete
			if (gameMap.player.missioncomplete)
			{
				window.setView(menuView);
				sf::Text missioncompleteText;
				missioncompleteText.setCharacterSize(128);
				missioncompleteText.setFont(font);
				missioncompleteText.setString("MISSION COMPLETE");
				//missioncompleteText.setColor(sf::Color::Green);
				missioncompleteText.setPosition(512 - missioncompleteText.getLocalBounds().width / 2, 384 - missioncompleteText.getLocalBounds().height);
				window.draw(missioncompleteText);
				if (gameMap.player.missioncompleteCounter < 150)
				{
					gameMap.player.missioncompleteCounter++;
				}
				else
				{
					screen = MENU;
					play_music(0);
					gameMap.player.missioncompleteCounter = 0;
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

void resetGame() {
	gameMap = Map(0);
	playerLives = 3;
}