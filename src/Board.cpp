#include <Board.hpp>
#include <UI.hpp>

#include <iostream>
#include <time.h>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>



Board::Board(): tileSize_(64)
{
  srand (time (NULL));


  al_init();
  al_init_primitives_addon();
  al_init_image_addon();

  Background_ = al_load_bitmap ("gfx/background.bmp");
  Entrance_ = al_load_bitmap ("gfx/entrance.bmp");
  Exit_ = al_load_bitmap ("gfx/exit.bmp");

  gridColor_ = al_map_rgb (255, 0, 0);
  temporaryBlackBackground_ = al_map_rgb (0, 0, 0);



  ALLEGRO_BITMAP *pOldTargetBitmap;
  pOldTargetBitmap = al_get_target_bitmap();

  enemyPathBitmap_ = al_create_bitmap (tileSize_ / 2, tileSize_ / 2);
  al_set_target_bitmap (enemyPathBitmap_);
  al_clear_to_color (al_map_rgb (255, 255, 255));

  al_set_target_bitmap (pOldTargetBitmap);





  UI ui;

  displayWidth_ = ui.displayWidth;
  displayHeight_ = ui.displayHeight;
  boardHeight_ = ui.boardHeight;


  generateRandomPositions();


  enemyPathX_ = 0;
  enemyPathY_ = entranceTile_;

  enemyPath_.push_back(std::make_pair(enemyPathX_, enemyPathY_));

  if (entranceTile_ < 5)
    {
      generatePath(getRand(2, 3), getRand(7, 9));

      generatePath(getRand(5, 6), getRand(0, 2));

      generatePath(getRand(8, 10), getRand(7, 9));

      generatePath(getRand(12, 14), getRand(0, 2));

      generatePath(getRand(16, 18), getRand(7, 9));

      generatePath(19, exitTile_);
    }


  if (entranceTile_ > 5)
    {
      generatePath (getRand(2, 3), getRand(0, 2));

      generatePath(getRand(5, 6), getRand(7, 9));

      generatePath(getRand(8, 10), getRand(0, 2));

      generatePath(getRand(12, 14), getRand(7, 9));

      generatePath(getRand(16, 18), getRand(7, 9));

      generatePath(19, exitTile_);
    }

    
}





void Board::Draw() const
{
  drawBackground();
  drawGrid();
  drawEntrance();
  drawExit();
  drawEnemyPath();
}



int Board::getRand(int Min, int Max)
{
  return (rand() % (Max - Min) + Min);
}


void Board::generateRandomPositions()
{
  entranceTile_ = 0;
  exitTile_ = 0;

  while ((entranceTile_ - exitTile_ < 6) || (exitTile_ - entranceTile_ < 6))
    {
      entranceTile_ = rand() % 9 + 1;
      exitTile_ = rand() % 9 + 1;
    }
}



void Board::generatePath (unsigned int endPointX, unsigned int endPointY)
{
  while(!((enemyPathX_ == endPointX) && (enemyPathY_ == endPointY)))
    {
      if ((rand() % 2) && (enemyPathX_ < endPointX) && (!onEnemyPath(enemyPathX_ + 1, enemyPathY_)))
  	++enemyPathX_;
      
	else if ((enemyPathY_ > endPointY) && (enemyPathY_ != 0) && (!onEnemyPath(enemyPathX_, enemyPathY_ - 1)))
  	--enemyPathY_;
  
  
	else if ((enemyPathY_ < endPointY) && (enemyPathY_ != endPointY) && (!onEnemyPath(enemyPathX_, enemyPathY_ + 1)))
  	++enemyPathY_;
      
  
      enemyPath_.push_back(std::make_pair(enemyPathX_,enemyPathY_));
      std::cout << "Adding enemy path tiles:\nX: " << enemyPathX_ << "\nY: " << enemyPathY_ << std::endl;      
    }
}



bool Board::onEnemyPath (unsigned int tileX, unsigned int tileY) const
{
    for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = enemyPath_.begin(); it != enemyPath_.end(); ++it)
      {
	const std::pair<unsigned int, unsigned int> & enemyTile = *it;

	if ((tileX == enemyTile.first) && (tileY == enemyTile.second))
	  return true;
      }
    return false;
}



void Board::mouseClick(unsigned int x, unsigned int y)
{
  unsigned int x_leftBorder, y_topBorder;

  x_leftBorder = tileSize_ * (x / tileSize_);
  y_topBorder = tileSize_ * (y / tileSize_);
  if (y < boardHeight_)
    {
      std::cout << "mouse clicked on board\n";
      std::cout << "PX: " << x_leftBorder << "\nPY: " << y_topBorder << std::endl;
    }
}



bool Board::getTileCoordinates (unsigned int x, unsigned int y, unsigned int &gridPositionX, unsigned int &gridPositionY) const
{
  if (y < boardHeight_)
    {
      gridPositionX = x / tileSize_;
      gridPositionY = y / tileSize_;
      return true;
    }
  return false;
}




void Board::drawBackground() const
{
  //al_draw_bitmap (Background_, 0, 0, 0);
  al_clear_to_color (temporaryBlackBackground_);
}


void Board::drawGrid() const
{
  for(int hPos = tileSize_; hPos <= boardHeight_; hPos += tileSize_)
    {
      al_draw_line(0, hPos, displayWidth_, hPos, gridColor_, 2);
    }

  for(int vPos = tileSize_; vPos < displayWidth_; vPos += tileSize_)
    {
      al_draw_line(vPos, 0, vPos, boardHeight_, gridColor_, 2);
    }
}



void Board::drawEntrance() const
{
  al_draw_bitmap (Entrance_, 0, (entranceTile_ * tileSize_), 0);
}




void Board::drawExit() const
{
  al_draw_bitmap (Exit_, (displayWidth_ - (tileSize_ / 2)), (exitTile_ * 64), 0);
}



void Board::drawEnemyPath() const
{
  for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = enemyPath_.begin(); it != enemyPath_.end(); ++it)
    {
      const std::pair<unsigned int, unsigned int> & enemyTile = *it;

      al_draw_bitmap (enemyPathBitmap_, ((enemyTile.first * tileSize_) + 16), ((enemyTile.second * tileSize_) + 16), 0);
    }
}



unsigned int Board::getEntranceTile() const
{
  return entranceTile_;
}


unsigned int Board::getExitTile() const
{
  return exitTile_;
}
