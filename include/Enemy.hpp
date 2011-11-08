//! Moves from @ref entranceTile_ "entrance" to @ref exitTile_ "exit" and avoids Tower

//! Enemy moves from @ref entranceTile_ "entrance" to @ref exitTile_
//! "exit". It spawns with a set number of @ref healthPoints_ "health
//! points" which decreases when shot by Tower. When Enemy's health
//! points reaches zero it will despawn (die).

//! Enemy tries to find the shortest route to @ref exitTile_ "exit"
//! while avoiding Tower.

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <allegro.h>



class Enemy
{
public:
  Enemy(unsigned int xIndex, unsigned int yIndex);

  void Draw() const;



  unsigned int getXIndex() const;
  unsigned int getYIndex() const;

  void setXIndex(unsigned int xIndex);
  void setYIndex(unsigned int yIndex);

private:
  Enemy(const Enemy&);
  Enemy & operator = (const Enemy&);



  //Properties

  //! Enemy's health points

  //! Enemy spawns with a certain number of health points. These
  //! health points are decreased when shot by Tower. Upon reaching
  //! zero, Enemy despawns.
  unsigned int healthPoints_;

  unsigned int movementSpeed_;

  //! Enemy will yield a set amount of money when killed

  //! Money collected from slain Enemy is used to purchase and/or
  //! upgrade Tower.
  unsigned int yieldsMoney_;


  const unsigned int enemyBitmapSize_;


  unsigned int xIndex_;
  unsigned int yIndex_;



  ALLEGRO_BITMAP *enemyBitmap_;
  ALLEGRO_BITMAP *targetBitmapHolder_;

};



#endif //ENEMY_HPP
