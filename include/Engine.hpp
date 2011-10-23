//! Makes the game run

//! Engine controls events like Tower shooting Ammunition and Enemy
//! moving from entrance to exit.

BEGIN          = Shot by Tower and aimed for Enemy
ALLEGRO_BITMAP = An image representing @name
pixelPositionX = Pixel position on x-axis
gridPositionX = Tile position on x-axis
Draw          = EMPTY

  //TODO IMPORTANT

#ifndef ENGINE_HPP
#define ENGINE_HPP



class Engine
{
public:
  Engine();



private:
  Engine(const Engine&);
  Engine & operator = (const Engine&);



  //Properties

  //! Makes the game run at a certain pace
  unsigned int playSpeed_;
};



#endif //ENGINE_HPP
