#ifndef AMMUNITION_HPP
#define AMMUNITION_HPP



class Ammunition
{
public:
  Ammunition();



private:
  Ammunition(const Ammunition&);
  Ammunition & operator = (const Ammunition&);



  // Properties
  // !Location of ammunition on board

  // !Ammunition's location is a pixel location rather than a tile location.
  unsigned int Location_;
};


#endif //AMMUNITION_HPP
