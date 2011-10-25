//! The playable area

//! Board's size is either 1280 by 640 pixels (low resolution) or 1920
//! by 640 pixels (high resolution),
//! depending on the user's choice. The grid, Enemy,
//! Tower, entrance and exit are all drawn on Board.

#ifndef BOARD_HPP
#define BOARD_HPP
#include <allegro.h>






class Board
{
public:
  Board();

  //! Method to draw elements designed for the high resolution
  void highResDraw() const;

  //! Method to draw elements designed for the low resolution
  void lowResDraw() const;




  //! Detect where on Board mouse has been clicked
  //! @param x pixel position on x-axis
  //! @param y pixel position on y-axis
  void mouseClick(unsigned int x, unsigned int y);




  //! Detect if the pixel coordinate is on a tile
  //!
  //! The x and y parameters are pixel coordinates that may correspond
  //! to a tile. If the pixel is on a tile, the tile coordinates
  //! are returned in gridPositionX and gridPositionX.
  //! @param x pixel position on x-axis
  //! @param y pixel position on y-axis
  //! @param[out] gridPositionX tile position on x-axis
  //! containing the pixels x and y
  //! @param[out] gridPositionY tile position on y-axis
  //! containing the pixels x and y
  //! @return true if the pixel position is on a tile
  bool getTileCoordinates(unsigned int x, unsigned int y, unsigned int &gridPositionX, unsigned int &gridPositionY) const;





  //! Get the tile position of the @ref entranceTile_ "entrance tile"
  //! 
  //! The @ref entranceTile_ "entrance tile" is always located along the left wall of Board.
  //! @return entrance tile position on y-axis
  unsigned int getEntranceTile() const;





  //! Get the tile position of the @ref exitTile_ "exit tile"
  //!
  //! The exit tile is always located along the right wall of Board.
  //! @return exit tile position on y-axis
  unsigned int getExitTile() const;





private:
  Board(const Board&);
  Board & operator = (const Board&);



  void drawLowResBackground() const;
  void drawHighResBackground() const;

  void drawLowResGrid() const;
  void drawHighResGrid() const;

  void drawLowResExit() const;
  void drawHighResExit() const;

  void drawEntrance() const;






  //! Width of the low resolution
  unsigned int lowResWidth_;

  //! Height of the whole low resolution screen (both Board and ScoreBoard)
  unsigned int lowResDisplayHeight_;

  //! Height of Board on low resolution
  unsigned int lowResBoardHeight_;

  //! Width of the high resolution
  unsigned int highResWidth_;

  //! Height of the whole high resolution screen (both Board and ScoreBoard)
  unsigned int highResDisplayHeight_;

  //! Height of Board on high resolution
  unsigned int highResBoardHeight_;




  //! Location of entrance on Board
  const unsigned int entranceTile_;

  //! Location of exit on Board
  const unsigned int exitTile_;

  //! The size of a tile on Board
  const unsigned int tileSize_;

  //! The 1280 by 640 pixel background
  ALLEGRO_BITMAP *Background_;

  //! The 32 by 64 pixel green colored "fading light"-style entrance
  ALLEGRO_BITMAP *Entrance_;

  //! The 32 by 64 pixel red colored "fading light"-style exit
  ALLEGRO_BITMAP *Exit_;

  ALLEGRO_COLOR gridColor_;
  ALLEGRO_COLOR temporaryBlackBackground_;
};


#endif //BOARD_HPP
