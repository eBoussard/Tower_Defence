//! Placed by Player in order to kill Enemy

#ifndef TOWER_HPP
#define TOWER_HPP
#include <allegro.h>



class Tower
{
public:

  //! @param xIndex tower's position on x-axis on Board
  //! @param yIndex tower's position on y-axis on Board
  Tower(unsigned int xIndex, unsigned int yIndex);

  void Draw() const;

  //! Find out if Tower is positioned on this tile
  //! @param tilePositionX tile position on x-axis
  //! @param tilePositionY tile position on y-axis
  bool onTile(unsigned int tilePositionX, unsigned int tilePositionY) const;


  unsigned int getDamage() const;
  unsigned int getPrice() const;
  unsigned int getRange() const;
  unsigned int getSellValue() const;
  unsigned int getShootingSpeed() const;


private:
  Tower(const Tower& );
  Tower & operator =(const Tower&);


  //Properties
  //! Tower shoots at a certain pace
  unsigned int shootingSpeed_;

  //! Tower can only shoot within a certain range of itself
  unsigned int Range_;

  //! The number of money required to purchase Tower
  unsigned int Price_;

  //! The number of health Tower will remove from Enemy per attack
  unsigned int Damage_;

  //! Tower may be sold back for money
  unsigned int sellValue_;


  const unsigned int xIndex_;
  const unsigned int yIndex_;
  //! An image representing Tower
  ALLEGRO_BITMAP *towerBitmap_;
  const unsigned int towerBitmapSize_;

  ALLEGRO_BITMAP *targetBitmapHolder_;
};



#endif //TOWER_HPP
