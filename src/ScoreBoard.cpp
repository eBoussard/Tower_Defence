#include <ScoreBoard.hpp>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>



ScoreBoard::ScoreBoard():m_ButtonSize(40), m_Size_x(1280), m_Size_y(80)
{
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();

  m_TowerButton = al_create_bitmap (m_ButtonSize, m_ButtonSize);
  al_set_target_bitmap (m_TowerButton);
  al_clear_to_color (al_map_rgb(0,255,0));
}


void ScoreBoard::draw() const
{
  drawTopLine();
  drawTowerButton();
  drawInfoText();
}

void ScoreBoard::drawTopLine() const
{
  al_draw_line (0, 640, m_Size_x,  640, al_map_rgb(127, 127, 127), 2);
}

void ScoreBoard::drawTowerButton() const
{
  al_draw_bitmap (m_TowerButton, m_Size_x - (m_ButtonSize * 2), m_Size_y + 640 - (m_ButtonSize + (m_ButtonSize / 2)), 0);
}

void ScoreBoard::drawInfoText() const
{
  //todo
}
