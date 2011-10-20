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
  unsigned int m_playSpeed;
};



#endif //ENGINE_HPP
