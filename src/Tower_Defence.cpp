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





int main()
{
  ALLEGRO_DISPLAY *Display = NULL;
  ALLEGRO_BITMAP *EnemyPH = NULL;
  ALLEGRO_BITMAP *TowerPH = NULL;
  ALLEGRO_EVENT_QUEUE *EventQueue = NULL;
  ALLEGRO_TIMER *FramerateTimer = NULL;






  if (!al_init())
    {
      cout << "failed to initialize Allegro!\n";
      return 1;
    }





  EventQueue = al_create_event_queue();
  if (!EventQueue)
    {
      cout << "EventQueue fail\n";
      return 1;
    }





  FramerateTimer = al_create_timer (1.0 / FPS);
  if (!FramerateTimer)
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

  Tower *pTower = new Tower();

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



  al_register_event_source (EventQueue, al_get_display_event_source (Display));

  al_register_event_source (EventQueue, al_get_timer_event_source (FramerateTimer));

  al_start_timer(FramerateTimer);

  al_set_target_bitmap(al_get_backbuffer(Display)); 

  while(1)
    {
      ALLEGRO_EVENT Event;
      al_wait_for_event(EventQueue, &Event);
      if (Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      	{
      	  break;
      	}
      pBoard->draw();
      pScoreBoard->draw();
      al_flip_display();
    }
}
