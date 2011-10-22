//! The playable area

//! The board is the 1280 by 640 pixel area where event such as
//! placement of Tower, movement of Enemy and movement of Ammunition
//! takes place.

#ifndef BOARD_HPP
#define BOARD_HPP



class Board
{
public:
  Board();

  //! Draw visual elements on Board
  void Draw() const;

  //! Detect where on Board mouse has been clicked
  void mouseClick(unsigned int x, unsigned int y);

  //! Detect if a pixel coordinate is on a tile and return the tile coordinates 
  //!
  //! The x and y parameters are pixel coordinates that may correspond
  //! to a tile. If the pixel is on a tile, a true value is returned
  //! and the tile index coordinates
  //! are returned in gridPositionX and gridPositionX.
  //! @param x x-coordinate of the pixel
  //! @param y y-coordinate of the pixel
  //! @param gridPositionX The zero-based x-index of the tile
  //! containing the point x, y
  //! @param gridPositionY The zero-based y-index of the tile
  //! containing the point x, y
  //! @return true if the given pixel is on a tile of the board
  bool getTileCoordinates(unsigned int x, unsigned int y, unsigned int &gridPosition_x, unsigned int &gridPosition_y) const;

  //! Get the index of the entrance tile
  //! 
  //! The entrance tile is always located along the left wall of Board.
  //! The entrance tile position is fully determined by the
  //! zero-based y-index from the top of the board
  //!
  //! @return The zero-based index of the entrance tile of Board
  unsigned int getEntranceTile() const;

  //! Get the index of the exit tile
  //!
  //! The exit tile is always located along the right wall of Board.
  //! The exit tile position is fully determined by the zero-based
  //! y-index from the top of the board.
  //!
  //! @return The zero-based index of the exit tile of Board
  unsigned int getExitTile() const;



private:
  Board(const Board&);
  Board & operator = (const Board&);


  void drawBackground() const;

  //! Draw the grid

  //! The grid consists of 200 tiles, 0-19 on the y-axis and 0-9 on
  //! the x-axis
  void drawGrid() const;
  void drawEntrance() const;
  void drawExit() const;



  //Properties
  const unsigned int screenWidth_;
  const unsigned int screenHeight_;
  const unsigned int entranceTile_;
  const unsigned int exitTile_;
  const unsigned int tileSize_;
};


#endif //BOARD_HPP
