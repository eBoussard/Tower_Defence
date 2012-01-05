//! Placeras på Board av Player för att döda Enemy

#ifndef TOWER_HPP
#define TOWER_HPP
#include <allegro.h>
#include <definitions.hpp>

class Tower
{
public:
   Tower(gridPosition gridX, gridPosition gridY);
   void Draw() const;

   //! Tar reda på om Tower finns på en specifik ruta
   bool onTile(gridPosition gridX, gridPosition gridY) const;

   unsigned int getDamage() const;
   static unsigned int getPrice();
   unsigned int getRange() const;
   static unsigned int getSellValue();
   unsigned int getShootingSpeed() const;


private:
   Tower(const Tower& );
   Tower & operator =(const Tower&);

   const unsigned int shootingSpeed_;
   const unsigned int Range_;
   static const unsigned int Price_;
   const unsigned int Damage_;
   static const unsigned int sellValue_;


   const gridPosition gridX_;
   const gridPosition gridY_;
   const unsigned int towerBitmapSize_;

   ALLEGRO_BITMAP *towerBitmap_;
   ALLEGRO_BITMAP *targetBitmapHolder_;
};

#endif //TOWER_HPP
