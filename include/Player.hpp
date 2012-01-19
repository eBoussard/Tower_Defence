//! Spelaren, placerar Tower på Board

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

      unsigned int Money_;
      unsigned int healthPoints_;
      unsigned int Score_;
};

#endif //PLAYER_HPP
