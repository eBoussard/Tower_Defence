#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();
  void debugPrint() const;
  void draw() const;
  void mouseClick(unsigned int x, unsigned int y);
  bool getTileCoordinates(unsigned int x, unsigned int y, unsigned int &gridPosition_x, unsigned int &gridPosition_y) const;
  unsigned int getEntranceTile() const;
  unsigned int getExitTile() const;



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
  const unsigned int m_entranceTile;
  const unsigned int m_exitTile;
  const unsigned int m_tileSize;
};



#endif //BOARD_HPP
