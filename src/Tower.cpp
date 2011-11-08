#include <Tower.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_image.h>



Tower::Tower(unsigned int xIndex, unsigned int yIndex):Price_(20), Damage_(100), shootingSpeed_(100), Range_(100), sellValue_(15), xIndex_(xIndex), yIndex_(yIndex), towerBitmapSize_(48)
{
  al_init();
  al_init_image_addon();

  towerBitmap_ = al_create_bitmap (towerBitmapSize_, towerBitmapSize_);


  targetBitmapHolder_ = al_get_target_bitmap();
  al_set_target_bitmap (towerBitmap_);
  al_clear_to_color (al_map_rgb (0, 255, 0));
  al_set_target_bitmap(targetBitmapHolder_);
}



void Tower::Draw() const
{
  al_draw_bitmap (towerBitmap_, (xIndex_ * 64) + 8, (yIndex_ * 64) + 8, 0);
}


bool Tower::onTile (unsigned int tilePositionX, unsigned int tilePositionY) const
{
  return ((tilePositionX == xIndex_) && (tilePositionY == yIndex_));
}




unsigned int Tower::getDamage() const
{
    return Damage_;
}

unsigned int Tower::getPrice() const
{
    return Price_;
}

unsigned int Tower::getRange() const
{
    return Range_;
}

unsigned int Tower::getSellValue() const
{
    return sellValue_;
}

unsigned int Tower::getShootingSpeed() const
{
    return shootingSpeed_;
}


