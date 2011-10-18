#include <Ammunition.hpp>
#include <iostream>



Ammunition::Ammunition():m_Location(100)
{ }



void Ammunition::debugPrint() const
{
  std::cout << "Ammunition\n";
  std::cout << "Location: " << m_Location << "\n\n";
}
