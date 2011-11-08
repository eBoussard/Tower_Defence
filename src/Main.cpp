#include <iostream>

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

      const unsigned int FPS = 30;
      bool gameStarted = false;
      bool Quit = false;
      bool redraw = false;
      pixelPosition x, y;
      gridPosition gridX, gridY;
      unsigned int updateEnemyPosition = 0;
      unsigned int enemyStepCounter = 0;



      list <Tower *> Towers;
      Tower tower(gridX, gridY);
      Player player;
      ScoreBoard scoreboard(player);
      Rules rules;
      Board board;
      UI ui;
      Enemy *pEnemy = NULL;




      if (!al_init())
	    {
		  cout << "TOWERDEFENCE.CPP: AL_INIT()" << endl;
		  return 1;
	    }



      if (!al_install_mouse())
	    {
		  cout << "TOWERDEFENCE.CPP: AL_INSTALL_MOUSE()" << endl;
		  return 1;
	    }



      if (!al_install_keyboard())
	    {
		  cout << "TOWERDEFENCE.CPP: AL_INSTALL_KEYBOARD()" << endl;
		  return 1;
	    }



      eventQueue = al_create_event_queue();
      if (!eventQueue)
	    {
		  cout << "TOWERDEFENCE.CPP: AL_CREATE_EVENT_QUEUE()" << endl;
		  return 1;
	    }



      framerateTimer = al_create_timer (1.0 / FPS);
      if (!framerateTimer)
	    {
		  cout << "TOWERDEFENCE.CPP: AL_CREATE_TIMER()" << endl;
		  return 1;
	    }



      Display = al_create_display (ui.displayWidth, ui.displayHeight);
      if (!Display)
	    {
		  cout << "TOWERDEFENCE.CPP: AL_CREATE_DISPLAY()" << endl;
		  return 1;
	    }
  

      al_set_window_title (Display, "MENU");


      al_register_event_source (eventQueue, al_get_display_event_source (Display));
      al_register_event_source (eventQueue, al_get_timer_event_source (framerateTimer));
      al_register_event_source (eventQueue, al_get_keyboard_event_source());



      al_start_timer(framerateTimer);



      while(!Quit)
	    {
		  ALLEGRO_EVENT Event;

		  al_set_target_bitmap (al_get_backbuffer (Display));
		  


		  if (!al_get_next_event(eventQueue, &Event))
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
					  al_set_timer_count (framerateTimer, 0);
				    }
			}
      



		  if (gameStarted == true && redraw == true)
			{
			      board.Draw();
			      scoreboard.Draw();

			      if (pEnemy != NULL)
				    {
					  pEnemy->Draw();
				    }

			      for (list<Tower *>::iterator it = Towers.begin(); it != Towers.end(); ++it)
				    {
					  Tower * pTower = *it;
					  pTower->Draw();
				    }
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
					  al_set_timer_count(framerateTimer, 0);

					  player.setHealthPoints(player.getHealthPoints() - 1);
					  cout << player.getHealthPoints() << endl;
						      
				    }


			      else
				    {
					  int oldGridX = gridX;
					  int oldGridY = gridY;

					  enemyStepCounter = al_get_timer_count(framerateTimer) / (FPS / 2);
					  board.getEnemyPosition(enemyStepCounter, gridX, gridY);
					  pEnemy->setXIndex(gridX);
					  pEnemy->setYIndex(gridY);



					  if ((oldGridY != gridY) || (oldGridX != gridX))
						{
						      cout << "ENEMY STEP: " << enemyStepCounter << endl;
						      cout << "ENEMY X: " << gridX << endl;
						      cout << "ENEMY Y: " << gridY << endl;
						      cout << "TIME: " << al_get_timer_count(framerateTimer) / 30 << endl;
						}
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
								  Tower * pTower = new Tower(gridX, gridY);

								  if (player.getMoney() >= pTower->getPrice())
									{
									      Towers.push_back(pTower);
									      player.setMoney(player.getMoney() - pTower->getPrice());
									      cout << "TOWER CREATED\n\nMONEY: " << player.getMoney() << endl;
									}
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
								  player.setMoney(player.getMoney() + pTower->getSellValue());
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

