//! Bar at the bottom of the screen

//! The ScoreBoard bar is used to inform Player about Player's health,
//! money and score. The bar also includes button selectors for
//! placing Tower on Board. The bar is 1280 by 80 pixels.

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>


class ScoreBoard
{
public: 
  ScoreBoard();
  ~ScoreBoard();

  //! Draw visual elements on ScoreBoard
  void Draw() const;

  //! Check if Tower button has been pressed
  //! @param x check if mouse is clicked on button's x-axis
  //! @param y check if mouse is clicked on button's y-axis
  void buttonClicked(unsigned int x, unsigned int y);

  //! Check if button has been clicked
  //! @returns true if mouse has been clicked on buttons position
  bool towerButtonActive() const;



private:
  ScoreBoard(const ScoreBoard&);
  ScoreBoard & operator = (const ScoreBoard&);

  void drawTowerButton() const;

  //! Draws text on screen

  //! This method will draw the text "SCORE", "LIFE" and "MONEY" on
  //! the left side of ScoreBoard.
  void drawInfoText() const;

  //! TODO
  char * infoText_;
  char * getScoreInfoText() const;
  char * getHealthPointsInfoText() const;
  char * getMoneyInfoText() const;



  //Properties
  const unsigned int buttonSize_;
  const unsigned int screenWidth_;
  const unsigned int screenHeight_;

  //! The y-axis position of the top border of ScoreBoard

  //! This variable is called topLinePosition because the screen pixel
  //! count starts at the top, thus giving the variable the value 640
  //! instead of 80.
  const int topLinePosition_;
  const unsigned int Score_;
  const unsigned int healthPoints_;
  const unsigned int Money_;
  bool towerButtonActive_;

  //! The image representing the clickable button
  ALLEGRO_BITMAP *towerButton_;

  //! TODO
  ALLEGRO_FONT *infoFont_;


  ALLEGRO_COLOR colorWhite_;
  ALLEGRO_COLOR colorRed_;

};



#endif //SCOREBOARD_HPP
