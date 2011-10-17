#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player
{
public:
  Player();
  void debugPrint() const;

private:
  Player(const Player&);
  Player & operator = (const Player&);

  //Properties
  unsigned int m_Money;
  unsigned int m_HealthPoints;
};

#endif //PLAYER_HPP
