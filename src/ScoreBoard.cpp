#include <ScoreBoard.hpp>
#include <UI.hpp>

#include <stdio.h>
#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <allegro_image.h>





ScoreBoard::ScoreBoard():buttonSize_(32), Score_(100), healthPoints_(100), Money_(100), towerButtonActive_(false)
{
  al_init();
  al_init_primitives_addon();
  al_init_font_addon();
  al_init_ttf_addon();
  al_init_image_addon();

  colorWhite_ = al_map_rgb (255, 255, 255);
  colorRed_ = al_map_rgb (255, 0, 0);


  towerButton_ = al_load_bitmap ("gfx/towerbutton.bmp");


  infoFont_ =  al_load_ttf_font ("pirulen.ttf", 18, 0);
  infoText_ = new char [128];

  UI ui;

  scoreBoardLowResWidth_ = ui.lowResWidth;
  scoreBoardLowResHeight_ = (ui.lowResDisplayHeight - ui.lowResBoardHeight);

  scoreBoardHighResWidth_ = ui.highResWidth;
  scoreBoardHighResHeight_ = (ui.highResDisplayHeight - ui.highResBoardHeight);

  lowResTopLinePosition_ = ui.lowResBoardHeight;
  highResTopLinePosition_ = ui.highResBoardHeight;
}



ScoreBoard::~ScoreBoard()
{
  al_destroy_font (infoFont_); 
  al_shutdown_ttf_addon();
  delete(infoText_);
}



void ScoreBoard::lowResDraw() const
{
  drawLowResTowerButton();
  drawLowResInfoText();
}


void ScoreBoard::highResDraw() const
{
  drawHighResTowerButton();
  drawHighResInfoText();
  
}




void ScoreBoard::lowResButtonClicked(unsigned int x, unsigned int y)
{
  if (y > lowResTopLinePosition_ + (buttonSize_ / 2) && y < lowResTopLinePosition_ + (buttonSize_ * 1.5))
    {
      if (x > scoreBoardLowResWidth_ - (buttonSize_ * 2) && x < scoreBoardLowResWidth_ - buttonSize_)
	{
	  std::cout << "low res button clicked\n";
	  towerButtonActive_ = !towerButtonActive_;
	}
    }
}


void ScoreBoard::highResButtonClicked(unsigned int x, unsigned int y)
{
  if (y > highResTopLinePosition_ + (buttonSize_ / 2) && y < lowResTopLinePosition_ + (buttonSize_ * 1.5))
    {
      if (x > scoreBoardHighResWidth_ - (buttonSize_ * 2) && x < scoreBoardHighResWidth_ - buttonSize_)
	{
	  std::cout << "high res button clicked\n";
	  towerButtonActive_ = !towerButtonActive_;
	}
    }
}


bool ScoreBoard::towerButtonActive() const
{
  return towerButtonActive_;
}



void ScoreBoard::drawLowResTowerButton() const
{
  al_draw_bitmap (towerButton_, scoreBoardLowResWidth_ - (buttonSize_ * 2), lowResTopLinePosition_ + (buttonSize_ / 2), 0);

  if (towerButtonActive_)
    {
      al_draw_rectangle ((scoreBoardLowResWidth_ - 2) - (buttonSize_ * 2), (lowResTopLinePosition_ - 2) + (buttonSize_ / 2), (scoreBoardLowResWidth_ + 2) - buttonSize_, (lowResTopLinePosition_ + 2) + (buttonSize_ * 1.5), colorRed_, 2);
    }
}



void ScoreBoard::drawHighResTowerButton() const
{
  al_draw_bitmap (towerButton_, scoreBoardHighResWidth_ - (buttonSize_ * 2), highResTopLinePosition_ + (buttonSize_ / 2), 0);

  if (towerButtonActive_)
    {
      al_draw_rectangle ((scoreBoardHighResWidth_ - 2) - (buttonSize_ * 2), (highResTopLinePosition_ - 2) + (buttonSize_ / 2), (scoreBoardHighResWidth_ + 2) - buttonSize_, (highResTopLinePosition_ + 2) + (buttonSize_ * 1.5), colorRed_, 2);
    }
}


  



void ScoreBoard::drawLowResInfoText() const
{
  if (infoFont_ != NULL)
    {
      al_draw_text (infoFont_, colorWhite_, 10, (lowResTopLinePosition_ + 2), ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (infoFont_, colorWhite_, 10, (lowResTopLinePosition_ + ((scoreBoardLowResHeight_ - 20) / 2)), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (infoFont_, colorWhite_, 10, (lowResTopLinePosition_ + (scoreBoardLowResHeight_ - 20)), ALLEGRO_ALIGN_LEFT, "MONEY");


      al_draw_text (infoFont_, colorWhite_, 180, (lowResTopLinePosition_ + 2), ALLEGRO_ALIGN_RIGHT, getScoreInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (lowResTopLinePosition_ + ((scoreBoardLowResHeight_ - 20) / 2)), ALLEGRO_ALIGN_RIGHT, getHealthPointsInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (lowResTopLinePosition_ + (scoreBoardLowResHeight_ - 20)), ALLEGRO_ALIGN_RIGHT, getMoneyInfoText());
    }
}



void ScoreBoard::drawHighResInfoText() const
{
  if (infoFont_ != NULL)
    {
      al_draw_text (infoFont_, colorWhite_, 10, (highResTopLinePosition_ + 2), ALLEGRO_ALIGN_LEFT, "SCORE");
      al_draw_text (infoFont_, colorWhite_, 10, (highResTopLinePosition_ + ((scoreBoardHighResHeight_ - 20) / 2)), ALLEGRO_ALIGN_LEFT, "LIFE");
      al_draw_text (infoFont_, colorWhite_, 10, (highResTopLinePosition_ + (scoreBoardHighResHeight_ - 20)), ALLEGRO_ALIGN_LEFT, "MONEY");


      al_draw_text (infoFont_, colorWhite_, 180, (highResTopLinePosition_ + 2), ALLEGRO_ALIGN_RIGHT, getScoreInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (highResTopLinePosition_ + ((scoreBoardHighResHeight_ - 20) / 2)), ALLEGRO_ALIGN_RIGHT, getHealthPointsInfoText());
      al_draw_text (infoFont_, colorWhite_, 180, (highResTopLinePosition_ + (scoreBoardHighResHeight_ - 20)), ALLEGRO_ALIGN_RIGHT, getMoneyInfoText());
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


