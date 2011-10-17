#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();
  void debugPrint() const;


private:
  Board(const Board&);
  Board & operator = (const Board&);


  //Properties
  const unsigned int m_Size_x;
  const unsigned int m_Size_y;
  const unsigned int m_EntranceLower;
  const unsigned int m_EntranceUpper;
  const unsigned int m_ExitLower;
  const unsigned int m_ExitUpper;
};


#endif //BOARD_HPP
