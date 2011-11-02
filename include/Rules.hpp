//! Check if the requested action is allowed

//! Rules mainly control Tower placement on Board to make sure Enemy
//! always has a free path to @ref exitTile_ "exit".

#ifndef RULES_HPP
#define RULES_HPP

//! To find out positions

//! These includes are needed in order to find out current Tower, @ref
//! entranceTile_ "entrance" and @ref exitTile_ "exit" positions.
#include <Board.hpp>
#include <Tower.hpp>
#include <list>


class Rules
{
public:
  Rules();

  //! Check if tower placement is valid

  //! @param board current positions of @ref entranceTile_ "entrance"
  //! and @ref exitTile_ "exit"
  //! @param Towers current position(s) of Tower
  //! @param tilePositionX tile position on grid on x-axis
  //! @param tilePositionY tile position on grid on y-axis
  //! @returns true if placement of Tower is valid
  bool towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePositionX, unsigned int tilePositionY) const;

  bool enemyPositionValid (const Board & board, unsigned int tilePositionX, unsigned int tilePositionY) const;


private:
  Rules(const Rules&);
  Rules & operator = (const Rules&);
};



#endif //RULES_HPP
