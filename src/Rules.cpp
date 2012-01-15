#include <Rules.hpp>
#include <iostream>
#include <allegro.h>



Rules::Rules()
{ }


bool Rules::towerPlacementValid (const Board & board, Tower & tower, gridPosition gridX, gridPosition gridY) const
{

   if ((gridX == 0) && (gridY == board.getEntranceTile()))
      {
	 return false;
      }


   if ((gridX == 19) && (gridY == board.getExitTile()))
      {
	 return false;
      }

   if (board.tileHasTower(gridX, gridY))
      {
	 return false;
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

void Rules::enemyShootable(const Board & board, Tower & tower, Enemy & enemy)
{
   if (tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex()) ||
       tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex() + 1) ||
       tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex() - 1) ||

       tower.onTile(enemy.getXIndex(), enemy.getYIndex() + 1) ||
       tower.onTile(enemy.getXIndex(), enemy.getYIndex() - 1) ||

       tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex()) ||
       tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex() + 1) ||
       tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex() - 1))
   if (true)
      {
	 ALLEGRO_TIMER *shootingTimer = NULL;
	 ALLEGRO_EVENT_QUEUE *datQueue = NULL;

	 al_init();
	 shootingTimer = al_create_timer(1.0);
	 datQueue = al_create_event_queue();

	 al_register_event_source (datQueue, al_get_timer_event_source (shootingTimer));
	 al_start_timer(shootingTimer);

	 enemy.setHealthPoints(enemy.getHealthPoints() - 1);
	 std::cout << "Enemy HP: " << enemy.getHealthPoints() << std::endl;
      }
}


