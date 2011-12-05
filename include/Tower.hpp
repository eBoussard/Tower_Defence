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
      unsigned int getPrice() const;
      unsigned int getRange() const;
      unsigned int getSellValue() const;
      unsigned int getShootingSpeed() const;


private:
      Tower(const Tower& );
      Tower & operator =(const Tower&);

      const unsigned int shootingSpeed_;
      const unsigned int Range_;
      const unsigned int Price_;
      const unsigned int Damage_;
      const unsigned int sellValue_;


      const gridPosition gridX_;
      const gridPosition gridY_;
      const unsigned int towerBitmapSize_;

      ALLEGRO_BITMAP *towerBitmap_;
      ALLEGRO_BITMAP *targetBitmapHolder_;
};

#endif //TOWER_HPP
