#include <Tower.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_image.h>



Tower::Tower(unsigned int xIndex, unsigned int yIndex):m_Price(100), m_Damage(100), m_shootingSpeed(100), m_Range(100), m_sellValue(100), m_xIndex(xIndex), m_yIndex(yIndex), m_towerBitmapSize(48)
{
  al_init();
  al_init_image_addon();

  m_towerBitmap = al_create_bitmap (m_towerBitmapSize, m_towerBitmapSize);


  ALLEGRO_BITMAP *pOldTargetBitmap = al_get_target_bitmap();
  al_set_target_bitmap (m_towerBitmap);
  al_clear_to_color (al_map_rgb (0, 255, 0));
  al_set_target_bitmap(pOldTargetBitmap);
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



void Tower::draw() const
{
  al_draw_bitmap (m_towerBitmap, (m_xIndex * 64) + 8, (m_yIndex * 64) + 8, 0);
}


bool Tower::onTile (unsigned int tilePosition_x, unsigned int tilePosition_y) const
{
  return ((tilePosition_x == m_xIndex) && (tilePosition_y == m_yIndex));
}
