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
using namespace std;




const float FPS = 60.;




bool mouseNClick (unsigned int & x, unsigned int & y, unsigned int n, bool & isDown)
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



bool mouseOneClick (unsigned int & x, unsigned int & y)
{
  static bool isDown = false;
  return mouseNClick(x, y, 1, isDown);
}



bool mouseTwoClick (unsigned int & x, unsigned int & y)
{
  static bool isDown = false;
  return mouseNClick(x, y, 2, isDown);
}









int main()
{
  ALLEGRO_DISPLAY *menuDisplay = NULL;
  ALLEGRO_DISPLAY *highResDisplay = NULL;
  ALLEGRO_DISPLAY *lowResDisplay = NULL;


  ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
  ALLEGRO_TIMER *framerateTimer = NULL;






  if (!al_init())
    {
      cout << "failed to initialize Allegro!\n";
      return 1;
    }



  list <Tower *> Towers;

  ScoreBoard scoreboard;

  Rules rules;

  Board board;

  UI ui;




  if (!al_install_mouse())
    {
      cout << "mouse fail\n";
      return 1;
    }



  eventQueue = al_create_event_queue();
  if (!eventQueue)
    {
      cout << "EventQueue fail\n";
      return 1;
    }



  framerateTimer = al_create_timer (1.0 / FPS);
  if (!framerateTimer)
    {
      cout << "Framerate timer fail\n";
      return 1;
    }



  menuDisplay = al_create_display (ui.menuDisplayWidth, ui.menuDisplayHeight);




  al_register_event_source (eventQueue, al_get_display_event_source (menuDisplay));

  al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

  al_start_timer(framerateTimer);

  al_set_target_bitmap(al_get_backbuffer(menuDisplay)); 




  while(1)
    {
      ALLEGRO_EVENT Event;

      unsigned int x, y, tilePositionX, tilePositionY;


      al_wait_for_event(eventQueue, &Event);


      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
	  break;
	}
      


      if (menuDisplay != NULL)
      	{
	  {
	    ui.Draw();
	  }
	}
	

	  for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
	    {
	      Tower * pTower = *it;
	      pTower->Draw();
	    }
	



      if (mouseOneClick(x, y))
	{
	  board.mouseClick(x, y);

	  scoreboard.lowResButtonClicked(x, y);

	  scoreboard.highResButtonClicked(x, y);





	  if (menuDisplay != NULL) 
	    {
	      al_destroy_display (menuDisplay);
	      menuDisplay = NULL;
	    }

	  lowResDisplay = al_create_display (ui.lowResWidth, ui.lowResDisplayHeight);
	  cout << "W: " << ui.lowResWidth << "\nH: " << ui.lowResDisplayHeight << endl;
	  al_set_window_title (lowResDisplay, "Low resolution display @ 1280 * 720");
	  al_set_target_bitmap (al_get_backbuffer (lowResDisplay));

	  if (lowResDisplay != NULL)
	    {
	      board.lowResDraw();
	      scoreboard.lowResDraw();
	    }





	  if (scoreboard.towerButtonActive())
	    {	   
	      if (board.getTileCoordinates(x, y, tilePositionX, tilePositionY))
		{
		  if (rules.towerPlacementValid(board, Towers, tilePositionX, tilePositionY))
		    {
		      //Creates a new tower
		      Tower * pTower = new Tower(tilePositionX, tilePositionY);

		      //and puts it in the list
		      Towers.push_back(pTower);

		      cout << "new tower created on\nX: " << tilePositionX << "\nY: " << tilePositionY << endl; //Temporary

		      cout << "Amount of towers: " << Towers.size() << endl;
		    }
		} 
	    } 
	}


      if (mouseTwoClick(x, y))
	{





	  if (menuDisplay != NULL) 
	    {
	      al_destroy_display (menuDisplay);
	      menuDisplay = NULL;
	    }

	  highResDisplay = al_create_display (ui.highResWidth, ui.highResDisplayHeight);
	  cout << "X: " << ui.highResWidth << "\nH: " << ui.highResDisplayHeight << endl;
	  al_set_window_title (highResDisplay, "High resolution display @ 1920 * 1080");
	  al_set_target_bitmap (al_get_backbuffer (highResDisplay));

	  if (highResDisplay != NULL)
	    {
	      board.highResDraw();
	      scoreboard.highResDraw();
	    }





	  if (board.getTileCoordinates(x, y, tilePositionX, tilePositionY))
	    {
	      for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
		{
		  Tower *pTower = *it;

		  if (pTower->onTile(tilePositionX, tilePositionY))
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

