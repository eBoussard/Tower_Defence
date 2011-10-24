#include <ScoreBoard.hpp>

#include <stdio.h>
#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <allegro_image.h>





ScoreBoard::ScoreBoard():buttonSize_(32), scoreBoardWidth_(1280), scoreBoardHeight_(80), topLinePosition_(640), Score_(100), healthPoints_(100), Money_(100), towerButtonActive_(false)
{
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();

  colorWhite_ = al_map_rgb (255, 255, 255);
  colorRed_ = al_map_rgb (255, 0, 0);


  towerButton_ = al_load_bitmap ("gfx/T1test.bmp");


  infoFont_ =  al_load_ttf_font ("pirulen.ttf", 18, 0);
  //EXPERIMENTAL
  infoText_ = new char [128];
}



ScoreBoard::~ScoreBoard()
{
  al_destroy_font (infoFont_); 
  al_shutdown_ttf_addon();
  delete(infoText_);
}



void ScoreBoard::Draw() const
{
  drawTowerButton();
  drawInfoText();
}



void ScoreBoard::buttonClicked(unsigned int x, unsigned int y)
{
  if (y > topLinePosition_ + (buttonSize_ / 2) && y < topLinePosition_ + (buttonSize_ * 1.5))
    {
      if (x > scoreBoardWidth_ - (buttonSize_ * 2) && x < scoreBoardWidth_ - buttonSize_)
	{
	  std::cout << "button clicked\n";
	  towerButtonActive_ = !towerButtonActive_;
	}
    }
}



bool ScoreBoard::towerButtonActive() const
{
  return towerButtonActive_;
}



void ScoreBoard::drawTowerButton() const
{
  al_draw_bitmap (towerButton_, scoreBoardWidth_ - (buttonSize_ * 2), topLinePosition_ + (buttonSize_ / 2), 0);
  if (towerButtonActive_)


    {
      al_draw_rectangle ((scoreBoardWidth_ - 2) - (buttonSize_ * 2), (topLinePosition_ - 2) + (buttonSize_ / 2), (scoreBoardWidth_ + 2) - buttonSize_, (topLinePosition_ + 2) + (buttonSize_ * 1.5), colorRed_, 2);
    }
}



void ScoreBoard::drawInfoText() const
{
  if (infoFont_ != NULL)
    {
      al_draw_text (infoFont_, colorWhite_, 10, (topLinePosition_ + 2), ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (infoFont_, colorWhite_, 10, (topLinePosition_ + ((scoreBoardHeight_ - 20) / 2)), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (infoFont_, colorWhite_, 10, (topLinePosition_ + (scoreBoardHeight_ - 20)), ALLEGRO_ALIGN_LEFT, "MONEY");


      al_draw_text (infoFont_, colorWhite_, 180, (topLinePosition_ + 2), ALLEGRO_ALIGN_RIGHT, getScoreInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (topLinePosition_ + ((scoreBoardHeight_ - 20) / 2)), ALLEGRO_ALIGN_RIGHT, getHealthPointsInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (topLinePosition_ + (scoreBoardHeight_ - 20)), ALLEGRO_ALIGN_RIGHT, getMoneyInfoText());
    }
}


char * ScoreBoard::getScoreInfoText() const
{
  sprintf (infoText_, "%d", Score_);
  return infoText_;
}


char * ScoreBoard::getHealthPointsInfoText() const
{
  sprintf (infoText_, "%d", healthPoints_);
  return infoText_;
}


char * ScoreBoard::getMoneyInfoText() const
{
  sprintf (infoText_, "%d", Money_);
  return infoText_;
}


