#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();
  void debugPrint() const;
  void draw() const;
  void MouseClick(unsigned int x, unsigned int y);
  bool CreateTower(unsigned int x, unsigned int y, unsigned int &Grid_x, unsigned int &Grid_y) const;


private:
  Board(const Board&);
  Board & operator = (const Board&);

  void drawBackground() const;
  void drawTiles() const;
  void drawEntrance() const;
  void drawExit() const;


  //Properties
  const unsigned int m_Size_x;
  const unsigned int m_Size_y;
  const unsigned int m_EntranceLower;
  const unsigned int m_EntranceUpper;
  const unsigned int m_ExitLower;
  const unsigned int m_ExitUpper;
};


#endif //BOARD_HPP
