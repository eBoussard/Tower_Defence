#include <Board.hpp>
#include <iostream>
#include <time.h>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>

Board::Board(): tileSize_(64), boardWidth_(1280), boardHeight_(640)
{
      srand (time (NULL));
 
      al_init();
      al_init_primitives_addon();
      al_init_image_addon();

      Entrance_ = al_load_bitmap ("gfx/entrance.bmp");
      Exit_ = al_load_bitmap ("gfx/exit.bmp");
      enemyPathBitmap_ = al_create_bitmap (tileSize_ / 2, tileSize_ / 2);
      al_set_target_bitmap (enemyPathBitmap_);
      al_clear_to_color (al_map_rgb (255, 255, 255));

      gridColor_ = al_map_rgb (255, 0, 0);
      blackBackground_ = al_map_rgb (0, 0, 0);


      generateEntranceExitPositions();
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

////////////////////////////////////
// PUBLIC METHODS //
///////////////////////////////////

void Board::Draw() const
{
      drawBackground();
      drawGrid();
      drawEntrance();
      drawExit();
      drawEnemyPath();
}

void Board::mouseClick(pixelPosition x, pixelPosition y)
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

bool Board::getTileCoordinates (pixelPosition x, pixelPosition y, gridPosition &gridX, gridPosition &gridY) const
{
      if (y < boardHeight_)
	    {
		  gridX = x / tileSize_;
		  gridY = y / tileSize_;
		  return true;
	    }
      return false;
}

unsigned int Board::getEntranceTile() const
{
      return entranceTile_;
}


unsigned int Board::getExitTile() const
{
      return exitTile_;
}

bool Board::onEnemyPath (gridPosition gridX, gridPosition gridY) const
{
      for (std::vector<std::pair<unsigned int, unsigned int> >::const_iterator it = enemyPath_.begin(); it != enemyPath_.end(); ++it)
	    {
		  const std::pair<gridPosition, gridPosition> &enemyTile = *it;

		  if ((gridX == enemyTile.first) && (gridY == enemyTile.second))
			return true;
	    }
      return false;
}

void Board::getEnemyPosition(unsigned int enemyStep, gridPosition &gridX, gridPosition &gridY)
{
      gridX = enemyPath_[enemyStep].first;
      gridY = enemyPath_[enemyStep].second;
}

/////////////////////////////////////
// PRIVATE METHODS //
/////////////////////////////////////

unsigned int Board::getRand(unsigned int Min, unsigned int Max)
{
      return (rand() % (Max - Min) + Min);
}

void Board::generatePath (gridPosition gridXEnd, gridPosition gridYEnd)
{
      while(! ((enemyPathX_ == gridXEnd) && (enemyPathY_ == gridYEnd)))
	    {
		  // Sista delen (efter &&) används inte just nu, eftersom path inte går tillbaks
		  if ((rand() % 2) && (enemyPathX_ < gridXEnd) && (! onEnemyPath(enemyPathX_ + 1, enemyPathY_)))
			++enemyPathX_;

		  else if ((enemyPathY_ > gridYEnd) && (enemyPathY_ != 0) && (!onEnemyPath(enemyPathX_, enemyPathY_ - 1)))
			--enemyPathY_;

		  else if ((enemyPathY_ < gridYEnd) && (enemyPathY_ != gridYEnd) && (!onEnemyPath(enemyPathX_, enemyPathY_ + 1)))
			++enemyPathY_;

		  enemyPath_.push_back(std::make_pair(enemyPathX_,enemyPathY_));
		  std::cout << "Adding enemy path tiles:\nX: " << enemyPathX_ << "\nY: " << enemyPathY_ << std::endl;
	    }
}

void Board::generateEntranceExitPositions()
{
      entranceTile_ = 0;
      exitTile_ = 0;

      while ((entranceTile_ - exitTile_ < 6) || (exitTile_ - entranceTile_ < 6))
	    {
		  entranceTile_ = rand() % 9 + 1;
		  exitTile_ = rand() % 9 + 1;
	    }
}

////////////////////////
// DRAWING //
//////////////////////

void Board::drawBackground() const
{
      al_clear_to_color (blackBackground_);
}

void Board::drawGrid() const
{
      for (int hPos = tileSize_; hPos <= boardHeight_; hPos += tileSize_)
	    {
		  al_draw_line(0, hPos, boardWidth_, hPos, gridColor_, 2);
	    }

      for (int vPos = tileSize_; vPos < boardWidth_; vPos += tileSize_)
	    {
		  al_draw_line(vPos, 0, vPos, boardHeight_, gridColor_, 2);
	    }
}

void Board::drawExit() const
{
      al_draw_bitmap (Exit_, (boardWidth_ - (tileSize_ / 2)), (exitTile_ * 64), 0);
}

void Board::drawEntrance() const
{
      al_draw_bitmap (Entrance_, 0, (entranceTile_ * tileSize_), 0);
}

void Board::drawEnemyPath() const
{
      for (std::vector<std::pair<gridPosition, gridPosition> >::const_iterator it = enemyPath_.begin(); it != enemyPath_.end(); ++it)
	    {
		  const std::pair<gridPosition, gridPosition> & enemyTile = *it;

		  al_draw_bitmap (enemyPathBitmap_, ((enemyTile.first * tileSize_) + 16), ((enemyTile.second * tileSize_) + 16), 0);
	    }
}

