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



void Rules::isEnemyShootable(Board & board, Player & player)
{
   Board::EnemiesList_t enemies = board.getEnemies();
   Board::TowersList_t towers = board.getTowers();

   for (Board::EnemiesList_t::iterator ite = enemies.begin(); ite != enemies.end(); ++ite)
      {
	 for (Board::TowersList_t::iterator itt = towers.begin(); itt != towers.end(); ++itt)
	    {
			Engine engine;
			engine.shootEnemy(board, **itt, *ite->first, player);
	    }
     }
}


