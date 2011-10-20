#include <Board.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>



Board::Board():m_max_x(1280), m_min_x(0), m_max_y(640), m_min_y(0),  m_entranceTile(1), m_exitTile(8), m_tileSize(64)
{
  al_init();
  al_init_primitives_addon();
}



void Board::draw() const
{
  drawBackground();
  drawGrid();
  drawEntrance();
  drawExit();
}



void Board::mouseClick(unsigned int x, unsigned int y)
{
  unsigned int x_leftBorder, y_topBorder;

  x_leftBorder = m_tileSize * (x / m_tileSize);
  y_topBorder = m_tileSize * (y / m_tileSize);
  if (y < m_max_y)
    {
      std::cout << "mouse clicked on board\n";
    }
}


//QUESTION Why bool?
bool Board::getTileCoordinates (unsigned int x, unsigned int y, unsigned int &gridPosition_x, unsigned int &gridPosition_y) const
{
  if (y < m_max_y)
    {
      gridPosition_x = x / m_tileSize;
      gridPosition_y = y / m_tileSize;
      return true;
    }
  return false;
}




void Board::drawBackground() const
{
  al_clear_to_color(al_map_rgb(0,0,0));
}




void Board::drawGrid() const
{
  for(int hPos = m_tileSize; hPos <= m_max_y; hPos += m_tileSize)
    {
      al_draw_line(m_min_x, hPos, m_max_x, hPos, al_map_rgb(127,127,127), 2);
    }
  for(int vPos = m_tileSize; vPos < m_max_x; vPos += m_tileSize)
    {
      al_draw_line(vPos, m_min_y, vPos, m_max_y, al_map_rgb(127,127,127), 2);
    }
}




void Board::drawEntrance() const
{
  al_draw_line(m_min_x + 2, m_entranceTile * m_tileSize, m_min_x + 2, (m_entranceTile + 1) * m_tileSize, al_map_rgb(0,255,0), 3);
}




void Board::drawExit() const
{
  al_draw_line(m_max_x, m_exitTile * m_tileSize, m_max_x, (m_exitTile + 1) * m_tileSize, al_map_rgb(255,0,0), 3);
}



unsigned int Board::getEntranceTile() const
{
  return m_entranceTile;
}


unsigned int Board::getExitTile() const
{
  return m_exitTile;
}
