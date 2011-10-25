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

  unsigned int menuWidth;
  unsigned int menuHeight;

  unsigned int highResWidth;
  unsigned int highResHeight;

  unsigned int lowResWidth;
  unsigned int lowResHeight;

private:
  UI(const UI&);
  UI & operator = (const UI&);

  void drawResolutionTexts();
  void drawResolutionSelector();

  ALLEGRO_FONT *resolutionText_;
  ALLEGRO_COLOR Unselected_;
  ALLEGRO_COLOR Selected_;
};



#endif //UI_HPP

