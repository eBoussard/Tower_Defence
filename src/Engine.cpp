#include <Engine.hpp>

#include <iostream>
#include <allegro.h>

Engine::Engine()
{
}


void Engine::moveEnemy(Enemy & enemy, Board & board, unsigned int enemyStepCounter)
{
   unsigned int gridX, gridY;
   board.getEnemyPosition(enemyStepCounter, gridX, gridY);
   enemy.setXIndex(gridX);
   enemy.setYIndex(gridY);

   std::cout << "\nE-X: " << gridX << std::endl;
   std::cout << "E-Y: " << gridY << std::endl;
   std::cout << "E-S: " << enemyStepCounter << std::endl;
}

