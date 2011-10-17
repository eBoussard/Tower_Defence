#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <allegro.h>

class ScoreBoard
{
public: 
  ScoreBoard();
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
  ALLEGRO_BITMAP *m_TowerButton;
};


#endif //SCOREBOARD_HPP
