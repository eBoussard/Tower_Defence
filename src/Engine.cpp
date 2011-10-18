#include <Engine.hpp>
#include <iostream>


Engine::Engine():m_playSpeed(100)
{ }


void Engine::debugPrint() const
{
  std::cout << "Engine\n";
  std::cout << "playSpeed: " << m_playSpeed << "\n\n";
}
