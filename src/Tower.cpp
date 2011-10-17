#include <Tower.hpp>
#include <iostream>
#include <allegro.h>



Tower::Tower():m_Price(100), m_Damage(100), m_ShootingSpeed(100), m_Range(100), m_SellValue(100)
{ }


ALLEGRO_BITMAP * Tower::getBitmap() const
{
  int TowerBitmapSize = 50;


  ALLEGRO_BITMAP *TowerBitmap = NULL;

  TowerBitmap = al_create_bitmap (TowerBitmapSize, TowerBitmapSize);
  return TowerBitmap;
}


void Tower::debugPrint() const
{
  std::cout << "Tower\n";
  std::cout << "Price: " << m_Price << "\n";
  std::cout << "Damage: " << m_Damage << "\n";
  std::cout << "ShootingSpeed: " << m_ShootingSpeed << "\n";
  std::cout << "Range: " << m_Range << "\n";
  std::cout << "SellValue: " << m_SellValue << "\n\n";
}
