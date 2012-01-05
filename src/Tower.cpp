#include <Tower.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_image.h>

const unsigned int Tower::Price_ = 20;
const unsigned int Tower::sellValue_ = 15;

Tower::Tower(gridPosition gridX, gridPosition gridY):Damage_(100), shootingSpeed_(100), Range_(100), gridX_(gridX), gridY_(gridY), towerBitmapSize_(48)
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
   al_draw_bitmap (towerBitmap_, (gridX_ * 64) + 8, (gridY_ * 64) + 8, 0);
}


bool Tower::onTile (gridPosition gridX, gridPosition gridY) const
{
   return ((gridX == gridX_) && (gridY == gridY_));
}

unsigned int Tower::getDamage() const
{
   return Damage_;
}

unsigned int Tower::getPrice()
{
   return Price_;
}

unsigned int Tower::getRange() const
{
   return Range_;
}

unsigned int Tower::getSellValue()
{
   return sellValue_;
}

unsigned int Tower::getShootingSpeed() const
{
   return shootingSpeed_;
}


