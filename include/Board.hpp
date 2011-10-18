#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();
  void debugPrint() const;
  void draw() const;
  void mouseClick(unsigned int x, unsigned int y);
  bool createTower(unsigned int x, unsigned int y, unsigned int &gridPosition_x, unsigned int &gridPosition_y) const;



private:
  Board(const Board&);
  Board & operator = (const Board&);

  void drawBackground() const;
  void drawGrid() const;
  void drawEntrance() const;
  void drawExit() const;



  //Properties
  const unsigned int m_max_x;
  const unsigned int m_min_x;
  const unsigned int m_max_y;
  const unsigned int m_min_y;
  const unsigned int m_entranceLower;
  const unsigned int m_entranceUpper;
  const unsigned int m_exitLower;
  const unsigned int m_exitUpper;
  const unsigned int m_tileSize;
};



#endif //BOARD_HPP
