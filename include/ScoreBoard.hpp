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
  void draw() const;
  void MouseClick(unsigned int x, unsigned int y);


private:
  ScoreBoard(const ScoreBoard&);
  ScoreBoard & operator = (const ScoreBoard&);

  void drawTopLine() const;
  void drawTowerButton() const;
  void drawInfoText() const;

  char * m_InfoText;
  char * GetScoreInfoText() const;
  char * GetHealthPointsInfoText() const;
  char * GetMoneyInfoText() const;


  //Properties
  const unsigned int m_ButtonSize;
  const unsigned int m_Size_x;
  const unsigned int m_Size_y;
  const int m_Position_x;
  const int m_Position_y;
  const unsigned int m_Score;
  const unsigned int m_HealthPoints;
  const unsigned int m_Money;

  ALLEGRO_BITMAP *m_TowerButton;
  ALLEGRO_COLOR m_ColorGray;
  ALLEGRO_COLOR m_ColorWhite;

  ALLEGRO_FONT *m_InfoFont;
};


#endif //SCOREBOARD_HPP
