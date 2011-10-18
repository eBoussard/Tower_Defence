#include <Player.hpp>
#include <iostream>



Player::Player():m_Money(100), m_healthPoints(100)
{ }


void Player::debugPrint() const
{
  std::cout << "Player\n";
  std::cout << "Money: " << m_Money << "\n";
  std::cout << "healthPoints: " << m_healthPoints << "\n\n";
}
