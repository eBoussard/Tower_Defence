#ifndef ENGINE_HPP
#define ENGINE_HPP

class Engine
{
public:
  Engine();
  void debugPrint() const;

private:
  Engine(const Engine&);
  Engine & operator = (const Engine&);

  //Properties
  unsigned int m_SpeedOfPlay;
};


#endif //ENGINE_HPP
