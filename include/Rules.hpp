#ifndef RULES_HPP
#define RULES_HPP

#include <Board.hpp>
#include <Tower.hpp>
#include <list>

class Rules
{
public:
  Rules();
  bool towerPlacementValid (const Board & board, const std::list<Tower *> & Towers, unsigned int tilePosition_x, unsigned int tilePosition_y) const;


private:
  Rules(const Rules&);
  Rules & operator = (const Rules&);
};



#endif //RULES_HPP
