#include <Rules.hpp>
#include <iostream>
#include <allegro.h>



Rules::Rules()
{ }


bool Rules::towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, gridPosition gridX, gridPosition gridY) const
{

      if ((gridX == 0) && (gridY == board.getEntranceTile()))
	    {
		  return false;
	    }


      if ((gridX == 19) && (gridY == board.getExitTile()))
	    {
		  return false;
	    }


      //If new position is on existing tower
      for (std::list<Tower *>::const_iterator it = Towers.begin(); it != Towers.end(); ++it)
	    {
		  Tower *pTower = *it;
		  if (pTower->onTile(gridX, gridY))
			{
			      return false;
			}
	    }


      if (board.onEnemyPath(gridX, gridY))
	    {
		  return false;
	    }

      return true;
}



bool Rules::enemyPositionValid (const Board & board, gridPosition gridX, gridPosition gridY) const
{
      if (board.onEnemyPath(gridX, gridY))
	    {
		  return true;
	    }
      return false;
}



void Rules::enemyShootable(const Board & board, const std::list<Tower *> & Towers, Enemy & enemy)
{
      for (std::list<Tower *>::const_iterator it = Towers.begin(); it != Towers.end(); ++it)
	    {
		  Tower *pTower = *it;

		  if (pTower->onTile(enemy.getXIndex() + 1, enemy.getYIndex()) ||
		      pTower->onTile(enemy.getXIndex() + 1, enemy.getYIndex() + 1) ||
		      pTower->onTile(enemy.getXIndex() + 1, enemy.getYIndex() - 1) ||

		      pTower->onTile(enemy.getXIndex(), enemy.getYIndex() + 1) ||
		      pTower->onTile(enemy.getXIndex(), enemy.getYIndex() - 1) ||

		      pTower->onTile(enemy.getXIndex() - 1, enemy.getYIndex()) ||
		      pTower->onTile(enemy.getXIndex() - 1, enemy.getYIndex() + 1) ||
		      pTower->onTile(enemy.getXIndex() - 1, enemy.getYIndex() - 1))
			{
			      ALLEGRO_TIMER *shootingTimer = NULL;
			      ALLEGRO_EVENT_QUEUE *datQueue = NULL;

			      al_init();
			      shootingTimer = al_create_timer(1.0);
			      datQueue = al_create_event_queue();

			      al_register_event_source (datQueue, al_get_timer_event_source (shootingTimer));
			      al_start_timer(shootingTimer);

			      enemy.setHealthPoints(enemy.getHealthPoints() - 1);
			      std::cout << enemy.getHealthPoints() << std::endl;
			}
	    }
}

