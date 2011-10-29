#include <Enemy.hpp>
#include <iostream>
#include <allegro.h>



Enemy::Enemy():healthPoints_(100), movementSpeed_(100), yieldsMoney_(100), enemyBitmapSize(48)
{ }



ALLEGRO_BITMAP * Enemy::getBitmap() const
{
  ALLEGRO_BITMAP *enemyBitmap = NULL;
 
  enemyBitmap = al_create_bitmap (enemyBitmapSize, enemyBitmapSize);
  return enemyBitmap;
}


