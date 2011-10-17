#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <allegro.h>



class Enemy
{
public:
  Enemy();
  void debugPrint() const;
  ALLEGRO_BITMAP * getBitmap() const;


private:
  Enemy(const Enemy&);
  Enemy & operator = (const Enemy&);


  //Properties
  unsigned int m_HealthPoints;
  unsigned int m_MovementSpeed;
  unsigned int m_YieldsMoney;
};


#endif //ENEMY_HPP
