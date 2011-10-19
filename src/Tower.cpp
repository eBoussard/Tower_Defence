#include <Tower.hpp>
#include <iostream>
#include <allegro.h>



Tower::Tower(unsigned int xIndex, unsigned int yIndex):m_Price(100), m_Damage(100), m_shootingSpeed(100), m_Range(100), m_sellValue(100), m_xIndex(xIndex), m_yIndex(yIndex)
{ }


ALLEGRO_BITMAP * Tower::getBitmap() const
{
  int towerBitmapSize = 48;


  ALLEGRO_BITMAP *towerBitmap = NULL;

  towerBitmap = al_create_bitmap (towerBitmapSize, towerBitmapSize);
  ALLEGRO_BITMAP *pOldTargetBitmap = al_get_target_bitmap();
  al_set_target_bitmap (towerBitmap);
  al_clear_to_color (al_map_rgb (0, 255, 0));
  al_set_target_bitmap(pOldTargetBitmap);
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



unsigned int Tower::getXIndex() const
{
  return m_xIndex;
}



unsigned int Tower::getYIndex() const
{
  return m_yIndex;
}
