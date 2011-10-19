#ifndef TOWER_HPP
#define TOWER_HPP
#include <allegro.h>



class Tower
{
public:
  Tower(unsigned int xIndex, unsigned int yIndex);
  void debugPrint() const;
  ALLEGRO_BITMAP * getBitmap() const;
  unsigned int getXIndex() const;
  unsigned int getYIndex() const;



private:
  Tower(const Tower&);
  Tower & operator = (const Tower&);



  //Properties
  unsigned int m_Price;
  unsigned int m_Damage;
  unsigned int m_shootingSpeed;
  unsigned int m_Range;
  unsigned int m_sellValue;
  const unsigned int m_xIndex;
  const unsigned int m_yIndex;
};



#endif //TOWER_HPP
