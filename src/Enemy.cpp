#include <Enemy.hpp>

#include <iostream>
#include <allegro.h>



Enemy::Enemy(unsigned int xIndex, unsigned int yIndex):healthPoints_(100), movementSpeed_(100), yieldsMoney_(100), enemyBitmapSize_(48), xIndex_(xIndex), yIndex_(yIndex), newPosRight_(xIndex + 1), newPosLeft_(xIndex - 1), newPosDown_(yIndex + 1), newPosUp_(yIndex - 1)
{ 
  al_init();

  enemyBitmap_ = al_create_bitmap (enemyBitmapSize_, enemyBitmapSize_);

  ALLEGRO_BITMAP *pOldTargetBitmap = al_get_target_bitmap();
  al_set_target_bitmap (enemyBitmap_);
  al_clear_to_color (al_map_rgb (255, 0, 0));
  al_set_target_bitmap (pOldTargetBitmap);
}


void Enemy::Draw() const
{
  al_draw_bitmap (enemyBitmap_, (xIndex_ * 64) + 8, (yIndex_ * 64) + 8, 0);
}


int Enemy::moveRight() const
{
  return newPosRight_;
}

int Enemy::moveLeft() const
{
  return newPosLeft_;
}

int Enemy::moveDown() const
{
  return newPosDown_;
}

int Enemy::moveUp() const
{
  return newPosUp_;
}
