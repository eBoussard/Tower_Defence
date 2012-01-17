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



void Engine::shootEnemy(const Board & board, Tower & tower, Enemy & enemy)
{	
	ALLEGRO_TIMER *shootingTimer = NULL;
	ALLEGRO_EVENT_QUEUE *datQueue = NULL;

	al_init();
	shootingTimer = al_create_timer(0.5);
	datQueue = al_create_event_queue();
	al_register_event_source (datQueue, al_get_timer_event_source (shootingTimer));

	if (tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex()) ||
	tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex() + 1) ||
	tower.onTile(enemy.getXIndex() + 1, enemy.getYIndex() - 1) ||
	tower.onTile(enemy.getXIndex(), enemy.getYIndex() + 1) ||
	tower.onTile(enemy.getXIndex(), enemy.getYIndex() - 1) ||
	tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex()) ||
	tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex() + 1) ||
	tower.onTile(enemy.getXIndex() - 1, enemy.getYIndex() - 1))
      {
		 al_start_timer(shootingTimer);
		  
		 if (enemy.getHealthPoints() > 0)
		    {
		       enemy.setHealthPoints(enemy.getHealthPoints() - 1);
		       std::cout << "Enemy HP: " << enemy.getHealthPoints() << std::endl;
		    }
	   }
}