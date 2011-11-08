#include <ScoreBoard.hpp>
#include <UI.hpp>

#include <stdio.h>
#include <iostream>

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <allegro_image.h>





ScoreBoard::ScoreBoard(Player& aPlayer):player(aPlayer), buttonSize_(32), towerButtonActive_(false)
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

  scoreBoardWidth_ = ui.displayWidth;
  scoreBoardHeight_ = (ui.displayHeight - ui.boardHeight); // 720 - 640 = 80                                                            


  topLinePosition_ = ui.boardHeight;


  Money_ = player.getMoney();
  healthPoints_ = player.getHealthPoints();
  Score_ = player.getScore();
}



ScoreBoard::~ScoreBoard()
{
  delete(infoText_);
}



void ScoreBoard::updateTextInfo()
{
  Money_ = player.getMoney();
  healthPoints_ = player.getHealthPoints();
  Score_ = player.getScore();
}



void ScoreBoard::Draw()
{
  updateTextInfo();
  drawTowerButton();
  drawInfoText();
}




void ScoreBoard::ButtonClicked(unsigned int x, unsigned int y)
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


