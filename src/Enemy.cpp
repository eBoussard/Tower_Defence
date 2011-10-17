#include <Enemy.hpp>
#include <iostream>
#include <allegro.h>



Enemy::Enemy():m_HealthPoints(100), m_MovementSpeed(100), m_YieldsMoney(100)
{ }



ALLEGRO_BITMAP * Enemy::getBitmap() const
{
  int EnemyBitmapSize = 50;

  ALLEGRO_BITMAP *EnemyBitmap = NULL;
 
  EnemyBitmap = al_create_bitmap (EnemyBitmapSize, EnemyBitmapSize);
  return EnemyBitmap;
}

void Enemy::debugPrint() const
{
  std::cout << "Enemy\n";
  std::cout << "HealthPoints: " << m_HealthPoints << "\n";
  std::cout << "MovementSpeed: " << m_MovementSpeed << "\n";
  std::cout << "YieldsMoney: " << m_YieldsMoney << "\n\n";
}
