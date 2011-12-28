//! Sköter saker som förflyttning

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <Enemy.hpp>
#include <Board.hpp>
#include <definitions.hpp>

class Engine
{
public:
   Engine();

   void moveEnemy(Enemy & enemy, Board & board, unsigned int enemyStepCounter);

private:
   Engine(const Engine&);
   Engine & operator = (const Engine&);


};



#endif //ENGINE_HPP
