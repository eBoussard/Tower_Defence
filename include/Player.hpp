//! Place Tower on Board

//! Player may place and remove Tower.

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



  //Properties

  //! Purchasing Tower requires Player to have Money, obtainable by
  //! killing Enemy
  unsigned int Money_;

  //! Player's health points will decrease for every Enemy that
  //! reaches @ref exitTile_ "exit".
  unsigned int healthPoints_;

  //! Score is earned by killing Enemy
  unsigned int Score_;
};



#endif //PLAYER_HPP
