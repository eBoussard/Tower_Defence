#include <ScoreBoard.hpp>

#include <stdio.h>
#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <allegro_image.h>





ScoreBoard::ScoreBoard():m_buttonSize(32), m_max_x(1280), m_min_x(0), m_max_y(80), m_min_y(0), m_topLinePosition(640), m_Score(100), m_healthPoints(100), m_Money(100), m_towerButtonActive(false)
{
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();

  m_colorWhite = al_map_rgb (255, 255, 255);
  m_colorRed = al_map_rgb (255, 0, 0);



  m_towerButton = al_load_bitmap ("gfx/T1.bmp");


  m_infoFont =  al_load_ttf_font ("pirulen.ttf", 18, 0);
  m_infoText = (char *)malloc(128);
}



ScoreBoard::~ScoreBoard()
{
  al_destroy_font (m_infoFont); 
  al_shutdown_ttf_addon();
  free(m_infoText);
}



void ScoreBoard::draw() const
{
  drawTowerButton();
  drawInfoText();
}



void ScoreBoard::mouseClick(unsigned int x, unsigned int y)
{
  if (y > m_topLinePosition + (m_buttonSize / 2) && y < m_topLinePosition + (m_buttonSize * 1.5))
    {
      if (x > m_max_x - (m_buttonSize * 2) && x < m_max_x - m_buttonSize)
	{
	  std::cout << "button clicked\n";
	  m_towerButtonActive = !m_towerButtonActive;
	}
    }
}



bool ScoreBoard::towerButtonActive() const
{
  return m_towerButtonActive;
}



void ScoreBoard::drawTowerButton() const
{
  al_draw_bitmap (m_towerButton, m_max_x - (m_buttonSize * 2), m_topLinePosition + (m_buttonSize / 2), 0);
  if (m_towerButtonActive)


    {
      al_draw_rectangle ((m_max_x - 2) - (m_buttonSize * 2), (m_topLinePosition - 2) + (m_buttonSize / 2), (m_max_x + 2) - m_buttonSize, (m_topLinePosition + 2) + (m_buttonSize * 1.5), m_colorRed, 2);
    }
}



void ScoreBoard::drawInfoText() const
{
  if (m_infoFont != NULL)
    {
      al_draw_text (m_infoFont, m_colorWhite, (m_min_x + 10), (m_topLinePosition + 2), ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (m_infoFont, m_colorWhite, (m_min_x + 10), (m_topLinePosition + ((m_max_y - 20) / 2)), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (m_infoFont, m_colorWhite, (m_min_x + 10), (m_topLinePosition + (m_max_y - 20)), ALLEGRO_ALIGN_LEFT, "MONEY");


      al_draw_text (m_infoFont, m_colorWhite, 180, (m_topLinePosition + 2), ALLEGRO_ALIGN_RIGHT, getScoreInfoText());
      al_draw_text (m_infoFont, m_colorWhite, 180, (m_topLinePosition + ((m_max_y - 20) / 2)), ALLEGRO_ALIGN_RIGHT, getHealthPointsInfoText());
      al_draw_text (m_infoFont, m_colorWhite, 180, (m_topLinePosition + (m_max_y - 20)), ALLEGRO_ALIGN_RIGHT, getMoneyInfoText());
    }
}


char * ScoreBoard::getScoreInfoText() const
{
  sprintf (m_infoText, "%d", m_Score);
  return m_infoText;
}


char * ScoreBoard::getHealthPointsInfoText() const
{
  sprintf (m_infoText, "%d", m_healthPoints);
  return m_infoText;
}


char * ScoreBoard::getMoneyInfoText() const
{
  sprintf (m_infoText, "%d", m_Money);
  return m_infoText;
}


