#ifndef UI_HPP
#define UI_HPP

#include <allegro.h>
#include <allegro_primitives.h>
#include <allegro_font.h>
#include <allegro_ttf.h>


class UI
{
public:
  UI();

  char getDisplayMode();
  void desktopProperties(int &width, int &height);
  void laptopProperties(int &width, int &height);


private:
  UI(const UI&);
  UI & operator = (const UI&);

};



#endif //UI_HPP

//TODO More resolution options
//TODO Buttons (images) for selecting mode and resolution
