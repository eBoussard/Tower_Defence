//! The playable area

//! Board's size is 1280 by 640 pixels (the last 80 pixels on the
//! Y-axis being ScoreBoard). The grid, Enemy,
//! Tower, entrance and exit are all drawn on Board.

#ifndef BOARD_HPP
#define BOARD_HPP
#include <allegro.h>
#include <vector>





class Board
{
public:
  Board();

  void Draw() const;


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

  void generatePath (unsigned int endPointX, unsigned int endPointY);

  void generateRandomPositions();

  bool onEnemyPath(unsigned int tileX, unsigned int tileY) const;

  void drawBackground() const;

  void drawGrid() const;

  void drawExit() const;

  void drawEntrance() const;

  //! Method to draw (or rather mark) the path for Enemy to walk on
  void drawEnemyPath() const;

  //! All tiles of the Enemy path
  std::vector<std::pair<unsigned int, unsigned int> > enemyPath_;


  unsigned int displayWidth_;

  //! Height of the whole low resolution screen (both Board and ScoreBoard)
  unsigned int displayHeight_;

  //! Height of Board on low resolution
  unsigned int boardHeight_;


  //! Location of entrance on Board
  unsigned int entranceTile_;

  //! Location of exit on Board
  unsigned int exitTile_;

  unsigned int enemyPathX_;

  unsigned int enemyPathY_;

  //! The size of a tile on Board
  const unsigned int tileSize_;


  ALLEGRO_BITMAP *Background_;

  //! The 32 by 64 pixel green colored "fading light"-style entrance
  ALLEGRO_BITMAP *Entrance_;

  //! The 32 by 64 pixel red colored "fading light"-style exit
  ALLEGRO_BITMAP *Exit_;

  ALLEGRO_COLOR gridColor_;

  ALLEGRO_COLOR temporaryBlackBackground_;

  ALLEGRO_BITMAP *enemyPathBitmap_;
};


#endif //BOARD_HPP
