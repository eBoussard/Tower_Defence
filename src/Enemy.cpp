#include <Enemy.hpp>
#include <iostream>
#include <allegro.h>



Enemy::Enemy():healthPoints_(100), movementSpeed_(100), yieldsMoney_(100)
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


