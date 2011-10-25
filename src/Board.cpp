#include <Board.hpp>
#include <UI.hpp>

#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>



Board::Board():entranceTile_(1), exitTile_(8), tileSize_(64)
{
  al_init();
  al_init_primitives_addon();
  al_init_image_addon();

  Background_ = al_load_bitmap ("gfx/background.bmp");
  Entrance_ = al_load_bitmap ("gfx/entrance.bmp");
  Exit_ = al_load_bitmap ("gfx/exit.bmp");

  gridColor_ = al_map_rgb (255, 0, 0);
  temporaryBlackBackground_ = al_map_rgb (0, 0, 0);

  UI ui;

  lowResWidth_ = ui.lowResWidth;
  lowResHeight_ = ui.lowResHeight;

  highResWidth_ = ui.highResWidth;
  highResHeight_ = ui.highResHeight;
}



void Board::lowResDraw() const
{
  drawLowResBackground();
  drawLowResGrid();
  drawEntrance();
  drawExit();
}



void Board::highResDraw() const
{
  drawHighResBackground();
  drawHighResGrid();
  drawEntrance();
  drawExit();
}



void Board::mouseClick(unsigned int x, unsigned int y)
{
  unsigned int x_leftBorder, y_topBorder;

  x_leftBorder = tileSize_ * (x / tileSize_);
  y_topBorder = tileSize_ * (y / tileSize_);
  if (y < lowResHeight_)
    {
      std::cout << "mouse clicked on board\n";
      std::cout << "X: " << x_leftBorder << "\nY: " << y_topBorder << std::endl;
    }
}



bool Board::getTileCoordinates (unsigned int x, unsigned int y, unsigned int &gridPositionX, unsigned int &gridPositionY) const
{
  if (y < lowResHeight_)
    {
      gridPositionX = x / tileSize_;
      gridPositionY = y / tileSize_;
      return true;
    }
  return false;
}




void Board::drawLowResBackground() const
{
  //al_draw_bitmap (Background_, 0, 0, 0);
  al_clear_to_color (temporaryBlackBackground_);
}


void Board::drawHighResBackground() const
{
  al_clear_to_color (temporaryBlackBackground_);
}


void Board::drawLowResGrid() const
{
  for(int lowResHPos = tileSize_; lowResHPos <= lowResHeight_; lowResHPos += tileSize_)
    {
      al_draw_line(0, lowResHPos, lowResWidth_, lowResHPos, gridColor_, 2);
    }

  for(int lowResVPos = tileSize_; lowResVPos < lowResWidth_; lowResVPos += tileSize_)
    {
      al_draw_line(lowResVPos, 0, lowResVPos, lowResHeight_, gridColor_, 2);
    }
}


void Board::drawHighResGrid() const
{
  for(int highResHPos = tileSize_; highResHPos <= lowResHeight_; highResHPos += tileSize_)
    {
      al_draw_line (0, highResHPos, lowResWidth_, highResHPos, gridColor_, 2);
    }

  for(int highResVPos = tileSize_; highResVPos < lowResWidth_; highResVPos += tileSize_)
    {
      al_draw_line(0, highResVPos, lowResHeight_, highResVPos, gridColor_, 2);
    }	
}
	




void Board::drawEntrance() const
{
  al_draw_bitmap (Entrance_, 0, (entranceTile_ * tileSize_), 0);
}




void Board::drawExit() const
{
  al_draw_bitmap (Exit_, 1248, (exitTile_ * 64), 0);
}



unsigned int Board::getEntranceTile() const
{
  return entranceTile_;
}


unsigned int Board::getExitTile() const
{
  return exitTile_;
}
