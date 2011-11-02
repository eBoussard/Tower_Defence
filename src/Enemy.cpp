#include <Enemy.hpp>

#include <iostream>
#include <allegro.h>



Enemy::Enemy(unsigned int xIndex, unsigned int yIndex):healthPoints_(100), movementSpeed_(100), yieldsMoney_(100), enemyBitmapSize_(48), xIndex_(xIndex), yIndex_(yIndex)
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


void Enemy::moveRight()
{
  if (xIndex_ != 19)
    xIndex_ += 1;
}

void Enemy::moveLeft()
{
  if (xIndex_ != 0)
    xIndex_ -= 1;
}

void Enemy::moveUp()
{
  if (yIndex_ != 0)
    yIndex_ -= 1;
}

void Enemy::moveDown()
{
  if (yIndex_ != 9)
    yIndex_ += 1;
}


unsigned int Enemy::getXIndex() const
{
  return xIndex_;
}

unsigned int Enemy::getYIndex() const
{
  return yIndex_;
}


void Enemy::setXIndex(unsigned int xIndex)
{
  xIndex_ = xIndex;
}


void Enemy::setYIndex(unsigned int yIndex)
{
  yIndex_ = yIndex;
}
