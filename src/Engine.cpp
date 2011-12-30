#include <Engine.hpp>

#include <iostream>
#include <allegro.h>

Engine::Engine()
{
}


void Engine::moveEnemy(Board & board, unsigned int enemyStepCounter)
{
   Board::EnemiesList_t & Enemies = board.getEnemies();
   for (Board::EnemiesList_t::iterator it = Enemies.begin(); it != Enemies.end(); ++it)
      {
	 Enemy *pEnemy = it->first;
	 unsigned int enemyStartStep = it->second;
	 
	 unsigned int gridX, gridY;
	 board.getEnemyPosition(enemyStepCounter - enemyStartStep, gridX, gridY);
	 pEnemy->setXIndex(gridX);
	 pEnemy->setYIndex(gridY);
      }
}

