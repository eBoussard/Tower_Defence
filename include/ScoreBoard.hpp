//! Rutan längst ner på skärmen

//! Visar information såsom @ref Player::healthPoints_ "Players HP", @ref Player::Money_ "Players
//! pengar" och @ref Player::Score_ "Players poäng"

#ifndef SCOREBOARD_HPP
#define SCOREBOARD_HPP

#include <Player.hpp>
#include <allegro.h>
#include <allegro_font.h>
#include <allegro_ttf.h>
#include <definitions.hpp>

class ScoreBoard
{
public: 
      ScoreBoard(Player&);
      ~ScoreBoard();

      void Draw();

      //! Gör saker och ting om en musknapp har klickats på knappen
      void ButtonClicked(pixelPosition x, pixelPosition y);

      //! Kollar om knappen har klickats
      //! @return true om en musknapp har klickats på knappen
      bool towerButtonActive() const;

private:
      ScoreBoard(const ScoreBoard&);
      ScoreBoard & operator = (const ScoreBoard&);

      //! Metod för att uppdatera infotexten i realtid
      void updateTextInfo();
      void drawTowerButton() const;
      void drawInfoText() const;

      //! Buffer för att formatera texten
      char * infoText_;

      char * getScoreInfoText() const;
      char * getHealthPointsInfoText() const;
      char * getMoneyInfoText() const;

      Player &player;

      const unsigned int buttonSize_;
      const unsigned int scoreBoardWidth_;
      const unsigned int scoreBoardHeight_;

      //! Pixelposition på Y-axeln av gränsen mellan ScoreBoard och Board
      unsigned int topLinePosition_;
      
      unsigned int Score_;
      unsigned int healthPoints_;
      unsigned int Money_;

      bool towerButtonActive_;

      ALLEGRO_BITMAP *towerButton_;
      ALLEGRO_FONT *infoFont_;
      ALLEGRO_COLOR colorWhite_;
      ALLEGRO_COLOR colorRed_;
};

#endif //SCOREBOARD_HPP
