#include <Tower.hpp>
#include <iostream>
#include <allegro.h>



Tower::Tower():m_Price(100), m_Damage(100), m_shootingSpeed(100), m_Range(100), m_sellValue(100)
{ }


ALLEGRO_BITMAP * Tower::getBitmap() const
{
  int towerBitmapSize = 48;


  ALLEGRO_BITMAP *towerBitmap = NULL;

  towerBitmap = al_create_bitmap (towerBitmapSize, towerBitmapSize);
  return towerBitmap;
}


void Tower::debugPrint() const
{
  std::cout << "Tower\n";
  std::cout << "Price: " << m_Price << "\n";
  std::cout << "Damage: " << m_Damage << "\n";
  std::cout << "ShootingSpeed: " << m_shootingSpeed << "\n";
  std::cout << "Range: " << m_Range << "\n";
  std::cout << "SellValue: " << m_sellValue << "\n\n";
}
