#ifndef AMMUNITION_HPP
#define AMMUNITION_HPP

class Ammunition
{
public:
  Ammunition();
  void debugPrint() const;

private:
  Ammunition(const Ammunition&);
  Ammunition & operator = (const Ammunition&);

  //Properties
  unsigned int m_Location;
};


#endif //AMMUNITION_HPP
