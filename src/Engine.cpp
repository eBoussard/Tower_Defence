#include <Engine.hpp>
#include <iostream>


Engine::Engine():m_SpeedOfPlay(100)
{ }


void Engine::debugPrint() const
{
  std::cout << "Engine\n";
  std::cout << "SpeedOfPlay: " << m_SpeedOfPlay << "\n\n";
}
