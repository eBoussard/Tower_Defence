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

   al_register_event_source (eventQueue, al_get_display_event_source (Display));
   al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));
   al_register_event_source (eventQueue, al_get_keyboard_event_source());
   al_start_timer(framerateTimer);
   al_set_window_title (Display, "TowerDefence");



   
   while(!Quit)
      {
	 ALLEGRO_EVENT Event;
	 al_set_target_bitmap (al_get_backbuffer (Display));

	 if (! al_get_next_event(eventQueue, &Event))
	    {
	       al_wait_for_event(eventQueue, &Event);
	       redraw = true;
	    }

	 else
	    {
	       redraw = false;
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


	 if (redraw == true)
	    {
	       board.Draw();
	       scoreboard.Draw();

	       enemyStepCounter = al_get_timer_count(framerateTimer) / FPS;
	       engine.moveEnemy(board, enemyStepCounter);
	       rules.isEnemyShootable(board);
	       board.removeEnemy();
	    }


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

