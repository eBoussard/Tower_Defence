//! Bar at the bottom of the screen

//! Includes information about Player's @ref Player::Money_ "money",
//! @ref Player::healthPoints_ "health points" and @ref Player::Score_
//! "score". It also includes a clickable @ref towerButton_ "button".

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <Player.hpp>

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>


class ScoreBoard
{
public: 
  ScoreBoard(Player&);
  ~ScoreBoard();

  void Draw();

  //! Check if the @ref towerButton_ "button" has been pressed
  //! @param x check if mouse is clicked on the @ref towerButton_ "button's" x-axis
  //! @param y check if mouse is clicked on the @ref towerButton_ "button's" y-axis
  void ButtonClicked(unsigned int x, unsigned int y);


  //! Check if @ref towerButton_ "button" has been clicked
  //! @returns true if mouse has been clicked on @ref towerButton_ "button's" position
  bool towerButtonActive() const;



private:
  ScoreBoard(const ScoreBoard&);
  ScoreBoard & operator = (const ScoreBoard&);

  void updateTextInfo();

  void drawTowerButton() const;

  //! Draws text on screen

  //! Draw the text "SCORE", "LIFE" and "MONEY" on
  //! the left side of ScoreBoard.
  void drawInfoText() const;

  //! Buffer for formatting text (score, health points and money)
  char * infoText_;

  char * getScoreInfoText() const;
  char * getHealthPointsInfoText() const;
  char * getMoneyInfoText() const;


  Player &player;


  //Properties

  //! Pixel size of the (square) button on ScoreBoard
  const unsigned int buttonSize_;

  unsigned int scoreBoardWidth_;
  unsigned int scoreBoardHeight_;


  //! The y-axis position of the top border of ScoreBoard

  //! The pixel position on the y-axis of the lowest line drawn on
  //! Board's grid. This line acts as a border.
  unsigned int topLinePosition_;

  unsigned int Score_;
  unsigned int healthPoints_;
  unsigned int Money_;

  //! @return true if @ref towerButton_ "tower button" has been
  //! clicked once
  bool towerButtonActive_;

  //! The image representing the clickable button
  ALLEGRO_BITMAP *towerButton_;

  ALLEGRO_FONT *infoFont_;

  ALLEGRO_COLOR colorWhite_;
  ALLEGRO_COLOR colorRed_;

};



#endif //SCOREBOARD_HPP
