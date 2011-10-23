#include <Rules.hpp>
#include <iostream>



Rules::Rules()
{ }


bool Rules::towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePositionX, unsigned int tilePositionY) const
{

  if ((tilePositionX == 0) && (tilePositionY == board.getEntranceTile()))
    {
      return false;
    }


  if ((tilePositionX == 19) && (tilePositionY == board.getExitTile()))
    {
      return false;
    }


  //If new position is on existing tower
  for (std::list<Tower *>::const_iterator it = Towers.begin(); it != Towers.end(); ++it)
    {
      Tower *pTower = *it;
      if (pTower->onTile(tilePositionX, tilePositionY))
	{
	  return false;
	}
    }

  //TODO Do not allow placing tower which blocks enemy from exit (dead end)

  return true;
}




