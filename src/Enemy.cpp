#include <Enemy.hpp>
#include <iostream>
#include <allegro.h>



Enemy::Enemy():m_healthPoints(100), m_movementSpeed(100), m_yieldsMoney(100)
{ }



ALLEGRO_BITMAP * Enemy::getBitmap() const
{
  int enemyBitmapSize = 50;

  ALLEGRO_BITMAP *enemyBitmap = NULL;
 
  enemyBitmap = al_create_bitmap (enemyBitmapSize, enemyBitmapSize);
  return enemyBitmap;
}


//TODO Enemy movement

//TODO Summon several enemy (waves)

//TODO Make enemy avoid tower 


