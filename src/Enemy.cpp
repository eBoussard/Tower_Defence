#include <Enemy.hpp>

#include <iostream>
#include <allegro.h>

Enemy::Enemy(gridPosition gridX, gridPosition gridY):healthPoints_(15), movementSpeed_(30), yieldsMoney_(100), enemyBitmapSize_(48), gridX_(gridX), gridY_(gridY)
{ 
   al_init();

   enemyBitmap_ = al_create_bitmap (enemyBitmapSize_, enemyBitmapSize_);
   al_set_target_bitmap (enemyBitmap_);
   al_clear_to_color (al_map_rgb (255, 0, 0));
}

unsigned int Enemy::getHealthPoints() const
{
   return healthPoints_;
}

void Enemy::setHealthPoints(unsigned int t_healthPoints)
{
   healthPoints_ = t_healthPoints;
}

void Enemy::Draw() const
{
   al_draw_bitmap (enemyBitmap_, (gridX_ * 64) + 8, (gridY_ * 64) + 8, 0);
}

unsigned int Enemy::getXIndex() const
{
   return gridX_;
}

unsigned int Enemy::getYIndex() const
{
   return gridY_;
}


void Enemy::setXIndex(gridPosition gridX)
{
   gridX = gridX_;
}


void Enemy::setYIndex(gridPosition gridY)
{
   gridY = gridY_;
}

unsigned int Enemy::getMovementSpeed() const
{
   return movementSpeed_;
}
