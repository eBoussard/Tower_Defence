#include <Engine.hpp>

#include <iostream>
#include <allegro.h>

Engine::Engine()
{
}


void Engine::moveEnemy(const std::list<Enemy *> & Enemies, Board & board, unsigned int enemyStepCounter)
{
   for (std::list<Enemy *>::const_iterator it = Enemies.begin(); it != Enemies.end(); ++it)
      {
	 Enemy *pEnemy = *it;
	 unsigned int gridX, gridY;
	 board.getEnemyPosition(enemyStepCounter, gridX, gridY);
	 pEnemy->setXIndex(gridX);
	 pEnemy->setYIndex(gridY);
      }
}

