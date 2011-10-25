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

  unsigned int menuDisplayWidth;
  unsigned int menuDisplayHeight;

  unsigned int highResolutionWidth;
  unsigned int highResolutionHeight;

  unsigned int lowResolutionWidth;
  unsigned int lowResolutionHeight;

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

