#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>


///class test
class ScoreBoard
{
public: 
  ///test

  ///more test
  ScoreBoard();
  ~ScoreBoard();
  void draw() const;
  void mouseClick(unsigned int x, unsigned int y);
  bool towerButtonActive() const;



private:
  ScoreBoard(const ScoreBoard&);
  ScoreBoard & operator = (const ScoreBoard&);

  void drawTowerButton() const;
  void drawInfoText() const;

  char * m_infoText;
  char * getScoreInfoText() const;
  char * getHealthPointsInfoText() const;
  char * getMoneyInfoText() const;



  //Properties
  const unsigned int m_buttonSize;
  const unsigned int m_max_x;
  const unsigned int m_min_x;
  const unsigned int m_max_y;
  const unsigned int m_min_y;
  const int m_topLinePosition;
  const unsigned int m_Score;
  const unsigned int m_healthPoints;
  const unsigned int m_Money;
  bool m_towerButtonActive;

  ALLEGRO_BITMAP *m_towerButton;
  ALLEGRO_FONT *m_infoFont;

  ALLEGRO_COLOR m_colorWhite;
  ALLEGRO_COLOR m_colorRed;

};



#endif //SCOREBOARD_HPP
