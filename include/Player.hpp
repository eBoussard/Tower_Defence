//! Player places Tower on Board

//! Player may place and remove Tower.

#ifndef PLAYER_HPP
#define PLAYER_HPP



class Player
{
public:
  Player();



private:
  Player(const Player&);
  Player & operator = (const Player&);



  //Properties

  //! Player's money

  //! Killing Enemy will earn Player more money.
  unsigned int Money_;

  //! Player's health points, which decreases when Enemy reaches exit.
  unsigned int healthPoints_;
};



#endif //PLAYER_HPP
