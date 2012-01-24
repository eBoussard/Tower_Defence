#include <iostream>

#include <Player.hpp>
#include <Board.hpp>
#include <Tower.hpp>
#include <Enemy.hpp>
#include <Rules.hpp>
#include <Engine.hpp>
#include <ScoreBoard.hpp>
#include <definitions.hpp>
using namespace std;

bool mouseNClick (pixelPosition &x, pixelPosition &y, unsigned int n, bool &isDown)
{
	ALLEGRO_MOUSE_STATE mouseState;
	al_get_mouse_state (&mouseState);

	if (mouseState.buttons &n)
	{
		isDown = true;
		return false;
	}

	if (isDown == true)
	{
		x = al_get_mouse_state_axis (&mouseState, 0);
		y = al_get_mouse_state_axis (&mouseState, 1);
		isDown = false;
		return true;
	}
	return false;
}

bool mouseOneClick (pixelPosition &x, pixelPosition &y)
{
	static bool isDown = false;
	return mouseNClick(x, y, 1, isDown);
}

bool mouseTwoClick (pixelPosition &x, pixelPosition &y)
{
	static bool isDown = false;
	return mouseNClick(x, y, 2, isDown);
}


int main()
{
	ALLEGRO_DISPLAY *Display = NULL;
	ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
	ALLEGRO_TIMER *framerateTimer = NULL;
	ALLEGRO_TIMER *enemyMovementTimer = NULL;
	ALLEGRO_TIMER *towerShootingTimer = NULL;

	const unsigned int FPS = 30;
	bool gameStarted = false;
	bool Quit = false;
	bool redraw = false;
	pixelPosition x, y;
	gridPosition gridX, gridY;
	const unsigned int displayWidth = 1280;
	const unsigned int displayHeight = 720;
	unsigned int enemyStepCounter = 0;

	Player player;
	ScoreBoard scoreboard(player);
	Rules rules;
	Board board;
	Engine engine;
	Enemy *pEnemy = NULL;
	Tower *pTower = NULL;

	if (!al_init())
	{
		cout << "main.cpp: al_init" << endl;
		return 1;
	}

	if (!al_install_mouse())
	{
		cout << "main.cpp: al_install_mouse" << endl;
		return 1;
	}

	if (!al_install_keyboard())
	{
		cout << "main.cpp: al_install_keyboard" << endl;
		return 1;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue)
	{
		cout << "main.cpp: al_create_event_queue" << endl;
		return 1;
	}

	framerateTimer = al_create_timer (1.0 / FPS);
	if (!framerateTimer)
	{
		cout << "main.cpp: al_create_timer" << endl;
		return 1;
	}

	Display = al_create_display (displayWidth, displayHeight);
	if (!Display)
	{
		cout << "main.cpp: al_create_display" << endl;
		return 1;
	}

	enemyMovementTimer = al_create_timer (1.0);
	towerShootingTimer = al_create_timer (0.5);

	al_register_event_source (eventQueue, al_get_timer_event_source (enemyMovementTimer));
	al_register_event_source (eventQueue, al_get_timer_event_source (towerShootingTimer));
	al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

	al_register_event_source (eventQueue, al_get_display_event_source (Display));
	al_register_event_source (eventQueue, al_get_keyboard_event_source());

	al_set_window_title (Display, "TowerDefence");

	al_start_timer (enemyMovementTimer);
	al_start_timer (towerShootingTimer);
	al_start_timer(framerateTimer);


	while(!Quit)
	{
		ALLEGRO_EVENT Event;
		al_set_target_bitmap (al_get_backbuffer (Display));

		if (! al_get_next_event(eventQueue, &Event))
		{
			al_wait_for_event(eventQueue, &Event);
		}


		if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}

		if (Event.type == ALLEGRO_EVENT_KEY_UP)
		{
			if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				Quit = true;
			}

			if (Event.keyboard.keycode == ALLEGRO_KEY_E)
			{
				pEnemy = new Enemy(0, board.getEntranceTile());
				board.addEnemy(pEnemy, enemyStepCounter);
				pEnemy = NULL;
			}
		}


		enemyStepCounter = al_get_timer_count(framerateTimer) / FPS;

		static int drawCounter = 0;
		static int moveCounter = 0;
		static int shootCounter = 0;
		static int summonCounter = 0;

		// drawCounter == 5 gånger per sekund (30/6)
		// moveCounter == 2 gånger per sekund (30/15)
		// shootCounter == en gång per sekund
		// summonCounter == en gång varannan sekund (60)

		if (Event.timer.source == framerateTimer)
		{
			++drawCounter;
			++moveCounter;
			++shootCounter;
			++summonCounter;
			if (drawCounter == 6)
			{
				board.Draw();
				scoreboard.Draw();
				board.removeEnemy();
				drawCounter = 0;
			}

			if (moveCounter == 15)
			{
				engine.moveEnemy(board, enemyStepCounter);
				moveCounter = 0;
			}

			if (shootCounter == 30)
			{
				rules.isEnemyShootable(board);
				shootCounter = 0;
			}

			if (summonCounter == 90)
			{
				pEnemy = new Enemy(0, board.getEntranceTile());
				board.addEnemy(pEnemy, enemyStepCounter);
				summonCounter = 0;
				pEnemy = NULL;
			}
		}

		//TODO: Player får pengar när Enemy dör
		// Gör en metod i Board

		if (mouseOneClick(x, y))
		{
			board.mouseClick(x, y);
			scoreboard.ButtonClicked(x, y);

			if (scoreboard.towerButtonActive())
			{
				if (board.getTileCoordinates(x, y, gridX, gridY))
				{
					if (rules.towerPlacementValid(board, *pTower, gridX, gridY))
					{
						if (player.getMoney() >= Tower::getPrice())
						{
							pTower = new Tower(gridX, gridY);
							board.addTower(pTower);
							player.setMoney(player.getMoney() - Tower::getPrice());
						}
					}
				}
			}
		}

		if (mouseTwoClick(x, y))
		{
			if (board.getTileCoordinates(x, y, gridX, gridY))
			{
				if (board.tileHasTower(gridX, gridY))
				{
					board.removeTower(gridX, gridY);
					player.setMoney(player.getMoney() + Tower::getSellValue());
				}
			}
		}
		al_flip_display();
	}
}

