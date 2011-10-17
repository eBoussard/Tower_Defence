#include <Board.hpp>
#include <iostream>
#include <allegro.h>
#include <allegro_primitives.h>



Board::Board():m_Size_x(1280), m_Size_y(640),  m_EntranceLower(128), m_EntranceUpper(64), m_ExitLower(576), m_ExitUpper(512)
{
  al_init();
  al_init_primitives_addon();
}


void Board::debugPrint() const
{
  std::cout << "Board\n";
  std::cout << "Size_x: " << m_Size_x << "\n";
  std::cout << "Size_y: " << m_Size_y << "\n";
  std::cout << "EntranceLower: " << m_EntranceLower << "\n";
  std::cout << "EntranceUpper: " << m_EntranceUpper << "\n";
  std::cout << "ExitLower: " << m_ExitLower << "\n";
  std::cout << "ExitUpper: " << m_ExitUpper << "\n\n";
}


void Board::draw() const
{
  drawBackground();
  drawTiles();
  drawEntrance();
  drawExit();
}

void Board::drawBackground() const
{
  al_clear_to_color(al_map_rgb(0,0,0));
}

void Board::drawTiles() const
{
  for(int h_pos = 64; h_pos < 640; h_pos += 64)
    {
      al_draw_line(0, h_pos, m_Size_x, h_pos, al_map_rgb(127,127,127), 2);
    }
  for(int v_pos = 64; v_pos < 1280; v_pos += 64)
    {
      al_draw_line(v_pos, 0, v_pos, m_Size_y, al_map_rgb(127,127,127), 2);
    }
}

void Board::drawEntrance() const
{
  al_draw_line(0,m_EntranceUpper, 0, m_EntranceLower, al_map_rgb(0,255,0), 3);
}

void Board::drawExit() const
{
  al_draw_line(m_Size_x ,m_ExitUpper, m_Size_x, m_ExitLower, al_map_rgb(255,0,0), 3);
}

