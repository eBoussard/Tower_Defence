//! Place Tower on Board

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

  //! Killing Enemy will earn Player more money. The amount of money
  //! is decided by Enemy's @ref yieldsMoney_ "value".
  unsigned int Money_;

  //! Player's health points, which decreases when Enemy reaches @ref
  //! exitTile_ "exit"
  unsigned int healthPoints_;

  //! Player's score increases for every killed Enemy
  unsigned int Score_;
};



#endif //PLAYER_HPP
