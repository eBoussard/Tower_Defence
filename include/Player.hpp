//! Spelaren, placerar torn på Board

#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
public:
      Player();

      unsigned int getMoney() const;
      void setMoney(unsigned int Money);

      unsigned int getHealthPoints() const;
      void setHealthPoints(unsigned int healthPoints);

      unsigned int getScore() const;
      void setScore(unsigned int Score);


private:
      Player(const Player&);
      Player & operator = (const Player&);

      //! Player får sina pengar genom att skjuta ner Enemy med hjälp av Tower
      unsigned int Money_;

      //! För varje Enemy som når @ref Board::exitTile_ "utgången" minskar Players HP med ett
      unsigned int healthPoints_;

      //! För varje fiende som dör ökar Players poäng
      unsigned int Score_;
};

#endif //PLAYER_HPP
