#ifndef TOWER_HPP
#define TOWER_HPP
#include <allegro.h>



class Tower
{
public:
  Tower();
  void debugPrint() const;
  ALLEGRO_BITMAP * getBitmap() const;

private:
  Tower(const Tower&);
  Tower & operator = (const Tower&);

  //Properties
  unsigned int m_Price;
  unsigned int m_Damage;
  unsigned int m_ShootingSpeed;
  unsigned int m_Range;
  unsigned int m_SellValue;
};


#endif //TOWER_HPP
