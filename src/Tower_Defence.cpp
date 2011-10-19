#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>

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





const unsigned int ScreenW = 1280;
const unsigned int ScreenH = 720;
const float FPS = 60.;




bool mouseClick (unsigned int & x, unsigned int & y)
{
  ALLEGRO_MOUSE_STATE mouseState;

  static bool mouseOneDown = false;

  al_get_mouse_state (&mouseState);




  if (mouseState.buttons & 1)
    {
      mouseOneDown = true;
      return false;
    }



  if (mouseOneDown)
    {
      x = al_get_mouse_state_axis (&mouseState, 0);
      y = al_get_mouse_state_axis (&mouseState, 1);
      mouseOneDown = false;
      return true;
    }

  return false;
}



int main()
{
  ALLEGRO_DISPLAY *Display = NULL;
  ALLEGRO_EVENT_QUEUE *eventQueue = NULL;
  ALLEGRO_TIMER *framerateTimer = NULL;






  if (!al_init())
    {
      cout << "failed to initialize Allegro!\n";
      return 1;
    }



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


  Display = al_create_display (ScreenW, ScreenH);
  if (!Display)
    {
      cout << "failed to create display!\n";
      return 1;
    }



  Player *pPlayer = new Player();

  Board *pBoard = new Board();

  Tower *pTower = NULL;

  Ammunition *pAmmunition = new Ammunition();

  Enemy *pEnemy = new Enemy();

  Engine *pEngine = new Engine();

  ScoreBoard *pScoreBoard = new ScoreBoard();




  if (pPlayer != NULL) pPlayer->debugPrint();

  if (pBoard != NULL) pBoard->debugPrint();

  if (pTower != NULL) pTower->debugPrint();

  if (pAmmunition != NULL) pAmmunition->debugPrint();

  if (pEnemy != NULL) pEnemy->debugPrint();

  if (pEngine != NULL) pEngine->debugPrint();




  al_register_event_source (eventQueue, al_get_display_event_source (Display));

  al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));

  al_start_timer(framerateTimer);

  al_set_target_bitmap(al_get_backbuffer(Display)); 

  while(1)
    {
      ALLEGRO_EVENT Event;
      unsigned int x, y;



      al_wait_for_event(eventQueue, &Event);


      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      	{
      	  break;
      	}




      pBoard->draw();
      pScoreBoard->draw();
 


      //if mouse one is clicked
      if (mouseClick(x, y))
	{
	  pBoard->mouseClick(x,y);
	  pScoreBoard->mouseClick(x,y);

	  //and if tower button is active
	  if (pScoreBoard->towerButtonActive())
	    {
	      unsigned int gridPosition_x, gridPosition_y;
	      //gridPosition means tile coordinates here
	      if (pBoard->createTower(x, y, gridPosition_x, gridPosition_y))
		{
		  delete pTower; //remove old tower drawn on Board
		  pTower = new Tower(gridPosition_x, gridPosition_y); //create new tower on tile
		  std::cout << "new tower created on " << gridPosition_x << ", " << gridPosition_y << std::endl;
		}
	      else
		{
		  std::cout << "could not create tower\n";
		}
	    } 
	}

      if (pTower != NULL)
	{
	  pTower->draw();
	}


      al_flip_display();
    }
}
