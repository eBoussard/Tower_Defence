//! "The bad guy"

//! Går från vänster sida (0 på X-axeln) till höger sida (19 på X-axeln) på sin @ref
//! Board::generatePath() "gång". @ref Tower "Torn" skadar @ref Enemy "fienden" när de är nära varanda.

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <allegro.h>
#include <definitions.hpp>


class Enemy
{
public:
      Enemy(gridPosition gridX, gridPosition gridY);

      unsigned int getHealthPoints() const;
      void setHealthPoints(unsigned int t_healthPoints);

      void Draw() const;

      unsigned int getXIndex() const;
      unsigned int getYIndex() const;

      void setXIndex(gridPosition gridX);
      void setYIndex(gridPosition gridY);

private:
      Enemy(const Enemy&);
      Enemy & operator = (const Enemy&);

      //! Ett värde som anger hur många skott av X värde @ref Enemy "fienden" kan ta innan den dör
      unsigned int healthPoints_;
      unsigned int movementSpeed_;

      //! @ref Enemy "Fienden" ger @ref Player "spelaren" pengar när den dör
      unsigned int yieldsMoney_;
      const unsigned int enemyBitmapSize_;
      gridPosition gridX_;
      gridPosition gridY_;
      unsigned int t_healthPoints;
      
      ALLEGRO_BITMAP *enemyBitmap_;
      ALLEGRO_BITMAP *targetBitmapHolder_;
};



#endif //ENEMY_HPP
