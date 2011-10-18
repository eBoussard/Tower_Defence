#include <Enemy.hpp>
#include <iostream>
#include <allegro.h>



Enemy::Enemy():m_healthPoints(100), m_movementSpeed(100), m_yieldsMoney(100)
{ }


//PLACEHOLDER
ALLEGRO_BITMAP * Enemy::getBitmap() const
{
  int enemyBitmapSize = 50;

  ALLEGRO_BITMAP *enemyBitmap = NULL;
 
  enemyBitmap = al_create_bitmap (enemyBitmapSize, enemyBitmapSize);
  return enemyBitmap;
}

void Enemy::debugPrint() const
{
  std::cout << "Enemy\n";
  std::cout << "HealthPoints: " << m_healthPoints << "\n";
  std::cout << "MovementSpeed: " << m_movementSpeed << "\n";
  std::cout << "YieldsMoney: " << m_yieldsMoney << "\n\n";
}
