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
  void Draw();  


  const unsigned int menuDisplayWidth;

  const unsigned int menuDisplayHeight;

  const unsigned int displayWidth;

  const unsigned int displayHeight;

  const unsigned int boardHeight;

private:
  UI(const UI&);
  UI & operator = (const UI&);
};



#endif //UI_HPP

