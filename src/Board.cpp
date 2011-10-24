#include <Board.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_image.h>



Board::Board():screenWidth_(1280), screenHeight_(640), entranceTile_(1), exitTile_(8), tileSize_(64)
{
  al_init();
  al_init_primitives_addon();
  al_init_image_addon();
  Background = al_load_bitmap ("gfx/BG1.bmp");
}



void Board::Draw() const
{
  drawBackground();
  drawGrid();
  drawEntrance();
  drawExit();
}



void Board::mouseClick(unsigned int x, unsigned int y)
{
  unsigned int x_leftBorder, y_topBorder;

  x_leftBorder = tileSize_ * (x / tileSize_);
  y_topBorder = tileSize_ * (y / tileSize_);
  if (y < screenHeight_)
    {
      std::cout << "mouse clicked on board\n";
    }
}



bool Board::getTileCoordinates (unsigned int x, unsigned int y, unsigned int &gridPositionX, unsigned int &gridPositionY) const
{
  if (y < screenHeight_)
    {
      gridPositionX = x / tileSize_;
      gridPositionX = y / tileSize_;
      return true;
    }
  return false;
}




void Board::drawBackground() const
{
  al_draw_bitmap (Background_, 0, 0, 0);
}




void Board::drawGrid() const
{
  for(int hPos = tileSize_; hPos <= screenHeight_; hPos += tileSize_)
    {
      al_draw_line(0, hPos, screenWidth_, hPos, al_map_rgb(127,127,127), 2);
    }
  for(int vPos = tileSize_; vPos < screenWidth_; vPos += tileSize_)
    {
      al_draw_line(vPos, 0, vPos, screenHeight_, al_map_rgb(127,127,127), 2);
    }
}




void Board::drawEntrance() const
{
  al_draw_line(2, (entranceTile_ * tileSize_), 2, ((entranceTile_ + 1) * tileSize_), al_map_rgb(0,255,0), 3);
}




void Board::drawExit() const
{
  al_draw_line(screenWidth_, exitTile_ * tileSize_, screenWidth_, (exitTile_ + 1) * tileSize_, al_map_rgb(255,0,0), 3);
}



unsigned int Board::getEntranceTile() const
{
  return entranceTile_;
}


unsigned int Board::getExitTile() const
{
  return exitTile_;
}
