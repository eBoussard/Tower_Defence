#include <ScoreBoard.hpp>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>



ScoreBoard::ScoreBoard():m_ButtonSize(40), m_Size_x(1280), m_Size_y(80), m_Position_x(0), m_Position_y(640)
{
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();

  m_TowerButton = al_create_bitmap (m_ButtonSize, m_ButtonSize);
  al_set_target_bitmap (m_TowerButton);
  al_clear_to_color (al_map_rgb(0,255,0));

  m_ColorGray = al_map_rgb (127, 127, 127);
  m_ColorWhite = al_map_rgb (255, 255, 255);

  m_InfoFont =  al_load_ttf_font ("pirulen.ttf", 18, 0);
}


ScoreBoard::~ScoreBoard()
{
  al_destroy_font (m_InfoFont); 
  al_shutdown_ttf_addon();
}


void ScoreBoard::draw() const
{
  drawTopLine();
  drawTowerButton();
  drawInfoText();
}

void ScoreBoard::drawTopLine() const
{
  al_draw_line (m_Position_x, m_Position_y, m_Position_x + m_Size_x,  m_Position_y, m_ColorGray, 2);
}

void ScoreBoard::drawTowerButton() const
{
  al_draw_bitmap (m_TowerButton, m_Size_x - (m_ButtonSize * 2), m_Size_y + 640 - (m_ButtonSize + (m_ButtonSize / 2)), 0);
}

void ScoreBoard::drawInfoText() const
{


  if (m_InfoFont != NULL)
    {
      al_draw_text (m_InfoFont, m_ColorWhite, 10, m_Position_y, ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (m_InfoFont, m_ColorWhite, 10, (m_Position_y + 25), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (m_InfoFont, m_ColorWhite, 10, (m_Position_y + 50), ALLEGRO_ALIGN_LEFT, "MONEY");
    }
}
