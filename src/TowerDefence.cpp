#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>
#include <list>

#include <Player.hpp>
#include <Board.hpp>
#include <Tower.hpp>
#include <Ammunition.hpp>
#include <Enemy.hpp>
#include <Rules.hpp>
#include <Engine.hpp>
#include <UI.hpp>
#include <ScoreBoard.hpp>
#include <definitions.hpp>
using namespace std;








bool mouseNClick (pixelPosition & x, pixelPosition & y, unsigned int n, bool & isDown)
{
  ALLEGRO_MOUSE_STATE mouseState;

  al_get_mouse_state (&mouseState);




  if (mouseState.buttons & n)
    {
      isDown = true;
      return false;
    }



  if (isDown)
    {
      x = al_get_mouse_state_axis (&mouseState, 0);
      y = al_get_mouse_state_axis (&mouseState, 1);
      isDown = false;
      return true;
    }
  return false;
}



bool mouseOneClick (pixelPosition & x, pixelPosition & y)
{
  static bool isDown = false;
  return mouseNClick(x, y, 1, isDown);
}



bool mouseTwoClick (pixelPosition & x, pixelPosition & y)
{
  static bool isDown = false;
  return mouseNClick(x, y, 2, isDown);
}









int main()
{
  ALLEGRO_DISPLAY *Display = NULL;

  ALLEGRO_EVENT_QUEUE *eventQueue = NULL;

  ALLEGRO_TIMER *framerateTimer = NULL;




  const unsigned int FPS = 5;



  list <Tower *> Towers;

  Player player;

  ScoreBoard scoreboard(player);

  Rules rules;

  Board board;

  UI ui;

  Enemy *pEnemy = NULL;




  if (!al_init())
    {
      cout << "Failed to initialize Allegro in TowerDefence.cpp" << endl;
      return 1;
    }



  if (!al_install_mouse())
    {
      cout << "mouse fail\n";
      return 1;
    }



  if (!al_install_keyboard())
    {
      cout << "keyboard fail\n";
      return 1;
    }



  eventQueue = al_create_event_queue();
  if (!eventQueue)
    {
      cout << "eventQueue fail\n";
      return 1;
    }



  framerateTimer = al_create_timer (1.0 / FPS);
  if (!framerateTimer)
    {
      cout << "Framerate timer fail\n";
      return 1;
    }



  Display = al_create_display (ui.displayWidth, ui.displayHeight);

  al_set_window_title (Display, "MENU");



  al_register_event_source (eventQueue, al_get_display_event_source (Display));

  al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

  al_register_event_source (eventQueue, al_get_keyboard_event_source());



  al_start_timer(framerateTimer);

  al_set_target_bitmap(al_get_backbuffer(Display)); 














  bool gameStarted = false;

  bool Quit = false;

  unsigned int enemyStepCounter = 0;

  pixelPosition x, y;
      
  gridPosition gridX, gridY; 











  while(!Quit)
    {
      ALLEGRO_EVENT Event;




      al_wait_for_event(eventQueue, &Event);


      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
	  break;
	}






      
      if (Event.type == ALLEGRO_EVENT_KEY_UP)
	{
	  if (Event.keyboard.keycode == ALLEGRO_KEY_S)
	    {
	      if (gameStarted == false)
		{
		  al_set_window_title (Display, "GAME");

		  gameStarted = true;
		}


	      else if (gameStarted == true)
		{
		  al_set_window_title (Display, "MENU");

		  gameStarted = false;

		  al_clear_to_color (al_map_rgb (0, 0, 0));
		}
	    }





	  if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
	    {
	      Quit = true;
	    }

	  if ((Event.keyboard.keycode == ALLEGRO_KEY_E) && (pEnemy == NULL))
	    {
	      pEnemy = new Enemy(0, board.getEntranceTile());
	    }
	}
      



      if (gameStarted == true)
	{
	  board.Draw();
	  scoreboard.Draw();
	  if (pEnemy != NULL) pEnemy->Draw();
	}

	

      for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
	{
	  Tower * pTower = *it;
	  pTower->Draw();
	}




      if (pEnemy != NULL)
	{
	  if ((gridX == 19) && (gridY == board.getExitTile()))
	    {
	      delete pEnemy;
	      pEnemy = NULL;
	      enemyStepCounter = 0;
	      gridX = 0;
	      gridY = 0;
	    }

	  else
	    {
	      board.getEnemyPosition(enemyStepCounter, gridX, gridY);
	      
	      pEnemy->setXIndex(gridX);
	      pEnemy->setYIndex(gridY);
	      
	      ++enemyStepCounter;

	      cout << "E-X: " << gridX << "\nE-Y: " << gridY << endl;
	    }
	}






      if (mouseOneClick(x, y))
	{
	  board.mouseClick(x, y);

	  scoreboard.ButtonClicked(x, y);

	  if (scoreboard.towerButtonActive())
	    {	   
	      if (board.getTileCoordinates(x, y, gridX, gridY))
		{
		  if (rules.towerPlacementValid(board, Towers, gridX, gridY))
		    {
		      //Creates a new tower
		      Tower * pTower = new Tower(gridX, gridY);

		      //and puts it in the list
		      Towers.push_back(pTower);

		      cout << "new tower created on\nT-GX: " << gridX << "\nT-GY: " << gridY << endl;

		      cout << "Amount of towers: " << Towers.size() << endl;
		    }
		} 
	    } 
	}




      if (mouseTwoClick(x, y))
	{
	  if (board.getTileCoordinates(x, y, gridX, gridY))
	    {
	      for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
		{
		  Tower *pTower = *it;

		  if (pTower->onTile(gridX, gridY))
		    {
		      delete pTower;

		      Towers.erase(it);

		      break;
		    }
		}
	    }
	}








      al_flip_display();
    }
}

