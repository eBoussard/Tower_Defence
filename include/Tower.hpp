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

  //! Find out if Tower is positioned on a perticular tile
  //! @param tilePositionX tile position on x-axis
  //! @param tilePositionY tile position on y-axis
  bool onTile(unsigned int tilePositionX, unsigned int tilePositionY) const;


private:
  Tower(const Tower&);
  Tower & operator = (const Tower&);



  //Properties
  unsigned int Price_;
  unsigned int Damage_;

  //! Tower shoots at a certain pace
  unsigned int shootingSpeed_;

  //! Tower can only shoot within a certain range of itself
  unsigned int Range_;

  //! Tower can be sold back for a certain value
  unsigned int sellValue_;
  const unsigned int xIndex_;
  const unsigned int yIndex_;

  //! An image representing Tower
  ALLEGRO_BITMAP *towerBitmap_;
  int towerBitmapSize_;
};



#endif //TOWER_HPP
