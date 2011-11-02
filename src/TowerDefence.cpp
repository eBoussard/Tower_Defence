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



  enum KEYS {KEY_S, KEY_ESCAPE, KEY_E, KEY_LEFT, KEY_RIGHT, KEY_DOWN, KEY_UP};

  bool Key[7] = {false, false, false, false, false, false, false};

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



  Display = al_create_display (ui.menuDisplayWidth, ui.menuDisplayHeight);



  al_register_event_source (eventQueue, al_get_display_event_source (Display));

  al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

  al_register_event_source (eventQueue, al_get_keyboard_event_source());



  al_start_timer(framerateTimer);

  al_set_target_bitmap(al_get_backbuffer(Display)); 




  bool displayResizable = true;

  bool Quit = false;

  unsigned int enemyStepCounter = 0;

  while(!Quit)
    {
      ALLEGRO_EVENT Event;

      // x and y are pixel coordinates, gridX and
      // gridY are grid coordinates
      pixelPosition x, y;
      gridPosition gridX, gridY; 




      al_wait_for_event(eventQueue, &Event);


      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
	  break;
	}



      if (Event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
	  if (Event.keyboard.keycode == ALLEGRO_KEY_S) Key[KEY_S] = true;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) Key[KEY_ESCAPE] = true;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_E) Key[KEY_E] = true;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_LEFT) Key[KEY_LEFT] = true;
	    
	  if (Event.keyboard.keycode == ALLEGRO_KEY_RIGHT) Key[KEY_RIGHT] = true;
	    
	  if (Event.keyboard.keycode == ALLEGRO_KEY_DOWN) Key[KEY_DOWN] = true;
	    
	  if (Event.keyboard.keycode == ALLEGRO_KEY_UP) Key[KEY_UP] = true;
	}



      
      if (Event.type == ALLEGRO_EVENT_KEY_UP)
	{
	  if (Event.keyboard.keycode == ALLEGRO_KEY_S) Key[KEY_S] = false;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
	    {
	      Key[KEY_ESCAPE] = false;
	      Quit = true;
	    }

	  if (Event.keyboard.keycode == ALLEGRO_KEY_E) Key[KEY_E] = false;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_LEFT) Key[KEY_LEFT] = false;
	    
	  if (Event.keyboard.keycode == ALLEGRO_KEY_RIGHT) Key[KEY_RIGHT] = false;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_DOWN) Key[KEY_DOWN] = false;
	    
	  if (Event.keyboard.keycode == ALLEGRO_KEY_UP) Key[KEY_UP] = false;	    
	}
      



      if (al_get_display_width (Display) == 1280)
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




      if (Key[KEY_E] && pEnemy == NULL)
	{
	  pEnemy = new Enemy(0, board.getEntranceTile());
	}




      // if (pEnemy != NULL && rules.enemyPositionValid(board, gridX, gridY) == true)
      // 	{

      // 	}
	  // If (Key[KEY_RIGHT])
	  //   {	
	  //     pEnemy->moveRight();	
	  //   }


	  // if (Key[KEY_LEFT])
	  //   {
	  //     pEnemy->moveLeft();
	  //   }


	  // if (Key[KEY_DOWN])
	  //   {
	  //     pEnemy->moveDown();
	  //   }


	  // if (Key[KEY_UP])
	  //   {
	  //     pEnemy->moveUp();
	  //   }
	




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



      // If menu is being shown and S is pressed
      if (Key[KEY_S] && al_get_display_width (Display) == 640 && displayResizable == true)
	{
	  al_resize_display (Display, ui.displayWidth, ui.displayHeight);

	  cout << "W: " << ui.displayWidth << "\nH: " << ui.displayHeight << endl;

	  al_set_window_title (Display, "Low resolution display @ 1280 * 720");

	  displayResizable = false;
	}




      al_flip_display();
    }
}

