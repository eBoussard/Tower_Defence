#include <Rules.hpp>
#include <iostream>



Rules::Rules()
{ }


bool Rules::towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePosition_x, unsigned int tilePosition_y) const
{

  //If a tower is placed on entrance tile
  if ((tilePosition_x == 0) && (tilePosition_y == board.getEntranceTile()))
    {
      return false;
    }


  //If a tower is placed on exit tile
  if ((tilePosition_x == 19) && (tilePosition_y == board.getExitTile()))
    {
      return false;
    }
  return true;
}




