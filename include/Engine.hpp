//! Controls events such as movement of Enemy

#ifndef ENGINE_HPP
#define ENGINE_HPP



class Engine
{
public:
  Engine();

  int test();

private:
  Engine(const Engine&);
  Engine & operator = (const Engine&);



  //Properties

  //! Makes the game run at a certain pace
  unsigned int playSpeed_;
};



#endif //ENGINE_HPP
