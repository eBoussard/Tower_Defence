#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();
  void draw() const;
  void mouseClick(unsigned int x, unsigned int y);

  /// \brief Detect if a pixel coord is on a tile and return the tile coordinates. 
  ///
  ///The x and y parameters are pixel coordinates that may correspond
  /// to a tile. If the pixel is on a tile, a true value is returned
  /// and the tile index coordinates.
  /// are returned in gridPosition_x and gridPosition_y.
  /// \param x x-coordinate of the pixel
  /// \param y y-coordinate of the pixel
  /// \param gridPosition_x The zero-based x-index of the tile
  /// containing the point x,y
  /// \param gridPosition_y The zero-based y-index of the tile
  /// containing the point x,y
  /// \return true if the given pixel is on a tile of the board
  bool getTileCoordinates(unsigned int x, unsigned int y, unsigned int &gridPosition_x, unsigned int &gridPosition_y) const;
  /// \brief Get the entrance tile
  /// 
  /// The entrance tile is always placed along the left wall of the
  /// board. The entrance tile position is fully determined by the
  /// 0-based y-index from the top of the board
  ///
  /// \return The zero based index of the entrance tile of the board
  unsigned int getEntranceTile() const;
  /// \brief Get the index of the exit tile
  ///
  /// The exit tile is always located along the right wall of the
  /// board, so its location is fully determined by the 0-based
  /// y-index from the top of the board.
  ///
  /// \return The zero based index of the exit tile of the boards
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
