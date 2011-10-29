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




const float FPS = 10.;




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
  ALLEGRO_DISPLAY *Display = NULL;


  ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
  ALLEGRO_TIMER *framerateTimer = NULL;

  enum KEYS {KEY_S, KEY_ESCAPE};
  bool Key[2] = {false, false};






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



  if (!al_install_keyboard())
    {
      cout << "keyboard fail\n";
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



  Display = al_create_display (ui.menuDisplayWidth, ui.menuDisplayHeight);




  al_register_event_source (eventQueue, al_get_display_event_source (Display));

  al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

  al_register_event_source (eventQueue, al_get_keyboard_event_source());


  al_start_timer(framerateTimer);

  al_set_target_bitmap(al_get_backbuffer(Display)); 


  bool displayResizable = true;

  bool Quit = false;

  while(!Quit)
    {
      ALLEGRO_EVENT Event;

      unsigned int x, y, tilePositionX, tilePositionY;


      al_wait_for_event(eventQueue, &Event);


      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
	  break;
	}


      if (Event.type == ALLEGRO_EVENT_KEY_DOWN)
	{
	  if (Event.keyboard.keycode == ALLEGRO_KEY_S) Key[KEY_S] = true;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) Key[KEY_ESCAPE] = true;
	}



      
      if (Event.type == ALLEGRO_EVENT_KEY_UP)
	{
	  if (Event.keyboard.keycode == ALLEGRO_KEY_S) Key[KEY_S] = false;

	  if (Event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) 
	    {
	      Key[KEY_ESCAPE] = false;
	      Quit = true;
	    }
	}
      

      if (al_get_display_width (Display) == 1280)
	{
	  board.Draw();
	  scoreboard.Draw();
	}

	

      for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
	{
	  Tower * pTower = *it;
	  pTower->Draw();
	}





      if (mouseOneClick(x, y))
	{
	  board.mouseClick(x, y);

	  scoreboard.ButtonClicked(x, y);

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

		      cout << "new tower created on\nGX: " << tilePositionX << "\nGY: " << tilePositionY << endl;

		      cout << "Amount of towers: " << Towers.size() << endl;
		    }
		} 
	    } 
	}


      if (mouseTwoClick(x, y))
	{
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

