#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <allegro.h>



class Enemy
{
public:
  Enemy();

  ALLEGRO_BITMAP * getBitmap() const;



private:
  Enemy(const Enemy&);
  Enemy & operator = (const Enemy&);



  //Properties
  unsigned int m_healthPoints;
  unsigned int m_movementSpeed;
  unsigned int m_yieldsMoney;
};



#endif //ENEMY_HPP
