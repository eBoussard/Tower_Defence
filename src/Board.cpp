#include <Board.hpp>
#include <iostream>



Board::Board():m_Size_x(1280), m_Size_y(640),  m_EntranceLower(128), m_EntranceUpper(64), m_ExitLower(576), m_ExitUpper(512)
{ }


void Board::debugPrint() const
{
  std::cout << "Board\n";
  std::cout << "Size_x: " << m_Size_x << "\n";
  std::cout << "Size_y: " << m_Size_y << "\n";
  std::cout << "EntranceLower: " << m_EntranceLower << "\n";
  std::cout << "EntranceUpper: " << m_EntranceUpper << "\n";
  std::cout << "ExitLower: " << m_ExitLower << "\n";
  std::cout << "ExitUpper: " << m_ExitUpper << "\n\n";
}
