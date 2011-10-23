//! Moves from entrance to exit and avoids Tower

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <allegro.h>



class Enemy
{
public:
  Enemy();

  //! The image representing Tower
  ALLEGRO_BITMAP * getBitmap() const;



private:
  Enemy(const Enemy&);
  Enemy & operator = (const Enemy&);



  //Properties

  //! Enemy's health points

  //! Enemy spawns with a certain number of health points. These
  //! health points are decreased when shot by Tower. When they reach
  //! zero, Enemy dies (despawns).
  unsigned int healthPoints_;

  unsigned int movementSpeed_;

  //! Enemy will upon death yield a certain amount of money.
  unsigned int yieldsMoney_;
};



#endif //ENEMY_HPP
