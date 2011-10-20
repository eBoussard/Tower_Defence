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
  unsigned int m_Money;
  unsigned int m_healthPoints;
};



#endif //PLAYER_HPP
