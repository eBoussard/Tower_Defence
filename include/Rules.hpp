//! Rules check if the requested action is allowed

#ifndef RULES_HPP
#define RULES_HPP

//! To get positions

//! These includes are needed in order to find Tower position on
//! Board, entrance position and exit position.
#include <Board.hpp>
#include <Tower.hpp>
#include <list>


class Rules
{
public:
  Rules();

  //! Check if tower placement is valid

  //! @param board TODO
  //! @param Towers to find out current Tower positions
  //! @param tilePositionX tile position on grid on x-axis
  //! @param tilePositionY tile position on grid on y-axis
  //! @returns true if all conditions are false
  bool towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePositionX, unsigned int tilePositionY) const;


private:
  Rules(const Rules&);
  Rules & operator = (const Rules&);
};



#endif //RULES_HPP
