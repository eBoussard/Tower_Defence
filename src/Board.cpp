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

  displayWidth_ = ui.displayWidth;
  displayHeight_ = ui.displayHeight;
  boardHeight_ = ui.boardHeight;
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



unsigned int Board::getEntranceTile() const
{
  return entranceTile_;
}


unsigned int Board::getExitTile() const
{
  return exitTile_;
}
