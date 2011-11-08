#include <Player.hpp>
#include <iostream>



Player::Player():Money_(100), healthPoints_(20), Score_(0)
{ }


unsigned int Player::getMoney() const
{
  return Money_;
}


void Player::setMoney (unsigned int setterMoney)
{
  Money_ = setterMoney;
}



unsigned int Player::getHealthPoints() const
{
  return healthPoints_;
}

void Player::setHealthPoints(unsigned int healthPoints)
{
  healthPoints_ = healthPoints;
}



unsigned int Player::getScore() const 
{
  return Score_;
}

void Player::setScore(unsigned int Score)
{
  Score = Score_;
}
