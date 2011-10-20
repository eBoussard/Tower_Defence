#include <Rules.hpp>
#include <iostream>



Rules::Rules()
{ }


bool Rules::towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePosition_x, unsigned int tilePosition_y) const
{

  if ((tilePosition_x == 0) && (tilePosition_y == board.getEntranceTile()))
    {
      return false;
    }


  if ((tilePosition_x == 19) && (tilePosition_y == board.getExitTile()))
    {
      return false;
    }


  //If new position is on existing tower
  for (std::list<Tower *>::const_iterator it = Towers.begin(); it != Towers.end(); ++it)
    {
      Tower *pTower = *it;
      if (pTower->onTile(tilePosition_x, tilePosition_y))
	{
	  return false;
	}
    }

  //TODO Do not allow placing tower which blocks enemy from exit (dead end)

  return true;
}




