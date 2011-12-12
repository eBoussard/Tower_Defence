#include <Rules.hpp>
#include <iostream>



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
      Tower *pTower;

      if (pTower->onTile(0, 0))
	    {
		  std::cout << "test" << std::endl;
	    }
}
