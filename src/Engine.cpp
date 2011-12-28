#include <Engine.hpp>

#include <iostream>
#include <allegro.h>

Engine::Engine()
{
}


void Engine::moveEnemy(Board & board, Enemy & enemy)
{
      ALLEGRO_TIMER *movementTimer = al_create_timer (1.0 / enemy.getMovementSpeed());
      ALLEGRO_EVENT_QUEUE *eventQueue = al_create_event_queue();
      al_register_event_source(eventQueue, al_get_timer_event_source (movementTimer));
      al_start_timer (movementTimer); 

      unsigned int enemyStepCounter = 0, gridX, gridY;

      enemyStepCounter = al_get_timer_count(movementTimer) / enemy.getMovementSpeed();
      board.getEnemyPosition(enemyStepCounter, gridX, gridY);
      enemy.setXIndex(gridX);
      enemy.setYIndex(gridY);

      std::cout << "E-X: " << gridX << std::endl;
      std::cout << "E-Y: " << gridY << std::endl;
}

