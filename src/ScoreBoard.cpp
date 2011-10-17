#include <ScoreBoard.hpp>

#include <stdio.h>
#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>



ScoreBoard::ScoreBoard():m_ButtonSize(40), m_Size_x(1280), m_Size_y(80), m_Position_x(0), m_Position_y(640), m_Money(100), m_Score(100), m_HealthPoints(100), m_TowerButtonActive(false)
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
  m_ColorRed = al_map_rgb (255, 0, 0);

  m_InfoFont =  al_load_ttf_font ("pirulen.ttf", 18, 0);

  m_InfoText = (char *)malloc(128);
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

void ScoreBoard::MouseClick(unsigned int x, unsigned int y)
{
  if (y > m_Position_y + (m_ButtonSize / 2) && y < m_Position_y + (m_ButtonSize * 1.5))
    {
      if (x > m_Size_x - (m_ButtonSize * 2) && x < m_Size_x - m_ButtonSize)
	{
	  std::cout << "button clicked\n";
	  m_TowerButtonActive = !m_TowerButtonActive;
	}
    }
}


bool ScoreBoard::TowerButtonActive() const
{
  return m_TowerButtonActive;
}



void ScoreBoard::drawTopLine() const
{
  al_draw_line (m_Position_x, m_Position_y, m_Position_x + m_Size_x,  m_Position_y, m_ColorGray, 2);
}

void ScoreBoard::drawTowerButton() const
{
  al_draw_bitmap (m_TowerButton, m_Size_x - (m_ButtonSize * 2), m_Size_y + 640 - (m_ButtonSize + (m_ButtonSize / 2)), 0);
  if (m_TowerButtonActive)
    {
      al_draw_rectangle (1198, 658, 1242, 702, m_ColorRed, 2);
    }
}

void ScoreBoard::drawInfoText() const
{
  if (m_InfoFont != NULL)
    {
      al_draw_text (m_InfoFont, m_ColorWhite, 10, (m_Position_y + 2), ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (m_InfoFont, m_ColorWhite, 10, (m_Position_y + ((m_Size_y - 20) / 2)), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (m_InfoFont, m_ColorWhite, 10, (m_Position_y + (m_Size_y - 20)), ALLEGRO_ALIGN_LEFT, "MONEY");

      al_draw_text (m_InfoFont, m_ColorWhite, 180, (m_Position_y + 2), ALLEGRO_ALIGN_RIGHT, GetScoreInfoText());
      al_draw_text (m_InfoFont, m_ColorWhite, 180, (m_Position_y + ((m_Size_y - 20) / 2)), ALLEGRO_ALIGN_RIGHT, GetHealthPointsInfoText());
      al_draw_text (m_InfoFont, m_ColorWhite, 180, (m_Position_y + (m_Size_y - 20)), ALLEGRO_ALIGN_RIGHT, GetMoneyInfoText());
    }
}


char * ScoreBoard::GetScoreInfoText() const
{
  sprintf (m_InfoText, "%d", m_Score);
  return m_InfoText;
}

char * ScoreBoard::GetHealthPointsInfoText() const
{
  sprintf (m_InfoText, "%d", m_HealthPoints);
  return m_InfoText;
}

char * ScoreBoard::GetMoneyInfoText() const
{
  sprintf (m_InfoText, "%d", m_Money);
  return m_InfoText;
}


