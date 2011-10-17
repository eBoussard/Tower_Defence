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


private:
  ScoreBoard(const ScoreBoard&);
  ScoreBoard & operator = (const ScoreBoard&);

  void drawTopLine() const;
  void drawTowerButton() const;
  void drawInfoText() const;


  //Properties
  const unsigned int m_ButtonSize;
  const unsigned int m_Size_x;
  const unsigned int m_Size_y;
  const int m_Position_x;
  const int m_Position_y;
  ALLEGRO_BITMAP *m_TowerButton;
  ALLEGRO_COLOR m_ColorGray;
  ALLEGRO_COLOR m_ColorWhite;

  ALLEGRO_FONT *m_InfoFont;
};


#endif //SCOREBOARD_HPP
